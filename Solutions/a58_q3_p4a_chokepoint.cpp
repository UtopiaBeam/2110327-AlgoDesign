/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <vector>
#define N (int)1e5
#define L long long
using namespace std;

vector<int> g[N+2];
L ans[N+2], dp[N+2];
bool chk[N+2];
int n;

void dfs(int u) {
    if (chk[u])     return;
    chk[u] = true;
    dp[u] = 1;

    for (int v: g[u]) {
        if (!chk[v]) {
            dfs(v);
            ans[u] += dp[u]*dp[v];
            dp[u] += dp[v];
        }
    }
    ans[u] += (n-dp[u])*dp[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}