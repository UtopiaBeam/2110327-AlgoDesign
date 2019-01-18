// Golomb Sequence
#include <cstdio>
#include <vector>
#define L long long
using namespace std;

vector<L> v;
vector<int> seq = {0, 1};

int main() {
    L idx = 1;
    for (int i = 1; idx <= (L)4e9; i++) {
        v.push_back(idx);
        idx += seq[i];
        seq.push_back(1 + seq[i+1 - seq[seq[i]]]);
    }

    int n;
    L t;

    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &t);
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > t) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}