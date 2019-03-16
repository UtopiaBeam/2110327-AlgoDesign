/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <queue>
#include <vector>
#define N 1000
#define P pair<int, int>
#define F first
#define S second
using namespace std;

vector<int> g[N+2];
queue<P> q;
int ans = 0;
bool chk[N+2];

void bfs(int s, int k) {
    q.push( P(s, 0) );
    while (!q.empty()) {
        int u = q.front().F, d = q.front().S;
        q.pop();
        if (chk[u])     continue;
        chk[u] = true;
        if (d == k) {
            ans++;
            continue;
        }
        for (int v: g[u]) {
            if (!chk[v]) {
                q.push( P(v, d+1) );
            }
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        g[s].push_back(e);
        g[e].push_back(s);
    }

    bfs(0, k);

    printf("%d\n", ans);
    return 0;
}