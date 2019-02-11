#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

from itertools import islice


class Node:
    def __init__(self, n=None):
        if n > 1:
            self.l = self.r = Node(n // 2)
            self.m = n % 2
            self.size = self.l.size * 2 + 1
            self.summ = self.l.summ * 2 + self.m
        else:
            self.l = self.r = None
            self.m = n
            self.size = 1
            self.summ = n

    def sum(self, k):
        if self is None: return 0
        if k == 0: return 0
        if k == 1 and self.size == 1: return self.summ
        szl = 0 if self.l is None else self.l.size
        sml = 0 if self.l is None else self.l.summ
        if k <  szl + 1: return self.l.sum(k)
        if k == szl + 1: return sml + self.m
        if k >  szl + 1: return sml + self.m + self.r.sum(k - szl - 1)


def solve(n):
    if n <= 1:
        yield n
    else:
        yield from solve(n // 2)
        yield n % 2
        yield from solve(n // 2)


n, l, r = map(int, input().split())
# print(sum(islice(solve(n), l - 1, r)))
nd = Node(n)
print(nd.sum(r) - nd.sum(l - 1))