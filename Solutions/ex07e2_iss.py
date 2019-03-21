#
# AUTHOR: Natchapol Srisang (UtopiaBeam)
# KEYWORD: Integer partition
#


def DP(sm, most):
    if most == 0 or sm < 0:
        return 0
    if sm == 0:
        return 1
    if (sm, most) in dp:
        return dp[sm, most]
    dp[sm, most] = DP(sm, most-1) + DP(sm-most, most)
    return dp[sm, most]


n = int(input())
dp = dict()
print(DP(n, n))
