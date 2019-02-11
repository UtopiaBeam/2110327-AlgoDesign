/*
 * AUTHOR: Krist Pornpairin
 * KEYWORD: 
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cassert>
#define input [] {int i; std::cin >> i; return i; }
#define rep(i, k, n) for (auto i = k; i != n; ++i)
#define all(x) x.begin(), x.end()
typedef std::pair<int,int> pii;
typedef std::vector<int> Vec;

void printrange(int s, int t) {
  while (s != t) std::cout << s++ << ' ';
}

void makemerge(int s, int t, int& k, Vec& v) {
  assert(k % 2 == 0);
  if (s == t) {
    return;
  } else if (s + 1 == t) {
    v.push_back(s);
  } else if (k == 0) { // forward
    while (s != t) {
      v.push_back(s++);
    }
  } else if (k >= 2) { // backward
    int m = (s + t + 1) / 2;
    k -= 2;
    makemerge(m, t, k, v); // right
    makemerge(s, m, k, v); // left
  }
}

Vec makemerge(int n, int k) {
  k -= 1;
  Vec ans;
  if (k >= n * 2 || k < 0 || (k & 1)) {
    return ans;
  }
  makemerge(1, n + 1, k, ans);
  return ans;
}


int checkmerge(Vec::iterator l, Vec::iterator r) {
  if (l == r) return 0;
  if (std::is_sorted(l, r)) return 1;
  auto m = l + std::distance(l, r) / 2;
  int cl = checkmerge(l, m);
  int cr = checkmerge(m, r);
  std::sort(l, r);
  return 1 + cl + cr;
}
int checkmerge(Vec v) {
  return checkmerge(all(v));
}

int main() {
  int n = input();
  int k = input();
  Vec ans = makemerge(n, k);
  if (std::count(all(ans), -1) || ans.size() != n) {
    std::cout << -1;
  } else {
    for (int i : ans) std::cout << i << ' ';
    std::cout << '\n';
    // std::cerr << checkmerge(ans);
  }
}