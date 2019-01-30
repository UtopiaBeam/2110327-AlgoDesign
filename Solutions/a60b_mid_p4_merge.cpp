/* 
 * AUTHOR: Rodchananat Khunakornophat
 */
#include <cstdio>
int k;

void recur(int l, int r) {
    if (l == r) {
        printf("%d ", l);
        return;
    }
    int m = (l+r) / 2;
    if (k) {
        --k;
        recur(m+1, r);
        recur(l, m);
    } else {
        recur(l, m);
        recur(m+1, r);
    }
}

int main() {
    int n;
    scanf("%d%d", &n, &k);
    /* 
     * Why? Think of a function call tree, # of nodes is # of calls
     * if there is `m` leave nodes (already sorted array), there will
     * be m-1 internal nodes, because it's full binary tree.
     * There will be at most n leaves so there will be at most
     * 2n-1 nodes (function calls)  
     */
    if (k % 2 == 0 || k > 2*n-1) {
        printf("-1");
        return 0;
    }
    k = (k-1) / 2;
    recur(1, n);
    return 0;
}