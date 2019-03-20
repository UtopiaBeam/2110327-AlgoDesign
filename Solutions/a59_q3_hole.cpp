/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <queue>
#include <algorithm>
#define N 1000
#define INF 1<<30
using namespace std;

struct S {
    int x, y, d;
    S(int x, int y, int d=0): x(x), y(y), d(d) {}
};

queue<S> q;

int mp[N+2][N+2];
int cnt[N+2][N+2];

int main() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt[i][j] = INF;
        }
    }

    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    q.push( S(x, y) );
    while (n--) {
        scanf("%d %d", &x, &y);
        mp[x][y] = 1;
    }

    while ( !q.empty() ) {
        S nw = q.front();
        q.pop();
        int x = nw.x, y = nw.y, d = nw.d;
        if (cnt[x][y] <= d)      continue;
        cnt[x][y] = d;
        int c[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int nx = x + c[i][0], ny = y + c[i][1];
            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            q.push( S(nx, ny, d+mp[nx][ny]) );
        }
    }
    int mn = INF;
    for (int i = 1; i < N; i++) {
        mn = min(mn, min(min(cnt[1][i], cnt[N][i]), min(cnt[i][1], cnt[i][N])));
    }

    printf("%d\n", mn);
    return 0;
}



