/*
* AUTHOR: Natchapol Srisang(UtopiaBeam)
* KEYWORD: Dijkstra's Algorithm
*/

#include <cstdio>
#include <queue>
#include <vector>
#define N (int)5e4
#define INF 1<<30
using namespace std;

struct Node {
    int d, x, y;
    Node(): d(0), x(0), y(0) {}
    Node(int d, int x, int y): d(d), x(x), y(y) {}
    bool operator< (const Node &o) const {
        return d > o.d;
    }
};

priority_queue<Node> hp;
vector<vector<int> > v, ans;
int r, c;

int main() {
    scanf("%d %d", &r, &c);
    v.resize(r, vector<int>(c));
    ans.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &v[i][j]);
            ans[i][j] = INF;
        }
    }

    hp.push(Node());
    while ( !hp.empty() ) {
        Node nw = hp.top();
        hp.pop();
        int d = nw.d, x = nw.x, y = nw.y;
        if (ans[x][y] < d)
            continue;
        ans[x][y] = d;
        int s[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < 4; i++) {
            int nx = x+s[i][0], ny = y+s[i][1];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (d + v[nx][ny] < ans[nx][ny]) {
                hp.push( Node(d+v[nx][ny], nx, ny) );
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
