import numpy as np


def pwm(mat, n, k):
    if n == 0:
        return np.identity(2, dtype=int)
    x = pwm(mat, n//2, k) % k
    return (x**2 if n % 2 == 0 else mat*x**2) % k


n, k = map(int, input().split())
a, b, c, d = map(int, input().split())
mat = np.mat([[a, b], [c, d]], dtype=int)
print(*np.array(pwm(mat, n, k)).flatten())
