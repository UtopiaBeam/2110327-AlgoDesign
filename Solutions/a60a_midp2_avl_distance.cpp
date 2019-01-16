#include <cstdio>
#include <vector>
#define L long long
#define N (int)5e4
#define K 500
using namespace std;

vector<int> g[N+2];
L dp[N+2][K+2];
int n, k;
L ans = 0;

void dfs(int p, int u, int lv) {
    dp[u][0] = 1;
    for (int &v: g[u]) {
        dfs(u, v, lv+1);
        for (int i = 0; i < k; i++) {
            ans += dp[v][i] * dp[u][k-1-i];
        }
        for (int i = 1; i < k; i++) {
            dp[u][i] += dp[v][i-1];
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
    }
    dfs(0, 1, 1);
    printf("%lld\n", ans);
    return 0;
}