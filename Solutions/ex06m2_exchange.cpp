/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Floyd-Warshall
 */

#include <cstdio>
#include <algorithm>
#define N 500

double dp[N+2][N+2];

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lf", &dp[i][j]);
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k]*dp[k][j]);
                }
            }
        }

        bool chk = false;
        for (int i = 0; i < n; i++)
            chk = chk | (dp[i][i] > 1);
        
        printf(chk? "YES\n" : "NO\n");
    }
}