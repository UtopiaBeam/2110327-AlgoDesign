#include <cstdio>
#define N (int)1e5
#define L long long

int a[N+2], t[N+2];

L mrg(int s, int m, int e) {
    int l = s, r = m+1;
    L cnt = 0;
    for (int i = s; i <= e; i++) {
        if (l > m)      t[i] = a[r++];
        else if (r > e) t[i] = a[l++];
        else if (a[l] <= a[r]) {
            t[i] = a[l++];
        } else {
            cnt += m-l+1;
            t[i] = a[r++];
        }
    }
    for (int i = s; i <= e; i++) {
        a[i] = t[i];
    }
    return cnt;
}

L inv(int s, int e) {
    if (s >= e)     return 0;
    int m = (s+e)/2;
    return inv(s, m) + inv(m+1, e) + mrg(s, m, e);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }

    printf("%lld\n", inv(1, n));
    return 0;
}