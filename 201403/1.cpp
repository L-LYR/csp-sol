// Time: 03/18/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 相反数
// Content:
//　　有 N 个非零且各不相同的整数。请你编一个程序求出它们中有多少对相反数(a 和 -a 为一对相反数)。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n;
  cin >> n;
  unordered_set<int> ns;
  int x;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ns.insert(x);
    if (ns.count(-x)) ans++;
  }
  cout << ans << endl;

  return 0;
}