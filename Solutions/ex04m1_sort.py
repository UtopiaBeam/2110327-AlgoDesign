#
# AUTHOR: Natchapol Srisang
#
from sys import stdin as kb
from collections import Counter


def mn(x, y):
    global dc
    return min(dc[x, y], dc[y, x])


n, ls = int(kb.readline()), list(map(int, kb.readline().split()))
dc = Counter(zip(ls, sorted(ls)))
q = n - (dc[1, 1] + dc[2, 2] + dc[3, 3])
s = mn(1, 2) + mn(2, 3) + mn(3, 1)
print((q+s) * 2//3 - s)
