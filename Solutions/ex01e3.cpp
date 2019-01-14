#include <cstdio>
#define N (int)1e5

int a[N+2] = {-1};

int bs(int s, int e, int k) {
    if (s == e)     return a[s];
    int m = (s+e+1) / 2;
    if (k < a[m])  return bs(s, m-1, k);
    return bs(m, e, k);
}

int main() {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }
    while (m--) {
        scanf("%d", &t);
        printf("%d\n", bs(0, n, t));
    }
}