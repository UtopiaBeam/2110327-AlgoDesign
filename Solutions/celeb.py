# AUTHOR: Rodchananat Khunakornophat
n = int(input())
k = [[int(x) for x in input().split()] for i in range(n)]
cel = [i+1 for i in range(n) if all(k[x][i] for x in range(n) if x != i)
       and all(not k[i][x] for x in range(n) if x != i)] + [0]
print(cel[0])
