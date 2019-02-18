/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define N (int)1e6
#define M (int)1e6
using namespace std;

map<int, int> mp[N+2];      // (user, price)
int amn[N+2];
vector<int> ans[M+2];

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", amn+i);
    }
    
    while (q--) {
        char op;
        int u, i, v;

        scanf(" %c", &op);
        if (op == 'B') {
            scanf("%d %d %d", &u, &i, &v);
            mp[i][u] = v;
        } else {
            scanf("%d %d", &u, &i);
            mp[i].erase(u);
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<P> v;
        for (P p: mp[i]) {
            v.push_back(P(-p.S, -p.F));
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < amn[i] && j < v.size(); j++) {
            ans[ -v[j].S ].push_back(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i].empty()) {
            printf("NONE\n");
        } else {
            for (int &x: ans[i]) {
                printf("%d ", x);
            }
            printf("\n");
        }
    }
    return 0;
}