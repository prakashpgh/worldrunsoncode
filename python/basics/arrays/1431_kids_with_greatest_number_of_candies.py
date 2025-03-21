'''
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

array problem
'''


def kids_with_greatest_number_of_candies(candies: list[int], extra_candies:int) ->list[int]:
    max_candies = max(candies)
    result = [False] * len(candies)
    for i in range(len(candies)):
        if candies[i] + extra_candies > max_candies:
            result[i] = True
    return result    


