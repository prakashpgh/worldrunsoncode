#https://leetcode.com/problems/first-bad-version/description/
#meta

bad_version = 0
def isBadVersion(version):
    return version == bad_version

def firstBadVersion(n) -> int:
    first_bad_version = 0
    l = 0
    r = n-1
    while l < r:      #  => mistake  if you do >=, goes in a loop
        m = l + (r-l)//2
        is_bad = isBadVersion(m+1)
        if is_bad:
            r = m
        else:
            l = m+1
    first_bad_version = r+1
    return first_bad_version


n=5
bad_version = 4
result = firstBadVersion(n)
print("result: " + str(result))


