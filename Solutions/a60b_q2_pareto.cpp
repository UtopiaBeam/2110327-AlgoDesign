// AUTHOR: Rodchananat Khunakornophat
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

vector<pair<int, int>> points;
stack<int> st;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n;
    pair<int, int> thisPoint;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &thisPoint.first, &thisPoint.second);
        points.push_back(thisPoint);
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) {
        int y = points[i].second;
        while (!st.empty() && st.top() <= y) {
            st.pop();
        }
        st.push(y);
    }
    printf("%d\n", st.size());
    return 0;
}