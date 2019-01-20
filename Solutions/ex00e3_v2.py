# AUTHOR: Rodchananat Khunakornophat
n = int(input())
l = {int(x)for x in input().split()}
print(["NO", "YES"][all(i in l for i in range(1, n+1))])
