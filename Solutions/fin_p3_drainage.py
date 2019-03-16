#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

n, l = map(int, input().split())
ls = sorted(list(map(int, input().split())))
s, cnt = ls[0], 1
for x in ls:
    if s+l <= x:
        s, cnt = x, cnt+1
print(cnt)
