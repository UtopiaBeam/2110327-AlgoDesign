_, ls = input(), list(map(int, input().split()))
if all(x < 0 for x in ls):
    print(max(ls))
else:
    ans, sm = 0, 0
    for x in ls:
        sm += x
        if sm < 0:
            sm = 0
        ans = max(ans, sm)
    print(ans)
