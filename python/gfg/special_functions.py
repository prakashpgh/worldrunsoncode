#zip
tuple1 = (1, 4, 8)
List1 = ["Geeks" , "for", "Geeks", "Python"]
zipped_data = zip(tuple1, List1)
print(list(zipped_data))


#filter
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

def is_even(number):
    return number%2==0
filtered_numbers = list(filter(is_even, numbers))
print(filtered_numbers)


programming_languages = ["C", "C++", "Java", "Python", "JavaScript", "Ruby", "Swift"]
# Using filter with lambda to filter strings containing "Python"
java_languages = list(filter(lambda lang: "Java" in lang, programming_languages))
print("Programming Languages:", programming_languages)
print("Languages containing 'Java':", java_languages)


numbers = [1, 2, 3, 4, 5]
# Using map to square each element
squared_numbers = map(lambda x: x**2, numbers)
result_list = list(squared_numbers)
print(result_list)


x = lambda a: a + 10
print(x(5))
v = list(map(lambda x: x + 10, [1, 2, 3, 4, 5]))
print(v)

#ASCII
char = 'A'
ascii_code = ord(char)
print(ascii_code)

ascii_code = 97
character = chr(ascii_code)
print(character)


#map
