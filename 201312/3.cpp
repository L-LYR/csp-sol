// Time: 03/15/21
// Author: HammerLi
// Tags: [Monotonic Stack]
// Titile: 最大的矩形
// Content:
//      在横轴上放了n个相邻的矩形，每个矩形的宽度是1，而第i（1 <= i <= n）个矩形的高度是hi。
//      这n个矩形构成了一个直方图。例如，下图中六个矩形的高度就分别是3, 1, 6, 5, 2, 3。
//      请找出能放在给定直方图里面积最大的矩形，它的边要与坐标轴平行。
//      对于上面给出的例子，最大矩形如下图所示的阴影部分，面积是10。

#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int left[n];
  generate(left, left + n, []() { return -1; });
  int right[n];
  generate(right, right + n, [n]() { return n; });

  stack<int> stk;
  for (int i = 0; i < n; ++i) {
    while (!stk.empty() && arr[stk.top()] >= arr[i]) {
      right[stk.top()] = i;
      stk.pop();
    }
    if (!stk.empty()) {
      left[i] = stk.top();
    }
    stk.push(i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, (right[i] - left[i] - 1) * arr[i]);
  }
  cout << ans << endl;
  return 0;
}

/*
  建立两个数组来存储每一个矩形左右两侧第一个比他自己矮的。比如：
  3 1 6 5 2 3
  1 6 3 4 6 6
  -1 -1 1 1 1 4
  那么这在left[i]到right[i]的开区间的都是大于等于arr[i]的矩形，因此
  当前的面积即为(right[i] - left[i] - 1) * arr[i]。
  我们使用单调栈可以将left和right数组的获取降至O(n)。
  接着使用O(n)的比较即可。
*/