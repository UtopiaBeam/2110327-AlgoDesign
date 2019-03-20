/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Kruskal's Algorithm
 */

#include <cstdio>
#include <queue>
#include <algorithm>
#define N 5000
#define P pair<int, int>
#define PP pair<int, P>
#define F first
#define S second
using namespace std;

priority_queue<PP> hp;
P qs[N+2];
int r[N+2], ans[N+2];

int fr(int u) {
    return r[u] = (r[u] == u)? u : fr(r[u]);
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int s, e, w;
    while (m--) {
        scanf("%d %d %d", &s, &e, &w);
        hp.push( PP(-w, P(s, e)) );
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &qs[i].F);
        qs[i].S = i;
    }
    
    sort(qs, qs+q);

    int cnt = n, idx = q-1;
    for (int i = 1; i <= n; i++) {
        r[i] = i;
    }
    while ( !hp.empty() ) {
        w = -hp.top().F, s = hp.top().S.F, e = hp.top().S.S;
        hp.pop();
        int rs = fr(s), re = fr(e);
        if (rs == re)       continue;
        r[rs] = re;
        cnt--;
        if (cnt == qs[idx].F) {
            ans[qs[idx--].S] = w;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}