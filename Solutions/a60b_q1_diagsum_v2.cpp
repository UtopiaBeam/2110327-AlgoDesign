/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <iostream>
#include <algorithm>
#define N 1000
#define INF_MIN -1<<30
using namespace std;

int a[N+2][N+2];
int n, ans = INF_MIN;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[i][j] += a[i-1][j-1];
            for(int k = 1; k <= min(i, j); k++)
                ans = max(ans, a[i][j]-a[i-k][j-k]);
        }
    }

    cout << ans << '\n';
    return 0;
}