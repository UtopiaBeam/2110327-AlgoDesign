#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def res(m):
    s, cnt, i = 0, 0, 0
    while i < len(ls):
        while i < len(ls) and s+m >= ls[i]:
            i += 1
        if i < len(ls) and ls[i]-ls[i-1] > m:
            return float('inf')
        s, cnt = ls[i-1], cnt+1
    return cnt


def bs(s, e, k):
    if s == e:
        return s, res(s)
    m = (s+e) // 2
    return bs(s, m, k) if res(m) <= k else bs(m+1, e, k)


_, k = map(int, input().split())
ls = [0] + sorted(list(map(int, input().split())))
print(*bs(0, int(1e18), k))
