#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

# https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
import functools
__import__('sys').setrecursionlimit(2100)
@functools.lru_cache(maxsize=None)
def recur(n: int, k: int):
    if not n and not k: return 1
    if not n or not k: return 0
    return (k * recur(n - 1, k) + recur(n - 1, k - 1)) % 1997

print(recur(*map(int, input().split())))