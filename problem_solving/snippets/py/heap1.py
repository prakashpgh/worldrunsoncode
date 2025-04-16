import heapq
data = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}, {'name': 'Charlie', 'age': 35}]
print("before sort:" + str(data))
#1) sorting using heap..
# Transform the list into a heap with the key as the first element of the tuple
heap = [(item['age'], item) for item in data]
heapq.heapify(heap)

sorted_data = [heapq.heappop(heap)[1] for _ in range(len(heap))]

print("after sort:" + str(sorted_data))


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


#---------------------------------------
#custom sort using __lt__ function
#Push 
#push and pop in heap

#--------------
class Person:
    def __init__(self, id, age):
        self.age = age
        self.id = id

    def __lt__(self, other:"Person"):
        return self.age < other.age
        #return self.id < other.id
    
    def __str__(self):
        return f"id: {self.id} age: {self.age}"
    

p1 = Person(10, 16)
p2 = Person(2, 15)
p3 = Person(3, 14)
p4 = Person(4, 13)
p7 = Person(7, 12)
p5 = Person(5, 12)

import heapq
heap = []

heapq.heappush(heap, p2)
heapq.heappush(heap, p1)
heapq.heappush(heap, p3)
heapq.heappush(heap, p4)
heapq.heappush(heap, p5)
print([h.age for h in heap])
p = heapq.heappop(heap)
print(p)

#-----------------------------------------------

