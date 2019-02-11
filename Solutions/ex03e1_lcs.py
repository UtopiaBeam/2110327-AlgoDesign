#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

import functools
import sys
sys.setrecursionlimit(3000)

s1 = input().strip()
s2 = input().strip()

@functools.lru_cache(maxsize=None)
def LCS(i: int, j: int):
    if i == 0 or j == 0: return 0
    if s1[i - 1] == s2[j - 1]:
      return 1 + LCS(i - 1, j - 1) 
    else:
      return max(LCS(i - 1, j), LCS(i, j - 1))

print(LCS(len(s1), len(s2)))