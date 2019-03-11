/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <vector>
#include <queue>
#define N 50
#define P pair<int, int>
#define F first
#define S second
using namespace std;

vector<int> g[N+2];
queue<P> q;
int cr[N+2];
int cnt = 1;

void bfs(int u, int c) {
    q.push( P(u, c) );
    while ( !q.empty() ) {
        u = q.front().F, c = q.front().S;
        q.pop();
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
    for (int i = 0; i < n; i++) {
        if (cr[i] == 0) {
            bfs(i, 1);
        }
    }
    return 0;
}