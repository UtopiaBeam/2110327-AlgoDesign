from sys import stdin as kb
n, _ = map(int, kb.readline().split())
ls = list(map(int, kb.readline().split()))


def bs(s, e, k):
    if s == e:
        return s
    global ls
    m = (s+e) // 2
    return bs(s, m, k) if sum(m//t for t in ls) + n >= k else bs(m+1, e, k)


for x in map(int, kb.readline().split()):
    print(bs(0, int(1e16), x))
