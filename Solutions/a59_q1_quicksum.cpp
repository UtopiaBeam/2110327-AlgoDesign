#include <cstdio>
#define N 1000

int a[N+2][N+2];

int main() {
    int r, c, q;
    scanf("%d %d %d", &r, &c, &q);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    int sx, sy, ex, ey;
    while (q--) {
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        printf("%d\n", a[ex+1][ey+1] - a[sx][ey+1] - a[ex+1][sy] + a[sx][sy]);
    }

    return 0;
}