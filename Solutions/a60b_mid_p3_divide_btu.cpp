/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Bottom-up approach
 */

#include <cstdio>
#define N 500
#define MOD 1997

int dp[N+2][N+2];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k && j <= n; j++) {
            if (j == 1 || i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i-1][j-1] + j*dp[i-1][j]) % MOD;
            }
        }
    }

    printf("%d\n", dp[n][k]);
    return 0;
}