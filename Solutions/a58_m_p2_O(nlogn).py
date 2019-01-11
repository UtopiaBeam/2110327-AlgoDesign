from collections import defaultdict
dc = defaultdict(lambda: float('inf'))


def bs(s, e, k):
    if s >= e:
        return s
    m = (s+e) // 2
    return bs(s, m, k) if k <= dc[m] else bs(m+1, e, k)


n = int(input())
ls = list(map(int, input().split()))
ans = 0
for x in ls:
    l = bs(1, len(ls), x)
    dc[l] = x
    ans = max(ans, l)
print(ans)
