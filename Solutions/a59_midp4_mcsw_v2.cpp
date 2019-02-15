/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 * KEYWORD: Sliding window minimum
 */
#include <cstdio>
#include <deque>
#include <algorithm>
#define P pair<int, int>
#define F first
#define S second
#define INF (int)1e9
using namespace std;

deque<P> dq;

int main() {
    int n, w, x;
    int ans = -INF, sum = 0;

    scanf("%d %d", &n, &w);
    dq.push_back( P(0, 0) );
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        sum += x;
        while (!dq.empty() && dq.front().S <= i-w) {
            dq.pop_front();
        }
        ans = max(ans, sum - dq.front().F);
        while (!dq.empty() && dq.back().F > sum) {
            dq.pop_back();
        }
        dq.push_back( P(sum, i) );
    }

    printf("%d\n", ans);
    return 0;
}