#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
#

n, a, b, c = map(int, input().split())
dp = [0] + [-float('inf')] * n
for i in range(1, n+1):
    dp[i] = max(dp[i-a] if i >= a else -float('inf'),
                dp[i-b] if i >= b else -float('inf'),
                dp[i-c] if i >= c else -float('inf')) + 1
print(dp[n])
