/*
 * AUTHOR: Krist Pornpairin
 * KEYWORD: 
 */

#include <bits/stdc++.h>
//~ #include <iostream>
//~ #include <vector>
//~ #include <map>
//~ #include <iterator>
#define input() (*std::istream_iterator<int>(cin))
#define len(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i,k,n) for (auto i = k; i != n; ++i)
#define loop(i, n) for (auto i = n; i--;)
#define fi first
#define se second
using namespace std;
typedef std::pair<int,int> pii;

template <typename T>
 std::ostream& operator << (std::ostream& o, const std::vector<T>& v){
	o << '[';
	for (uint i = 0; i != v.size(); ++i){
		o << v[i];
		if (i + 1 != v.size()){
			o << ", ";
	}}
	o << ']';
	return o;
}

int main(){
	const int n = input();
	std::vector<pii> inp(n);
	rep(i,0,n){
		inp[i].fi = input();
		inp[i].se = input();
	}
	std::sort(all(inp));
	std::vector<int> stk;
	for (pii p: inp){
		int r = p.second;
		while (not stk.empty() and r > stk.back()){
			stk.pop_back();
		}
		stk.push_back(r);
		//~ cout << l << ' ' << r << ' ' << stk << '\n';
	}
	cout << stk.size();
	
}
