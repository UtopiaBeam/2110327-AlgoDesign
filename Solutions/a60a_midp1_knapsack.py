#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: 0/1 Kanpsack
#


def ks(n, m, ans=[]):
    if n == 0 or m == 0:
        print(len(ans))
        print(*ans)
        return
    global v, w, dp
    if m >= w[n-1] and dp[n-1][m-w[n-1]] + v[n-1] == dp[n][m]:
        ks(n-1, m-w[n-1], ans+[n])
    else:
        ks(n-1, m, ans)


n, m = map(int, input().split())
v, w = [list(map(int, input().split())) for _ in range(2)]
dp = [list(map(int, input().split())) for _ in range(n+1)]
ks(n, m)
