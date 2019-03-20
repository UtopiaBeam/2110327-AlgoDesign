#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def dfs(u, d):
    ans = {u}
    if d == 0:
        return ans
    for v in g[u]:
        ans = ans | dfs(v, d-1)
    return ans


n, m, k = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    s, e = map(int, input().split())
    g[s].append(e)
    g[e].append(s)
print(max(len(dfs(i, k)) for i in range(n)))
