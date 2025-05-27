import math

class Employee:
    def __init__(self, name, id):
        self.name = name
        self.id = id
        self.grades = []

    def add_grade(self, grade):
        self.grades.append(grade)

    def average_grades(self):
        return sum(self.grades)/len(self.grades)

class Manager(Employee):
    def __init__(self, name, id):
        self.name = name
        self.id = id
        Employee(name, id)


e = Employee('name', 1)
e.name="BBBB"
e.add_grade(2)
e.add_grade(4)
avg = e.average_grades()
print("name: " + e.name)





