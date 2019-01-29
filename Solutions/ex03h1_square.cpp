#include <cstdio>
#include <algorithm>
#define N 1000

int r, c;
char a[N+2][N+2];
int dp[N+2][N+2];

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf(" %s", a[i]);
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == '1') {
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ans = std::max(ans, dp[i][j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}