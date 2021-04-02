// Time: 04/01/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 数列分段
// Content:
// 　　给定一个整数数列，数列中连续相同的最长整数序列算成一段，问数列中共有多少段？
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n;
  cin >> n;
  int cur, pre = -1, cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> cur;
    if (cur != pre) {
      cnt++;
      pre = cur;
    }
  }
  cout << cnt << endl;
  return 0;
}

/*
  简单计数
*/