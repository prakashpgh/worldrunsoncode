'''
https://leetcode.com/problems/encode-and-decode-strings/description/
#todo
len#word1len#word2

'''

class Codec:
    def encode(self, strs: list[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        result = ""
        lst = []
        for s in strs:
            lst.append(len(s))
            lst.append("#")
            lst.append(s)
        return "".join(lst)
        

    def decode(self, s: str) -> list[str]:
        """Decodes a single string to a list of strings.
        """
        l = len(s)
        i = 0
        while i < l:
            s.
        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))