#include <cstdio>
#include <algorithm>
#define N 20
#define M 10000
#define INF 1<<20

int n, m;
int a[N+2], dp[M+2];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    for (int k = 1; k <= m; k++) {
        int tmp = INF;
        for (int i = 0; i < n; i++) {
            if (a[i] > k)       continue;
            tmp = std::min(tmp, dp[k-a[i]] + 1);
        }
        dp[k] = tmp;
    }

    printf("%d\n", dp[m]);
    return 0;
}