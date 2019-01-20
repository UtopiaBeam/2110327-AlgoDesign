# AUTHOR: Rodchananat Khunakornophat
def x(): return [*map(int, input().split())]
r, c, k = x()
a = [[0] * (c+1)] + [[0]+x() for i in range(r)]
for i in range(1, r+1):
    for j in range(1, c+1):
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1]
print(*(a[b+1][r+1] - a[b+1][l] - a[t][r+1] + a[t][l]
        for _ in range(k) for t, l, b, r in [x()]))
