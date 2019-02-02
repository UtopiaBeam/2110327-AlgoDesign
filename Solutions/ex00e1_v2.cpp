/*
 * AUTHOR: Krist Pornpairin
 * KEYWORD: 
 */

#include <iostream>
using namespace std;
typedef std::pair<int,int> pii;
int input(){int i; std::cin >> i; return i;}

int main() {
	cin.sync_with_stdio(0);
	int h = input();
	int m = input();
	int t = input();
	m += t;
	h += m / 60;
	printf("%02d %02d", h % 24, m % 60);
}
