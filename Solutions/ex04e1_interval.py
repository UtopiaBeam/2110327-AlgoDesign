#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

n, ls = int(input()), list(
    zip(map(int, input().split()), map(int, input().split())))
en, cnt = 0, 0
for s, e in sorted(ls, key=lambda x: x[1]):
    if s < en:
        continue
    en, cnt = e, cnt+1
print(cnt)
