#include <cstdio>
#include <algorithm>
#define N 100
#define INF 1<<20
using namespace std;

int n, a[N+2];
int dp[N+2][N+2];

int mcm(int s, int e) {
    if (s == e)         return 0;
    if (dp[s][e])       return dp[s][e];

    int tmp = INF;
    for (int i = s; i < e; i++) {
        tmp = std::min(tmp, mcm(s, i) + mcm(i+1, e) + a[s-1]*a[i]*a[e]);
    }

    return dp[s][e] = tmp;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", a+i);
    }

    printf("%d\n", mcm(1, n));
}