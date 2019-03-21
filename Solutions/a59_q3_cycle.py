from sys import stdin as kb


def dfs(u, p, dis):
    global d, ans
    if d[u] != -1:
        if ans < 0:
            ans = dis-d[u]
        return
    d[u] = dis
    for v in g[u]:
        if v != p:
            dfs(v, u, dis+1)


n = int(kb.readline())
g = [[] for _ in range(n)]
for _ in range(n):
    s, e = map(int, kb.readline().split())
    g[s].append(e)
    g[e].append(s)
ans, d = -1, [-1]*n
dfs(0, -1, 0)
print(ans)
