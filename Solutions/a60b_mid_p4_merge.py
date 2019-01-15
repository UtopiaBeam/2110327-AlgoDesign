n, k = map(int, input().split())


def f(s, e):
    global k
    if s == e:
        print(s, end=' ')
        return
    m = (s+e) // 2
    if k == 0:
        f(s, m)
        f(m+1, e)
    else:
        k -= 2
        f(m+1, e)
        f(s, m)


if k % 2 == 0 or k > 2*n-1:
    print(-1)
else:
    k -= 1
    f(1, n)
