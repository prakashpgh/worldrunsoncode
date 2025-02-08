'''
https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150

1) find out all the words that fit into a line.
2) formatting..
3) formatting of last line


    ## mistake: took a loong time to submit

'''
def format_line( words, max_width):
    total_length = sum(len(s) for s in words)
    if total_length <= max_width:
        space = 0
        extra = 0
        if len(words) == 1:
            space = max_width - len(words[0])+1
            words[0] += ' ' * (max_width - len(words[0]))
        else:
            space, extra = divmod((max_width - total_length), len(words)-1)
            for i in range(0, len(words)-1):
                extra_i = 0
                if extra > 0:
                    extra_i = 1
                    extra -= 1
                words[i] += ' ' * (space + extra_i-1)
        line = " ".join(words)
        return line
    return ""



def text_justification(words: list[str], maxWidth: int) -> list[str]:
    result = []
    i = 0
    while i < len(words):
        current_line = []
        curr_len = 0
        while i < len(words) and curr_len + len(words[i]) <= maxWidth:
            curr_len += len(words[i])
            curr_len += 1
            current_line.append(words[i])
            i += 1

        if i >= len(words):
            line = " ".join(current_line)
            if len(line) < maxWidth:
                line += " " * (maxWidth - len(line))
        else:
            line = format_line(current_line, maxWidth)
        result.append(line)

    return result


words = ["Listen","to","many,","speak","to","a","few."]
maxWidth = 6
output = text_justification(words, maxWidth)
print("output: " + str(output))



words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
'''
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
'''
output = text_justification(words, maxWidth)
print("output: " + str(output))



words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
'''
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
'''
output = text_justification(words, maxWidth)
print("output: " + str(output))





words = ["What","must","be","acknowledgment","shall","be"]
output = text_justification(words, maxWidth)
print("output: " + str(output))

maxWidth = 16
'''
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
'''

