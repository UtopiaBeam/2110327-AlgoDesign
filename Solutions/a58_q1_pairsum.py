#
# AUTHOR: Krist Pornpairin
# KEYWORD:
#

n, m = input().split()
st = set(int(i) for i in input().split())
for j in input().split():
  j = int(j)
  for i in st:
    if j - i in st:
      print("YES")
      break
  else:
    print("NO")