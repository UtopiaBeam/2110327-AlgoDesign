from itertools import accumulate

m, n = map(int, input().split())
ls = sorted(map(int, input().split()))
print('%.3f' % (sum(sum(accumulate(ls[i::m])) for i in range(m)) / n))
