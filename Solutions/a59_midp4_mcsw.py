#
# AUTHOR: Krist Pornpairin
# KEYWORD: Sliding window minimum
#

from itertools import accumulate
from collections import deque, namedtuple

Data = namedtuple('Data', 'idx val')

_, k = map(int, input().split())

dq = deque([Data(0, 0)])
mx = -1e9
for i, qsm in enumerate(accumulate(map(int, input().split())), 1):
    while dq[0].idx + k < i:
        dq.popleft()
    mx = max(mx, qsm - dq[0].val)
    while dq and dq[-1].val > qsm:
        dq.pop()
    dq.append(Data(i, qsm))
print(mx)
