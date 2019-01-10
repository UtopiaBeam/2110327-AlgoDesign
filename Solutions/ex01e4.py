def pwm(x, n, k):
    if n == 0:
        return 1
    tmp = pwm(x, n//2, k) % k
    return (tmp**2 if n % 2 == 0 else x * tmp**2) % k


x, n, k = map(int, input().split())
print(pwm(x, n, k))
