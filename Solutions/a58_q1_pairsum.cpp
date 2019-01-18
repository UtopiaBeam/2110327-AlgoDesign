// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
#include <set>
#include <unordered_map>
using namespace std;

unordered_map<int, int> count;
int a[100000];

int main(){
	// freopen("test.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
		count[a[i]] += 1;
	}

	int sum, found;
	while (m--){
		found = 0;
		scanf("%d", &sum);
		for (int i=0; i<n; i++){
			if (a[i]*2 == sum && count[a[i]] >= 2 ||
				a[i]*2 != sum && count[sum-a[i]] >= 1) {
				found = 1;
				break;
			}
		}
		printf(found?"YES\n":"NO\n");
	}
	return 0;
}