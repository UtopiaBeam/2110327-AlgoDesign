#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Kosaraju's Algorithm
#


def dfs(u):
    if chk[u]:
        return
    chk[u] = True
    for v in g[u]:
        dfs(v)
    st.append(u)


def rdfs(u):
    if not chk[u]:
        return 0
    cnt = 1
    chk[u] = False
    for v in gr[u]:
        cnt += rdfs(v)
    return cnt


n = int(input())
g, gr = [[] for _ in range(n)], [[] for _ in range(n)]
for u in range(n):
    for v in list(map(int, input().split()))[1:]:
        g[u].append(v)
        gr[v].append(u)
st, chk = [], [False]*n
for i in range(n):
    if not chk[i]:
        dfs(i)
print(*sorted(rdfs(u) for u in st[::-1] if chk[u]))
