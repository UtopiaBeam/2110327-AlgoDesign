#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Topological ordering
#

n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]
for _ in range(5):
    ls = list(map(int, input().split()))
    dc = dict(zip(ls, range(n)))
    for s, e in edges:
        if dc[s] > dc[e]:
            print('FAIL')
            break
    else:
        print('SUCCESS')
