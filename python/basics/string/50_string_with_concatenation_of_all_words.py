'''
https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150

words in the words list are all of same size.
so, in the string s, for each index, you can check split strings, and check if all the strings are present in the substring
function, that checks if the substrings are present..
hashtable...
'''

def split_string_by_length(s, index, word_length, words):
    i = index
    words_copy = words.copy()
    #print("split_string_by_length: " + str(i))
    words_len = len(words_copy)
    while i <= len(s) -1 :
        part = s[i:i+word_length]
        #print("print: " + part)
        if part in words_copy:
            words_copy[part] -= 1
            if words_copy[part] == 0:
                del words_copy[part]
                #print("deleted part: " + part)
            #print("word removed: " + part + " size: " + str(len(words_copy)))
            if len(words_copy) == 0:
                return True
        else:
            #print("word not in words: " + part)
            return False
        i += word_length
        #print("i: " + i + " plus: " + i + word_length * words_len)
    return False

def string_with_concatenation_of_all_words(s: str, words: list[str]) -> list[int]:
    words_set = {}
    number_words = len(words)
    length_word = len(words[0])
    words_len = number_words*length_word
    for word in words:
        if word not in words_set:
            words_set[word] = 1
        else:
            words_set[word] += 1
   
    def check_for_words(i, words, words_len):
        #split the 
        if i + words_len > len(s):
            #print("out of index: " + str(i))
            return False
        else:
            #print("valid index+ " + str(i))
            return split_string_by_length(s, i, length_word, words_set)
            #print("index = " + str(i) + " status:" + str(ret))
        return False
    result = []
    for i in range(len(s)-number_words*length_word+1):
        ret = check_for_words(i, words, words_len)
        if ret:
            result.append(i)
    return result


s = "a"
words = ["a"]
result = string_with_concatenation_of_all_words(s, words)
print("result: " + str(result))
#[0]

s = "wordgoodgoodgoodbestword"
words = ["word","good","best","good"]
result = string_with_concatenation_of_all_words(s, words)
print("result: " + str(result))
#[8]

s = "barfoothefoobarman"
words = ["foo","bar"]

#Output: [0,9]
#The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
#The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
result = string_with_concatenation_of_all_words(s, words)
print("result: " + str(result))


s = "wordgoodgoodgoodbestword"
words = ["word","good","best","word"]
#Output: []
result = string_with_concatenation_of_all_words(s, words)
print("result: " + str(result))


s = "barfoofoobarthefoobarman"
words = ["bar","foo","the"]
#Output: [6,9,12]
#The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
#The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
#The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
result = string_with_concatenation_of_all_words(s, words)
print("result: " + str(result))
