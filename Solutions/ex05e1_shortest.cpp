/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <queue>
#define N 100
#define INF 1<<30
using namespace std;

struct S {
    int x, y, d;
    S() {}
    S(int x, int y, int d): x(x), y(y), d(d) {}
};

char a[N+2][N+2];
int r, c;
int mn[N+2][N+2];
queue<S> q;

void bfs(int x, int y) {
    q.push( S(x, y, 0) );
    while ( !q.empty() ) {
        S nw = q.front();
        int x = nw.x, y = nw.y, d = nw.d;
        q.pop();
        if (mn[x][y] <= d || a[x][y] == '#')
            continue;
        mn[x][y] = d;

        int ch[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int nx = x+ch[i][0], ny = y+ch[i][1];
            if (nx < 1 || ny < 1 || nx > r || ny > c)
                continue;
            q.push( S(nx, ny, d+1) );
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf(" %s", &a[i][1]);
        for (int j = 1; j <= c; j++) {
            mn[i][j] = INF;
        }
    }

    bfs(1, 1);

    printf("%d\n", mn[r][c] == INF? -1 : mn[r][c]);
    return 0;
}