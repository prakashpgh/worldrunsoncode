'''
https://leetcode.com/problems/design-add-and-search-words-data-structure/

add_word:
    add as a tri.
        each word is the key of a dictionary.

search:
    iterate the letters and search if letter matches the dicionary ... if does not match, then False


'''


WOD_END="$"


class WordDictionary:

    def __init__(self):
        self.trie = {}        

    def addWord(self, word: str) -> None:
        node = self.trie
        for ch in word:
            if ch not in node:
                node[ch] = {}
            node = node[ch]
        node[WOD_END] = True

    def search(self, word: str) -> bool:
        def search_in(word, node):
            for i, ch in enumerate(word):
                if ch not in node:
                    if ch == ".":
                        for x in node:
                            if (x != "$" and search_in(word[i+1 :], node[x])):
                                return True
                    return False
                node = node[ch]
            return WOD_END in node
        return search_in(word, self.trie)        
    

wordDictionary = WordDictionary()
wordDictionary.addWord("bad")
wordDictionary.addWord("dad");
wordDictionary.addWord("mad")
result = wordDictionary.search("pad")
print("result: " + str(result))

result = wordDictionary.search("bad")
print("result: " + str(result))

result = wordDictionary.search(".ad")
if not result:
    raise Exception("failure")

result = wordDictionary.search("b..")
if not result:
    raise Exception("failure")

