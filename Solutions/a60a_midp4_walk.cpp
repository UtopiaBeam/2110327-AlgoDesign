#include <cstdio>
#include <algorithm>
#define N 500
using namespace std;

int r, c;
int a[N+2][N+2];
int dp[N+2][N+2];

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int tmp = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
            if (i == 1 || j == 1) {
                dp[i][j] = max(tmp, dp[i-1][j-1] + a[i][j]);
            } else {
                dp[i][j] = max(tmp, dp[i-1][j-1] + 2*a[i][j]);
            }
        }
    }

    printf("%d\n", dp[r][c]);
    return 0;
}