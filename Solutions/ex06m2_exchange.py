import numpy as np


def APSS(dp):
    n = len(dp)
    for k in range(n):
        for i in range(n):
            dp[i, :] = np.maximum(dp[i, :], dp[i, k]*dp[k, :])
        if any(dp[i, i] > 1 for i in range(n)):
            return 'YES'
    return 'NO'


for _ in range(int(input())):
    n = int(input())
    dp = np.array([list(map(float, input().split())) for _ in range(n)])
    print(APSS(dp))
