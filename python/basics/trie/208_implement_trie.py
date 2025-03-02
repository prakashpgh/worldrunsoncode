'''
#https://leetcode.com/problems/implement-trie-prefix-tree/description/


prefix tree
each character in a word is a dictionary.
"." to mark the end of the word

'''

class Trie:
    def __init__(self):
        self.trie = {}

    def insert(self, word:str) -> None:
        d = self.trie
        for c in word:
            if c not in d:
                d[c] = {}
            d = d[c]
        d["."] = "."

    def search(self, word:str) -> bool:
        d = self.trie
        for c in word:
            if c not in d:
                return False
            d = d[c]
        return "." in d

    def startsWith(self, prefix:str) -> bool:
        d = self.trie
        for c in prefix:
            if c not in d:
                return False
            d = d[c]
        return True



input = ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
trie = Trie()
trie.insert("apple")
ret = trie.search("apple")   # return True
print("apple: " + str(ret))
ret = trie.search("app")     # return False
print("app: " + str(ret))
ret = trie.startsWith("app") # return True
print("startsWith app: " + str(ret))
trie.insert("app")
ret = trie.search("app")     # return True
print("app: " + str(ret))
#[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

#[null, null, true, false, true, null, true]


