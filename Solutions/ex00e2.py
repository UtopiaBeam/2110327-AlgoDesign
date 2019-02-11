#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

import numpy as np
from itertools import product
r, c = map(int, input().split())
q = int(input())
tab = np.array(
    [[0] * (c + 1)] + [[0] + input().split() for _ in range(r)], dtype=int)

for _ in range(q):
    i1, j1, i2, j2 = map(int, input().split())
    if i1 > i2 or j1 > j2: print('INVALID')
    else:
        try:
            print(tab[i1:i2 + 1, j1:j2 + 1].max())
        except:
            print("OUTSIDE")
