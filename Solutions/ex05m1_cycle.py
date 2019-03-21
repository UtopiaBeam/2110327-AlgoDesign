#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#


def dfs(u, p):
    if not chk[u]:
        return True
    chk[u] = False
    ret = False
    for v in g[u]:
        if v != p:
            ret = ret or dfs(v, u)
    return ret


for _ in range(int(input())):
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        s, e = map(int, input().split())
        g[s].append(e)
        g[e].append(s)
    chk = [True]*n
    print('YES' if any(dfs(i, -1) for i in range(n) if chk[i]) else 'NO')
