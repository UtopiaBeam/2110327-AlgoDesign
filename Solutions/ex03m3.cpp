/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */ 
#include <cstdio>
#include <algorithm>
#define N (int)1e4
using namespace std;

int dp[N+2];
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = -k; j <= k; j++) {
            if (i+j <= 0 || i+j > n)
                continue;
            int y = max(0, i-k-1);
            dp[i+j] = dp[i+j]? min(dp[i+j], dp[y] + x) : dp[y] + x;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}