'''
https://leetcode.com/problems/top-k-frequent-words/description/

1) find the frequency of each word using dict.
2) iterate the dict, and heap push  pop if > k .... custom sort using __lt__ on frequency or (fre == same and word > ) ... WordFrequency class
3) so we are left with k sorted by min. freq.
4) sort the array in reverse order

#meta
'''

class WordFrequency:
    def __init__(self, word:str, frequency:int):
        self.word = word
        self.frequency = frequency

    def __str__(self):
        return f"{self.word}"

    def __repr__(self):
        return f"{self.word}"

    def __lt__(self, other:"WordFrequency"):
        return self.frequency < other.frequency or (self.frequency == other.frequency and self.word > other.word )

import heapq
def top_k_frequent_words(words:list[str], k):
    freq = {}
    #put in the hash table
    for w in words:
        if w in freq:
            freq[w] += 1
        else:
            freq[w] = 1
    min_heap = []
    print(f"frequency: {str(freq)}")
    for key,value in freq.items():
        heapq.heappush(min_heap, WordFrequency(key, value))
        if len(min_heap) > k:
            heapq.heappop(min_heap)
    print("min_heap: " + str(min_heap))
    return [p.word for p in sorted(min_heap, reverse=True)]


words=["i","love","leetcode","i","love","coding"]
k = 3
#Output: ["i","love"]
result = top_k_frequent_words(words, k)
print("result: " + str(result))




words = ["i","love","leetcode","i","love","coding"]
k = 2
#Output: ["i","love"]
result = top_k_frequent_words(words, k)
print("result: " + str(result))

words = ["the","day","is","sunny","the","the","the","sunny","is","is"]
k = 4
#Output: ["the","is","sunny","day"]
result = top_k_frequent_words(words, k)
print("result: " + str(result))
