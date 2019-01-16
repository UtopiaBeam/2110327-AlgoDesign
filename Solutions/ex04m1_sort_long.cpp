// AUTHOR: Rodchananat Khunakornophat
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100010], b[100010];
int m[4][4];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int lp = 0, rp = n - 1;
    // sorting -- actually didn't have to optimize to sort in O(n)
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            b[lp++] = 1;
        else if (a[i] == 3)
            b[rp--] = 3;
    }
    for (int i = lp; i <= rp; i++)
        b[i] = 2;

    // m[number][correct_number]
    for (int i = 0; i < n; i++)
        m[a[i]][b[i]]++;
    int ans = 0;
    int t;
    // Greedy Swap
    t = min(m[1][2], m[2][1]);
    m[1][2] -= t;
    m[2][1] -= t;
    ans += t;
    t = min(m[2][3], m[3][2]);
    m[2][3] -= t;
    m[3][2] -= t;
    ans += t;
    t = min(m[3][1], m[1][3]);
    m[3][1] -= t;
    m[1][3] -= t;
    ans += t;
    // for 3 "invalid" number, it took 2 moves to correct
    // EX [3, 1, 2] => [2, 1, 3] => [1, 2, 3]
    // hence there is 2/2 multiplier
    ans += (m[1][2] + m[2][1] + m[3][1] + m[1][3] + m[2][3] + m[3][2]) * 2 / 3;
    printf("%d\n", ans);
    return 0;
}