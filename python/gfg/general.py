import  module_1

def print_values(*args, **kwargs):
    print("Positional arguments:", args)
    print("Keyword arguments:", kwargs)

print_values(1, 2, 3, name="Rose", age=24)

#i = sum_test(a,b)


a = [2,3,'abc', 5, 'geek']
try:
  a[2] = int(a[2])
  a[3] = a[3]/a[1]
except IndexError:
  print("Index out of bound")
except ValueError:
  print("the value can not be converted to Int type")
except DivideByZero:
  print("Can not divide by zero")



