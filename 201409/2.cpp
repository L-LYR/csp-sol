// Time: 03/19/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 画图
// Content:
//      在一个定义了直角坐标系的纸上，画一个(x1,y1)到(x2,y2)的矩形指将横坐标范围从x1到x2，纵坐标范围从y1到y2之间的区域涂上颜色。
//      下图给出了一个画了两个矩形的例子。第一个矩形是(1, 1) 到(4, 4) ，用绿色和紫色表示。
//      第二个矩形是(2, 3) 到(6, 5) ，用蓝色和紫色表示。图中，一共有15个单位的面积被涂上颜色，其中紫色部分被涂了两次，
//      但在计算面积时只计算一次。在实际的涂色过程中，所有的矩形都涂成统一的颜色，图中显示不同颜色仅为说明方便。
//      给出所有要画的矩形，请问总共有多少个单位的面积被涂上颜色。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;

bool pad[maxn][maxn];

auto main() -> int {
  int n;
  cin >> n;
  int lx, ly, rx, ry;
  for (int i = 0; i < n; ++i) {
    cin >> lx >> ly >> rx >> ry;
    for (int j = lx; j < rx; ++j) {
      for (int k = ly; k < ry; ++k) {
        pad[j][k] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      if (pad[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

/*
  简单模拟，不用怕超时。
*/