n = int(input())
ls = list(map(int, input().split()))
dp = [1] * n
for i in range(n):
    for j in range(i):
        dp[i] = max(dp[i], dp[j]+1 if ls[i] >= ls[j] else 0)
print(max(dp))
