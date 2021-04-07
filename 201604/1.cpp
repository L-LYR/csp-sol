// Time: 04/07/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 折点计数
// Content:
//      给定n个整数表示一个商店连续n天的销售量。如果某天之前销售量在增长，而后一天销售量减少，
//      则称这一天为折点，反过来如果之前销售量减少而后一天销售量增长，
//      也称这一天为折点。其他的天都不是折点。如下图中，第3天和第6天是折点。
//      给定n个整数a1, a2, …, an表示销售量，请计算出这些天总共有多少个折点。
//      为了减少歧义，我们给定的数据保证：在这n天中相邻两天的销售量总是不同的，即ai - 1 != ai。注意，如果两天不相邻，销售量可能相同。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n;
  cin >> n;
  int pprev, prev, cur;
  int cnt = 0;
  cin >> pprev >> prev;
  for (int i = 2; i < n; ++i) {
    cin >> cur;
    if (pprev > prev && prev < cur) {
      cnt++;
    } else if (pprev < prev && prev > cur) {
      cnt++;
    }
    pprev = prev;
    prev = cur;
  }
  cout << cnt << endl;
  return 0;
}
/*
  从输入来统计即可。
*/