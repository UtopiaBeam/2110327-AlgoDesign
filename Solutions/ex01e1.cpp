/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <iostream>
#include <unordered_map>
#define N (int)1e5
using namespace std;

unordered_map<int, int> mp;
int a[N+2];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[ a[i] ]++;
    }

    while(m--) {
        int q;
        bool chk = false;
        cin >> q;
        for(int i = 0; i < n; i++) {
            if(chk)     break;
            mp[ a[i] ]--;
            if(mp[ q-a[i] ] > 0)
                chk = true;
            mp[ a[i] ]++;
        }
        cout << (chk? "YES\n":"NO\n");
    }
    return 0;
}