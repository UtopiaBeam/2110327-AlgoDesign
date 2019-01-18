// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
int isCel[1000];

int main() {
    int n, i, j, t, q = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        isCel[i] = 1;
        
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &t);
            if (i == j) continue;
            isCel[i] &= 1 - t;
            isCel[j] &= t;
        }
    }
    for (i = 0; i < n; ++i) 
        if (isCel[i]) q = i + 1;

    printf("%d", q);
    return 0;
}