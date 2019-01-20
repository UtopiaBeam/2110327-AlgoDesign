// AUTHOR: Rodchananat Khunakornophat
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[50001];
int cnt[50001][500], ans = 0, n, k, p, q;
void recur(int n) {
    cnt[n][0] = 1;
    vector<int> &v = adj[n];
    for (int &x : adj[n]) {
        recur(x);
        for (int i = 0; cnt[x][i] != 0; ++i)
            cnt[n][i+1] += cnt[x][i];
    }

    int l = v.size() >= 1 ? v[0] : 0;
    int r = v.size() >= 2 ? v[1] : 0;
    for (int i = 0; i <= k-2; ++i)
        ans += cnt[l][i] * cnt[r][k-i-2];
        
    ans += cnt[l][k-1] + cnt[r][k-1];
}
int main() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> p >> q;
        adj[p].push_back(q);
    }
    recur(1);
    cout << ans;
    return 0;
}