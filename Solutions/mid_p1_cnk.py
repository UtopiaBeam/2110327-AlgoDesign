#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

from functools import lru_cache

@lru_cache()
def binomial(n, k):
    return 1 if n == k or k == 0 else binomial(n - 1, k) + binomial(
        n - 1, k - 1)

print(binomial(*map(int, input().split())))