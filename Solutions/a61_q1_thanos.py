from bisect import bisect


def dq(p, ls):
    if p == 0:
        return A if len(ls) == 0 else B
    if len(ls) == 0:
        return A
    m = 2**(p-1)
    idx = bisect(ls, m)
    l, r = ls[:idx], [x-m for x in ls[idx:]]
    return min(dq(p-1, l) + dq(p-1, r), A if len(ls) == 0 else B*len(ls)*2**p)


p, _, A, B = map(int, input().split())
ls = sorted(map(int, input().split()))
print(dq(p, ls))
