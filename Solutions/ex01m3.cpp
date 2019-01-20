// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
#define LL long long
int n, q, a[1000];
LL num(LL tm) {
    LL sum = n;
    for (int i = 0; i < n; ++i)
        sum += tm / a[i];
    return sum;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    LL l, m, h, c;
    while (q--) {
        scanf("%lld", &c);
        l = 0, h = 1e16;
        while (l < h) {
            m = (l + h) / 2;
            num(m) < c ? l = m + 1 : h = m;
        }
        printf("%lld\n", l);
    }
    return 0;
}