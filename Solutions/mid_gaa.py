#
# AUTHOR: Krist Pornpairin
# KEYWORD: divide n conquer
#

from itertools import accumulate


def g(n):
    return g(n - 1) + "g" + "a" * (n + 2) + g(n - 1) if n else "gaa"


def f(n, layer=0, prvsize=0):
    size = prvsize + 1 + (layer + 2) + prvsize
    if n >= size:
        n = f(n, layer + 1, size)
        if type(n) is str:
            return n
    assert n < size
    tokk = [prvsize, 1, layer + 2, prvsize]
    tokv = [n, 'g', 'a', n - prvsize - 1 - (layer + 2)]
    return next(v for k, v in zip(accumulate(tokk), tokv) if n < k)


assert g(3) == ''.join(map(f, range(0, 56)))

print(f(int(input()) - 1))