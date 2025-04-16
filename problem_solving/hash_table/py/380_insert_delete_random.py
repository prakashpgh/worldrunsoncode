'''
https://leetcode.com/problems/insert-delete-getrandom-o1/

hashmap/dictionary => insert, remove
                        getRandom is bad.   
                        we will use list to store the keys => key mapping in a list


list    
    hashmap will store value, list-index

    remove => swap with end, 
                remove from end..   
                get index from hashmap, .. 

    insert -> not an issue

    random -> get random.. get the key from the random index, use the key for retrieving from dictionary


'''
import random

class RandomizedSet:

    def __init__(self):
        self.my_dict = {}
        self.my_list = []
        

    def insert(self, val: int) -> bool:
        if val in self.my_dict:
            return False
        else:
            self.my_list.append(val)
            self.my_dict[val]=len(self.my_list)-1
            return True

    def remove(self, val: int) -> bool:
        if val in self.my_dict:
            index = self.my_dict[val]
            index_value = self.my_list[index]
            last_value = self.my_list[len(self.my_list)-1]

            self.my_list[index] = self.my_list[len(self.my_list)-1]
            self.my_list[len(self.my_list)-1] = index_value

            self.my_dict[index_value]=len(self.my_list)-1   #mistake - you missed this change of mapping
            self.my_dict[last_value]=index
            self.my_list.pop()
            del self.my_dict[val]
            return True
        else:
            return False
        

    def getRandom(self) -> int:
        return random.choice(self.my_list)


# Your RandomizedSet object will be instantiated and called as such:
obj = RandomizedSet()
ret = obj.insert(1)
print("ret: " + str(ret))
ret = obj.remove(2)
print("ret: " + str(ret))
ret = obj.insert(2)
print("ret-insert: " + str(ret))
ret = obj.getRandom()
print("ret-random: " + str(ret))

ret = obj.remove(1)
print("ret-remov: " + str(ret))
ret = obj.insert(2)
print("ret: " + str(ret))
ret = obj.getRandom()
print("ret-random: " + str(ret))
