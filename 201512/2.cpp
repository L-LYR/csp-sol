// Time: 04/04/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 消除类游戏
// Content:
//      消除类游戏是深受大众欢迎的一种游戏，游戏在一个包含有n行m列的游戏棋盘上进行，
//      棋盘的每一行每一列的方格上放着一个有颜色的棋子，当一行或一列上有连续三个或更多的相同颜色的棋子时，
//      这些棋子都被消除。当有多处可以被消除时，这些地方的棋子将同时被消除。
//      现在给你一个n行m列的棋盘，棋盘中的每一个方格上有一个棋子，请给出经过一次消除后的棋盘。
//      请注意：一个棋子可能在某一行和某一列同时被消除。
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  int n, m;
  cin >> n >> m;
  int in[n][m];
  bool mark[n][m];
  memset(mark, false, sizeof(mark));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> in[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 2; ++j) {
      if (in[i][j] == in[i][j + 1] && in[i][j + 1] == in[i][j + 2]) {
        mark[i][j] = mark[i][j + 1] = mark[i][j + 2] = true;
      }
    }
  }

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n - 2; ++i) {
      if (in[i][j] == in[i + 1][j] && in[i + 1][j] == in[i + 2][j]) {
        mark[i][j] = mark[i + 1][j] = mark[i + 2][j] = true;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!mark[i][j]) {
        cout << in[i][j] << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}

/*
  模拟即可，没啥好办法，数据量确实也不大
*/