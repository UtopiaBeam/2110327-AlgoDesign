#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

import bisect
input()
lis = []
for val in map(int, input().split()):
    x = bisect.bisect_left(lis, val)
    lis[x:x + 1] = [val]
print(len(lis))