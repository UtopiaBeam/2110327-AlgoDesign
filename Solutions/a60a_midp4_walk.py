#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

r, c = map(int, input().split())
m = [list(map(int, input().split())) for i in range(r)]
for i in range(r):
    for j in range(c):
        m[i][j] += max([
            m[i - 1][j] if i else 0,
            m[i][j - 1] if j else 0,
            m[i-1][j-1] + m[i][j] if i and j else 0
        ]) if i or j else 0
print(m[-1][-1])