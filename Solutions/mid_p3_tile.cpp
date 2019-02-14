/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */ 
#include <cstdio>
#include <algorithm>
#define N 10
#define M (int)1e4
#define INF (int)1e9
using namespace std;

int dp[N+2][M+2];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 1; j*j <= m; j++) {
            for (int k = j*j; k <= m; k++) {
                dp[i][k] = min(dp[i][k], dp[i-1][k-j*j] + abs(x-j)*abs(x-j));
            }
        }
    }

    printf("%d\n", (dp[n][m] == INF)? -1 : dp[n][m]);
    return 0;
}