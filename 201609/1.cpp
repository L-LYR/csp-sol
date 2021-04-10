// Time: 04/09/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 最大波动
// Content:
//      小明正在利用股票的波动程度来研究股票。小明拿到了一只股票每天收盘时的价格，他想知道，
//      这只股票连续几天的最大波动值是多少，即在这几天中某天收盘价格与前一天收盘价格之差的绝对值最大是多少。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n, prev, cur, ans = 0;
  cin >> n;
  cin >> prev;
  for (int i = 1; i < n; ++i) {
    cin >> cur;
    ans = max(abs(cur - prev), ans);
    prev = cur;
  }
  cout << ans << endl;
  return 0;
}
/*
  简单模拟
*/