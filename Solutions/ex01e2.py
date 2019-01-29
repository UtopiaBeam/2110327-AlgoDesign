_, ls = input(), list(map(int, input().split()))
if all(x < 0 for x in ls):
    print(max(ls))
else:
    sm, mx = 0, 0
    for x in ls:
        sm = 0 if (sm+x) < 0 else (sm+x)
        mx = max(mx, sm)
    print(mx)
