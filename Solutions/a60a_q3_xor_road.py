#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Prim's Algorithm
#


def mst(c):
    n, sm = len(c), 0
    mx, inMst = [-1]*n, [False]*n
    mx[0] = 0
    for _ in range(n):
        u = mx.index(max(mx))
        sm += mx[u]
        mx[u], inMst[u] = float('-inf'), True
        for v in range(n):
            if not inMst[v]:
                mx[v] = max(mx[v], c[u] ^ c[v])
    return sm


c = [int(input()) for _ in range(int(input()))]
print(mst(c))
