/*
 * AUTHOR: Krist Pornpairin
 * KEYWORD: 
 */

#include <iostream>
#include <queue>
using namespace std;
typedef std::pair<int,int> pii;
int input(){int i; std::cin >> i; return i;}

int main() {
	cin.sync_with_stdio(0);
	std::priority_queue<pii> pq; // [time, add]
	int n = input();
	int m = input();
	while (n--){
		pq.emplace(0, input());
	}
	while (m--){
		pii top = pq.top();
		pq.pop();
		printf("%d\n", -top.first);
		pq.emplace(top.first - top.second, top.second);	
	}
}