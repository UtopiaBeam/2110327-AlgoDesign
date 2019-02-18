/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <cstdio>
#include <cmath>

int f(int n, int l, int r) {
    if (l > r)          return 0;
    if (n <= 1)         return n;
    
    // 1 << n = 2^n
    int m = 1 << (int)log2(n);
    if (r < m) {
        return f(n/2, l, r);
    } else if (l > m) {
        return f(n/2, l-m, r-m);
    } else {
        return f(n/2, l, m-1) + n%2 + f(n/2, 1, r-m);
    }
}

int main() {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    printf("%d\n", f(n, l, r));
    return 0;
}