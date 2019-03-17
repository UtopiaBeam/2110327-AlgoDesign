#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

W, _ = map(float, input().split())
ls = sorted(zip(map(float, input().split()), map(
    float, input().split())), key=lambda x: -float('inf') if x[1] == 0 else -x[0]/x[1])

ans = 0
for v, w in ls:
    ans += v if w == 0 else v/w * min(w, W)
    W -= w
    if W <= 0:
        break
print('%.4f' % ans)
