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
using namespace std;

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

template <typename IT>
 int maximum_sum_subarray(IT s, IT t) {
	int sm = 0, mx = 0;
	while (s != t){
		sm = std::max(sm, 0) + *s++;
		mx = std::max(sm, mx);
	}
	return mx;
}

int main(){
	const int n = input();
	std::map<int, std::vector<int>> dp;
	rep(i,0,n){
	rep(j,0,n){
		dp[i - j].push_back(input());
	}}
	int mx = -1e9;
	for (auto pii: dp){
		mx = std::max(mx, maximum_sum_subarray(all(pii.second)));
		//~ cout << k << ":\t" << maximum_sum_subarray(all(v)) << '\t' << v << '\n';
	}
	std::cout << mx;
}
