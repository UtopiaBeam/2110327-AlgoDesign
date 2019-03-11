#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

n, m = map(int, input().split())
a, b = input().strip(), input().strip()
dp = [list(map(int, input().split())) for _ in range(len(a)+1)]
ans = ''

i, j = len(a), len(b)
while i > 0 and j > 0:
    if dp[i][j] == dp[i-1][j-1] + 1:
        i, j = i-1, j-1
        ans = a[i] + ans
    elif dp[i-1][j] >= dp[i][j-1]:
        i -= 1
    else:
        j -= 1

print(ans)
