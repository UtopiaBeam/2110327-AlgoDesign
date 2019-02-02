#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

import numpy as np
n = int(input())
mat = np.array([input().split() for _ in range(n)], dtype=int)
for i in range(n):
    mat[i, i] = 0; r = (mat[i, :] == 0).all()
    mat[i, i] = 1; c = (mat[:, i] == 1).all()
    if r and c:
        print(i + 1)
        break
else:
    print(0)