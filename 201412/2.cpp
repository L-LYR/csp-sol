// Time: 03/22/21
// Author: HammerLi
// Tags: [Simulation]
// Titile: Z字形扫描
// Content:
//      在图像编码的算法中，需要将一个给定的方形矩阵进行Z字形扫描(Zigzag Scan)。
//      给定一个n×n的矩阵，Z字形扫描的过程如下图所示：
//      对于下面的4×4的矩阵，
//              1 5 3 9
//              3 7 5 6
//              9 4 6 4
//              7 3 1 3
//      对其进行Z字形扫描后得到长度为16的序列：
//              1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3
//      请实现一个Z字形扫描的程序，给定一个n×n的矩阵，输出对这个矩阵进行Z字形扫描的结果。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 501;
int m[maxn][maxn];
auto main(void) -> int {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> m[i][j];
    }
  }
  int d = 1;
  for (int i = 0; i <= 2 * n; ++i) {
    int j = (d == 1) ? i : 0;
    int k = i - j;
    while (k >= 0 && j >= 0) {
      if (k < n && j < n)
        cout << m[j][k] << " ";
      j -= d;
      k += d;
    }
    d = -d;
  }

  return 0;
}