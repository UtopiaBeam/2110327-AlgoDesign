// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
unordered_map<int, vector<pii> > cnt;
int found[1000], a[1000];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);

	int sum;
	for (int i=0; i<m; i++){ 
		scanf("%d", &sum);
		for (int j=0; j<n; j++){
			cnt[sum-a[j]].push_back(pii(i, j)); // questionID, usedNumberIndex
		}
	}
	int qID, idx;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++){
			if (cnt.find(a[i] + a[j]) != cnt.end()){ // possible
				for (pii x: cnt[a[i] + a[j]]){
					qID = x.first, idx = x.second;
					if (idx != i && idx != j){
						found[qID] = 1;
					}
				}
			}
		}
	for (int i=0; i<m; i++)
		printf("%s\n", found[i]?"YES":"NO");
	return 0;
}