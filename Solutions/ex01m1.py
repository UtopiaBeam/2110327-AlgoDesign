def f(sz, sx, sy, x, y):
    mx, my = sx - 1 + sz//2, sy - 1 + sz//2
    print(list(range(4))[(x > mx) + 2*(y > my)], mx, my)
    if sz == 2:
        return
    if x <= mx and y <= my:
        f(sz//2, sx, sy, x, y)
    else:
        f(sz//2, sx, sy, mx, my)
    if x > mx and y <= my:
        f(sz//2, mx+1, sy, x, y)
    else:
        f(sz//2, mx+1, sy, mx+1, my)
    if x <= mx and y > my:
        f(sz//2, sx, my+1, x, y)
    else:
        f(sz//2, sx, my+1, mx, my+1)
    if x > mx and y > my:
        f(sz//2, mx+1, my+1, x, y)
    else:
        f(sz//2, mx+1, my+1, mx+1, my+1)


l, x, y = map(int, input().split())
print((l*l - 1) // 3)
f(l, 0, 0, x, y)
