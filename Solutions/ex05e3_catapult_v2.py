#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Tarjan's Algorithm
#
from collections import Counter


def dfs(u):
    if dis[u] > 0:
        return
    global time
    dis[u], low[u], time = time, time, time+1
    isSt[u] = True
    st.append(u)
    for v in g[u]:
        if dis[v] < 0:
            dfs(v)
            low[u] = min(low[u], low[v])
        elif isSt[v]:
            low[u] = min(low[u], dis[v])
    v, cnt = -1, 0
    if dis[u] == low[u]:
        while u != v:
            v = st.pop()
            isSt[v] = False
            cnt += 1
        ans.append(cnt)


n = int(input())
g = [list(map(int, input().split()[1:])) for _ in range(n)]
dis, low = [-1]*n, [float('inf')]*n
st, isSt = [], [False]*n
ans, time = [], 1
for u in range(n):
    if dis[u] < 0:
        dfs(u)
print(*sorted(ans))
