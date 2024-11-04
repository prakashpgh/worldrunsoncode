#module => singl file containing code.  PYTHONPATH

#package => directory of modules  , has __init__.py

def find_average(numbers):
    if not numbers:
        return 0
    return sum(numbers) / len(numbers)

def filter_even(numbers):
    return [num for num in numbers if num % 2 == 0]

def reverse_list(input_list):
    return input_list[::-1]

def concatenate_lists(list1, list2):
    return list1 + list2

if __name__ == "__main__":
    # Code here will only run when the module is executed directly
    print(reverse_list([2,4,5,7,9]))