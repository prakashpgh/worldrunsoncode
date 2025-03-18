'''
https://leetcode.com/problems/search-suggestions-system/description/?envType=study-plan-v2&envId=leetcode-75

Trie
prefix matching problem..
wait till you get 3 matches...
1) create the trie from the products
2) for word, iterate the characters and call the prefix function
'''





products = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"
#Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
