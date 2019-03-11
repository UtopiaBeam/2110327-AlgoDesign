#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

from collections import deque
from itertools import accumulate

n, qs = int(input()), accumulate(list(map(int, input().split()))*2)
mx, dq = -1e9, deque([(0, 0)])

for i, x in enumerate(qs):
    while dq and dq[0][1] + n <= i:
        dq.popleft()
    mx = max(mx, x - dq[0][0])
    while dq and dq[-1][0] > x:
        dq.pop()
    dq.append((x, i))
print(mx)
