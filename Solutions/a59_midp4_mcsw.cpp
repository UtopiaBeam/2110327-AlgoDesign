/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define INF (int)1e9
using namespace std;

priority_queue<P> hp;

int main() {
    int n, w, x;
    int ans = -INF, sum = 0;

    scanf("%d %d", &n, &w);
    hp.push( P(0, 0) );
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        sum += x;
        while (!hp.empty() && hp.top().S <= i-w) {
            hp.pop();
        }
        ans = max(ans, sum + hp.top().F);
        hp.push( P(-sum, i) );
    }

    printf("%d\n", ans);
    return 0;
}