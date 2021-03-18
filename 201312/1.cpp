// Time: 03/15/21
// Author: HammerLi
// Tags: [Simulation]
// Titile: 出现次数最多的数
// Content:
//      给定n个正整数，找出它们中出现次数最多的数。
//      如果这样的数有多个，请输出其中最小的一个。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n, x;
  unordered_map<int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cnt[x]++;
  }
  int maxVal = 0, maxCnt = 0;
  for (auto& p : cnt) {
    if (p.second > maxCnt) {
      maxVal = p.first;
      maxCnt = p.second;
    } else if (p.second == maxCnt && p.first < maxVal) {
      maxVal = p.first;
    }
  }
  cout << maxVal << endl;
  return 0;
}

/*
  解法比较简单，输入时统计，再进行比较选择即可。
*/