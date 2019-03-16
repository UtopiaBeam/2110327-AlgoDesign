#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

n = int(input())
dp = [[0, 0] for _ in range(n+1)]
for i, x in enumerate(map(int, input().split()), 1):
    dp[i][0] = max(max(dp[i-2]) if i > 1 else 0, max(dp[i-1]))
    dp[i][1] = max(dp[i-2][0] if i > 1 else 0,
                   max(dp[i-3]) if i > 2 else 0) + x
print(max(dp[n]))
