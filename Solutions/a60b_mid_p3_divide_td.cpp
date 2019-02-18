/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Top-down approach
 */

#include <cstdio>
#define N 500
#define MOD 1997

int dp[N+2][N+2];

int f(int n, int k) {
    if (k == 1 || n == k) {
        return 1;
    }
    if (dp[n][k])   return dp[n][k];
    return dp[n][k] = (f(n-1, k-1) % MOD + k*f(n-1, k) % MOD) % MOD;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", f(n, k));
    return 0;
}