/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */

#include <cstdio>
#include <algorithm>
#define INF (1<<30)

int main() {
    int n;
    scanf("%d", &n);
    int sum = -INF, mx = -INF;
    while (n--) {
        int t;
        scanf("%d", &t);
        sum = std::max(sum+t, t);
        mx = std::max(sum, mx);
    }
    printf("%d\n", mx);
    return 0;
}