// Time: 03/19/21
// Author: HammerLi
// Tags: [Simulation][Sort]
// Titile: 相邻数对
// Content:
//      给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n;
  cin >> n;
  int nums[n];
  int ans = 0;
  for (int i = 0; i < n; ++i) cin >> nums[i];
  sort(nums, nums + n);
  for (int i = 1; i < n; ++i) {
    if (nums[i] - nums[i - 1] == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}

/*
  输入，排序，统计。
  或者用hash也可。
*/