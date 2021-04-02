// Time: 03/26/21
// Author: HammerLi
// Tags: [Sort]
// Title: 数字排序
// Content:
// 　　给定n个整数，请统计出每个整数出现的次数，按出现次数从多到少的顺序输出。
#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  int n;
  cin >> n;
  int x;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cnt[x]++;
  }
  vector<pair<int, int>> vec(cnt.begin(), cnt.end());
  sort(vec.begin(), vec.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
    return (l.second > r.second) || (l.second == r.second && l.first < r.first);
  });
  for_each(vec.begin(), vec.end(), [](const pair<int, int>& x) {
    cout << x.first << " " << x.second << endl;
  });
  return 0;
}

/*
  排序，没啥好说的，C++11 lambda挺好。
*/