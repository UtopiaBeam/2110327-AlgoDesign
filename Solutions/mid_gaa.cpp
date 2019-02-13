/*
 * AUTHOR: Natchapol Srisang (UtopiaBeam)
 */
#include <cstdio>
#include <vector>
#define L long long
using namespace std;

vector<L> l;

char g(L n, int sz) {
    if (sz == 0) {
        return (n == 1)? 'g' : 'a';
    }
    if (n <= l[sz-1]) {
        return g(n, sz-1);
    } else if (n <= l[sz-1] + sz+3) {;
        return (n-l[sz-1] == 1)? 'g' : 'a';
    } else {
        return g(n-l[sz-1]-sz-3, sz-1);
    }
}

int main() {
    l.push_back(3);
    for (int i = 1; l.back() <= (L)1e9; i++) {
        l.push_back(2*l.back() + i+3);
    }

    L n;
    scanf("%lld", &n);
    printf("%c\n", g(n, l.size()));
    return 0;
}