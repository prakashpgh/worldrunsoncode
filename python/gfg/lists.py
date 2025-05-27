# creating a student_info list to store the information about the student roll no,name, course and marks scored
Student_info = [21, 'Rose', "CSE", 30, 40, 50]
print(Student_info)

Student_info = [21, 'Rose', "CSE", 30, 40, 50, 120]
print("Student_roll :", Student_info[0], end=' , ')
print("Student_name :", Student_info[1], end=', ')
print("Student_totalMarks :", Student_info[-1], end=' ')

#changing elements
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
Student_info[2] = "ME"
print(Student_info)

#adding elements
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
Student_info.append(50)
print(Student_info)

#removing elements
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
Student_info.remove(50)
print(Student_info)

#appending lists
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
Student2_info = [22, "John", "ME", 40, 40, 50, 130]
print(Student_info + Student2_info)


#string repetition
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
print(Student_info * 2)

#sort and reverse
List = [2.0, 24.1, 3.6, 12.0, 4.5]
print(len(List))
List.sort()
print(List)
List.reverse()
print(List)

#multi dim
List1 = [[2, 4, 6, 8, 10], [3, 6, 9, 12, 15], [4, 8, 12, 16, 20]] 
List1.append([5, 10, 15, 20, 25]) 
print(List1) 


List = [[2, 4, 6, 8, 10], [3, 6, 9, 12, 15], [4, 8, 12, 16, 20]] 
List[0].extend([12, 14, 16, 18]) 
print(List)

###########
#list comprehensions
squares = [x**2 for x in range(5)]
print(squares)

even_numbers = [x for x in range(10) if x % 2 == 0]
print(even_numbers)

matrix = [[i * j for j in range(3)] for i in range(4)]
print(matrix)

letters = ['a', 'b', 'c']
uppercase_letters = [letter.upper() for letter in letters]
print(uppercase_letters)


