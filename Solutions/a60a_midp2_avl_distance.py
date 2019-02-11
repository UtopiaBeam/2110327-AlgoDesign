#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#
from collections import defaultdict
from itertools import zip_longest, starmap
n, k = map(int, input().split())

edge = defaultdict(list)
for _ in range(n - 1):
    a, b = map(int, input().split())
    edge[a].append(b)


def caldistance(l1: list, l2: list, k: int):
    return sum(l1[i] * l2[k-i] for i in range(len(l1)) if i <= k and k - i < len(l2))


def recur(nw: int):
    curr = [1]
    summ = 0
    for sm, lis in map(recur, edge[nw]):
        lis = [0] + lis
        summ += sm + caldistance(curr, lis, k)
        curr = list(map(sum, zip_longest(curr, lis, fillvalue=0)))
    return summ, curr


print(recur(1)[0])
