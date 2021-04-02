// Time: 03/26/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 图像旋转
// Content:
// 　　旋转是图像处理的基本操作，在这个问题中，你需要将一个图像逆时针旋转90度。
// 　　计算机中的图像表示可以用一个矩阵来表示，为了旋转一个图像，只需要将对应的矩阵旋转即可。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n, m;
  cin >> n >> m;
  int mat[m][n];
  for (int i = 0; i < n; ++i) {
    for (int j = m - 1; j >= 0; --j) {
      cin >> mat[j][i];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
  修改遍历方法或者存储顺序。
*/