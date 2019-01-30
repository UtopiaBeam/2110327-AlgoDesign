/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <iostream>
#include <algorithm>
#define N 500
using namespace std;

string a, b;
int dp[N+2][N+2];

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}