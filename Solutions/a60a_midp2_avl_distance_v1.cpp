// AUTHOR: Rodchananat Khunakornophat
#include <bits/stdc++.h>
#define CNT(i, j) ((j>24)?0:cnt[i][j])
using namespace std;
vector<int> adj[50001];
// max height of AVL with 50000 nodes is 22
int cnt[50001][25];

void count_nodes(int node) {
    cnt[node][0] = 1;
    for (int &x : adj[node]) {
        count_nodes(x);
        for (int i = 0; i < 24 && cnt[x][i] != 0; ++i)
            cnt[node][i+1] += cnt[x][i];
    }
}
int main() {
    int n, k, p, q, ans = 0;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> p >> q;
        adj[p].push_back(q);
    }
    count_nodes(1);
    // make all node have 2 leaves
    for (int i = 1; i <= n; ++i)
        while (adj[i].size() < 2) adj[i].push_back(0);
    
    int l, r;
    for (int i = 1; i <= n; ++i) {
        l = adj[i][0];
        r = adj[i][1];
        for (int j = 0; j <= k-2; ++j) 
            ans += CNT(l, j) * CNT(r, k-j-2);
        
        ans += CNT(l, k-1) + CNT(r, k-1);
    }
    cout << ans;
    return 0;
}