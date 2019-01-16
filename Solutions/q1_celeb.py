import numpy as np

n = int(input())
arr = np.array([list(map(int, input().split())) for _ in range(n)])
ans = [i+1 for i in range(n) if sum(arr[i, :]) ==
       0 and sum(arr[:, i]) == n-1] + [0]
print(ans[0])
