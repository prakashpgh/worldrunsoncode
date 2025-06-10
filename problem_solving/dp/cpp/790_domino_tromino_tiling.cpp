'''
https://leetcode.com/problems/domino-and-tromino-tiling/

https://www.youtube.com/watch?v=ej3lT1CkPZs

dominos =>  can be arranged in 2 ways
tromino => can be arranged in 4 ways L, reflection on Y-axis(mirror), refelection of X-axis(invert), invert=>mirror

(n-1) + 1
(n-2) + 2 [2 horizontal or 2 vertical]

fr = full rect
fr[n] = fr(n-1) + 1     => use of domino vertically for nth
      + fr(n-2) + 2     => use of 2 dominos horizontally 
      + bcm(n-1)       => bottom n-1 and n missing, top n missing
      + tcm(n-1)       => top n-1 and n missing, bottom n missing

    bottom-corner-missing can be manifested in 2 ways:
        tcm(n-1) + top horizontal
        fr(n-2) + L(with 90 degree rotation)

    top cell missing
        fr(n-2) + L(with no rotation)
        bcm(n-1) + horizontal

        n=0 =>  1
        n=1 =>  1

    array storing all possible combinations

'''

def tilings(n: int) -> int:
    fr = { 0:1, 1 : 1}
    top_rect = {1: 0}
    bottom_rect = {1:0}

    #solution for n-th tile
    for i in range(2, n+1):
        print("n="+str(n) + "   " + str(fr))
        fr[n] = fr[n-1] + fr[n-2] + top_rect[n-1] + bottom_rect[i-1]
        
        top_rect[i] = fr(n-2) + bottom_rect[n-1]
        bottom_rect[i] = fr[i-2] + top_rect[i-1]
    return fr[n]
 

n=3
result = tilings(3)
print("result:" + str(result))





