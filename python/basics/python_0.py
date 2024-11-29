
def printEnd():
    print("-" * 100)

#str => immutable sequence of characters
str1="test"
print(type(str1))

printEnd()
#range => immutable sequence
#iterating range
rg = range(1,10)
for i in rg:
    print( i, end=",")

printEnd()
#reverse range
rg = range(10, 1, -1)
for i in rg:
    print(i, end=",")

printEnd()

#tuple => immutable sequence
print("printing tuple")
tup = (10,8,6,4,2)
print ("tuple expected: " + str(type(tup)))
for i in tup:
    print(i, end=",")

printEnd()    


#list - mutable sequence
lst = [1,2,3,4,5,6,7,8,9,10]
print("printing list...")
for i in lst:
    print(i, end=",")

print("check in operator: " + str(3 in lst))


lst_2 = [1,2,3,4,5,6,7,8,9,10]
#lst_3=list + lst_2  # + is not supported
printEnd()    

#SLICES
x = "hello world"
x1=x[0:5:1]  #start:stop:step
print(x1)

#dictionaries
dict = {'a' : 1, 'b' : 2}
print("dict: " + str(dict))

printEnd()

#in operator

#Conditional operators
#if():
#else:
for i in range(0,10):
    print(i, end=",")

#enumerate function
for i,j in enumerate((1,2,3,4,5,6,7,8,9,10)):
    print("i=" + str(i) + " j=" + str(j))

#comprehensions or way of transforming sequences
lst = "hello"
print("lower:" + lst)
lst = [c.upper() for c in lst]
print("upper:" + str(lst))
printEnd()

#function
print("start of functions")

try:
    i = 8/0
except Exception as e:
    print("exception:" + str(e))

printEnd()
#####################################
#Classes

class Test:
    i = 0
    def __init__(self):
        self.instance_i = 0

    def increment(self):
        Test.i = Test.i + 1
        self.instance_i = self.instance_i + 1
    
    def print(self):
        print("class-i: " + str(Test.i))
        print("instance-i: " + str(self.instance_i))


t = Test()
t.increment()
t.print()

t1= Test()
t1.increment()
t1.print()
########################################

print(dir(str))
#for item in dir(str):
#    print (item)

printEnd()
#################################################
#inheritance

class Person:
    def __init__(self, firstName, lastName):
        self._firstName = firstName
        self._lastName = lastName
        print("Parent constructor")

    def printName(self):
        print(self._firstName + " " + self._lastName)

    def test():
        print("parent test")

class Child(Person):
    def __init__(self, firstName, lastName, year):
        super().__init__( firstName, lastName)
        self._year = year
        print("child __init__")

    def printDetails(self):
        super().printName()
        print("year:" + str(self._year))

c = Child("fname", "lastName", 2019)
c.printDetails()

##################################################################
#reverse a string
s = "hello world"
for i in range(-1,-(len(s)+1),-1):
    print(s[i], end="")
print("")
##################################################################

from mymodule import test
test()
###################################################################
#
#package contains one or more modules
#
from my_package import mymodule_1
mymodule_1.test()

from my_package import mymodule_2
mymodule_2.test()

###################################################################
#read csv into json 

f = open('fake_fruit.json', 'r')      # open the file for reading
print(f.read())                       # read and print the file content
f.close()                             # close the file

import json         # import the Python json module

with open('fake_fruit.json', 'r') as f:  # open the JSON file for reading
    data = json.load(f)                  # de-serialise the JSON into data

print(data)         # data is a python dict containing the JSON data

data['Fruit'][1]['Name'] = 'Wrong'        # write 'Wrong' to 'Name' field
    
with open ('fake_fruit.json', 'w') as f:   # open the JSON file for writing
    json.dump(data, f, indent=4)           # write JSON back to file          

with open('fake_fruit.json', 'r') as f:    # open one final time
    print(f.read())                        # print the new file contents