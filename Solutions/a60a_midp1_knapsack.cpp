/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: 0/1 Kanpsack
 */

#include <cstdio>
#include <vector>
#define N 500
using namespace std;

int dp[N+2][N+2];
int v[N+2], w[N+2];
vector<int> ans;

void ks(int n, int m) {
    if (n == 0 || m == 0) {
        return;
    }
    if (m >=w[n] && dp[n-1][m-w[n]] + v[n] == dp[n][m]) {
        ans.push_back(n);
        ks(n-1, m-w[n]);
    } else {
        ks(n-1, m);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", v+i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", w+i);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    ks(n, m);

    printf("%d\n", ans.size());
    for (int &x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}