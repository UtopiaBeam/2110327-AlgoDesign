/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <algorithm>
#define N 100
#define INF (int)1e9
using namespace std;

int a[N+2][N+2];
int r, c, q;

int main() {
    scanf("%d %d", &r, &c);
    scanf("%d", &q);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int r1, c1, r2, c2;
    while (q--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if (r1 > r2 || c1 > c2) {
            printf("INVALID\n");
        }
        else if (r1 > r || c1 > c || r2 < 1 || c2 < 1) {
            printf("OUTSIDE\n");
        } else {
            int tmp = -INF;
            for (int i = max(0, r1); i <= min(r2, r); i++) {
                for (int j = max(0, c1); j <= min(c2, c); j++) {
                    tmp = max(tmp, a[i][j]);
                }
            }

            printf("%d\n", tmp);
        }
    }
    return 0;
}