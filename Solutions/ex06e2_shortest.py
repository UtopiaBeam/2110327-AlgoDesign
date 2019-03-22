#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Floyd-Warshall's Algorithm
#

n, m, s = map(int, input().split())
d = [[float('inf') if i != j else 0 for j in range(n)] for i in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    d[u][v] = w
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j] = min(d[i][j], d[i][k]+d[k][j])

if any(d[i][j] > d[i][k]+d[k][j] for k in range(n) for i in range(n) for j in range(n)):
    print(-1)
else:
    print(*[d[s][i] for i in range(n)])
