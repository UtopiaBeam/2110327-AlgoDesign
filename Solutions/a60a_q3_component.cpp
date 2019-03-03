/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <cstdio>
#include <vector>
#define N (int)1e4
using namespace std;

vector<int> g[N+2];
int cnt = 0;
bool chk[N+2];

void dfs(int u) {
    if (chk[u])     return;
    chk[u] = true;
    for (int &v: g[u]) {
        dfs(v);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }

    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            dfs(i);
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}