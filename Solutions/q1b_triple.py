n, m = map(int, input().split())
ls = list(map(int, input().split()))
dc, ans = {}, [False]*m

for i, x in enumerate(map(int, input().split())):
    for j in range(n):
        if x-ls[j] not in dc:
            dc[x-ls[j]] = []
        dc[x-ls[j]].append((j, i))

for i in range(n):
    for j in range(i+1, n):
        sm = ls[i] + ls[j]
        if sm not in dc:
            continue
        for k, idx in dc[sm]:
            if i != k and j != k:
                ans[idx] = True
print(*['YES' if flag else 'NO' for flag in ans], sep='\n')
