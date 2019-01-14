from collections import Counter

n, dc = int(input()), Counter(list(map(int, input().split())))
print('YES' if all(dc[k] == 1 and 0 < k <= n for k in dc.keys()) else 'NO')
