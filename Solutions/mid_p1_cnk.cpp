/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <iostream>
#define N 30
using namespace std;

int dp[N+2][N+2];

int C(int n, int k) {
    if (n == 0 || k == 0 || n == k) {
        return 1;
    }
    if (dp[n][k])       return dp[n][k];
    return dp[n][k] = C(n-1, k) + C(n-1, k-1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", C(n, k));
    return 0;
}