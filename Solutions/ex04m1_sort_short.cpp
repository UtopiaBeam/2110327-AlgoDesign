// AUTHOR: Rodchananat Khunakornophat
#include <algorithm>
#include <cstdio>
using namespace std;
#define M(a, b) min(m[a][b], m[b][a])
// q is number of integers(1,2,3) that is "invalid" position
int m[4][4], i, n, q = 0, s;
int main() {
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (i = 0; i < n; i++) {
        m[a[i]][b[i]]++;
        q += (a[i] != b[i]);
    }
    // this formula is based on the "long" solution (just prove it 4Head)
    s = M(1, 2) + M(2, 3) + M(3, 1);
    printf("%d\n", (q + s) * 2 / 3 - s);
    return 0;
}