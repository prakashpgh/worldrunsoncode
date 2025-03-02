'''
https://leetcode.com/problems/word-ladder/

https://www.youtube.com/watch?v=EAcJgd4Xu5E
https://www.youtube.com/watch?v=h9iTnkgv05E&t=891s

here key is creation of the graph 
    1) create the patterns for each word.. where you replace each letter by *, hot => *ot, h*t, ho*
#create the graph...
1)  for each word in the word list, including the begin word, create a graph..
    replace 1 character each time with all possible a-z, and verify that the resulting word exists in the word_list
2)  once this graph is created, just do bfs, and find the number of hops required

#meta
'''

def possible_words_2(word_list_set):
    g = {}
    pattern_map={}
    for word in word_list_set:
        word_len = len(word)
        for i in range(word_len):
            pattern = word[:i] + "*" + word[i+1:]
            if pattern in pattern_map:
                pattern_map[pattern].append(word)
            else:
                pattern_map[pattern] = [word]
    #print("pattern-map: " + str(pattern_map))
    values = pattern_map.values()
    for value in values:
        for i in value:
            for j in value:
                if i == j:
                    continue
                if i not in g:
                    g[i] = [j]
                else:
                    g[i].append(j)
    return g


def possible_words(word_list_set):
    g = {}
    for word in word_list_set:
        words = []
        abc_str = "abcdefghijklmnopqrstuvwxyz"
        abc_len = len(abc_str)
        N = len (word)
        for i in range(N):
            for j in range(abc_len):
                word_formed = word[:i] + abc_str[j] + word[i+1:]
                #print(word_formed)
                if word_formed in word_list_set and word_formed != word:
                    words.append(word_formed)
        g[word] = words
    return g


from collections import deque
from collections import defaultdict



def word_ladder(begin_word:str, end_word:str, word_list: list[str]) -> int:
    #do this while the result is met, or there are no words in the wordlist
    result = 0
    word_list.append(begin_word)
    word_list_set = set(word_list)
    #g = possible_words(word_list_set)
    g = possible_words_2(word_list_set)
    
    print("g=" + str(g))
    q = deque()
    q.append((begin_word, 1))
    visited = set()
    while q:
        (word, f) = q.popleft()
        if word in visited:
            continue
        
        if word == end_word:
            result = f
            break
        if word in g:
            for nei in g[word]:
                q.append((nei, f+1))
        visited.add(word)
    return result


beginWord = "hot"
endWord = "dog"
wordList=["hot","dog"]
result = word_ladder(beginWord, endWord, wordList)
print("result: " + str(result))
#exit(0)


beginWord = "leet"
endWord = "code"
wordList=["lest","leet","lose","code","lode","robe","lost"]
result = word_ladder(beginWord, endWord, wordList)
print("result: " + str(result))
#exit(0)

beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
result = word_ladder(beginWord, endWord, wordList)
print("result: " + str(result))


beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
#Output: 0
result = word_ladder(beginWord, endWord, wordList)
print("result: " + str(result))
