/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Segment tree
 */

#include <cstdio>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define N (int)1e5
#define INF (1<<30)
using namespace std;

P st[2*N+2];
int n, m;

void build() {
    for (int i = 0; i < n; i++) {
        st[i+n] = P(i, i);
    }
    for (int i = n-1; i > 0; i--) {
        st[i] = P(min(st[i<<1].F, st[i<<1|1].F), max(st[i<<1].S, st[i<<1|1].S));
    }
}

P query(int l, int r) {
    int mn = INF, mx = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            mn = min(mn, st[l].F);
            mx = max(mx, st[l++].S);
        }
        if (r & 1) {
            mn = min(mn, st[--r].F);
            mx = max(mx, st[r].S);
        }
    }
    return P(mn, mx);
}

void update(int p) {
    for (p += n; p > 1; p >>= 1) {
        st[p>>1] = P(min(st[p].F, st[p^1].F), max(st[p].S, st[p^1].S));
    }
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &m);
        build();
        while (m--) {
            int op, s, e;
            scanf("%d %d %d", &op, &s, &e);
            if (op == 0) {
                swap(st[s+n], st[e+n]);
                update(s);      update(e);
            } else {
                printf(query(s, e+1) == P(s, e)? "YES\n" : "NO\n");
            }
        }
    }
}