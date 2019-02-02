/*
 * AUTHOR: Krist Pornpairin
 * KEYWORD: 
 */

#include <bits/stdc++.h>
#define input() (*std::istream_iterator<int>(cin))
#define len(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i,k,n) for (auto i = k; i != n; ++i)
#define loop(i, n) for (auto i = n; i--;)
#define fi first
#define se second
using namespace std;

int main() {
	const int n = input();
	const int m = input();
	std::vector<int> inp(n);
	rep(i,0,n) {
		inp[i] = input();
	}
	std::sort(all(inp));
	std::map<int, std::set<int>> mp;
	rep(i,0,n){
	rep(j,0,i){
		auto& s = mp[inp[i] + inp[j]];
		s.insert(i);	
		s.insert(j);	
	}}
	loop(_, m){
		int val = input();
		bool found = false;
		rep(k,0,n){
			auto it = mp.find(val - inp[k]);
			if (it != mp.end() and (len(it->second) > 2 or not it->second.count(k))){
				found = true;
				break;
		}}
		::puts(found ? "YES" : "NO");
	}
}
