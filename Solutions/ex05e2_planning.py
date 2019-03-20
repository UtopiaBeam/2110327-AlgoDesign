#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Topological sort
#


def dfs(u):
    if chk[u]:
        return
    chk[u] = True
    for v in g[u]:
        dfs(v)
    st.append(u)


n = int(input())
g = [list(map(int, input().split()))[1:] for _ in range(n)]
st, chk = [], [False]*n
for i in range(n):
    if not chk[i]:
        dfs(i)
print(*st)
