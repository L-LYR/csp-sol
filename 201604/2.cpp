// Time: 04/07/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 俄罗斯方块
// Content:
//      俄罗斯方块是俄罗斯人阿列克谢·帕基特诺夫发明的一款休闲游戏。
//      游戏在一个15行10列的方格图上进行，方格图上的每一个格子可能已经放置了方块，或者没有放置方块。
//      每一轮，都会有一个新的由4个小方块组成的板块从方格图的上方落下，玩家可以操作板块左右移动放到合适的位置，
//      当板块中某一个方块的下边缘与方格图上的方块上边缘重合或者达到下边界时，
//      板块不再移动，如果此时方格图的某一行全放满了方块，则该行被消除并得分。
//      在这个问题中，你需要写一个程序来模拟板块下落，你不需要处理玩家的操作，也不需要处理消行和得分。
//      具体的，给定一个初始的方格图，以及一个板块的形状和它下落的初始位置，你要给出最终的方格图。
#include <bits/stdc++.h>
using namespace std;
const int maxr = 15;
const int maxc = 10;
const int maxn = 4;
int g[maxr + 1][maxc];  // graph
set<pair<int, int>> block;
auto main() -> int {
  for (int i = 0; i < maxr; ++i) {
    for (int j = 0; j < maxc; ++j) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < maxc; ++i) g[maxr][i] = 1;  // set an extra line
  int x;                                          // coordinate x;
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      cin >> x;
      if (x == 1) {
        block.emplace(i, j);
      }
    }
  }
  cin >> x;
  x--;
  int row = 0;
  bool reach = false;
  while (!reach) {
    row++;
    for (const auto& b : block) {
      int bx = row + b.first;
      int by = x + b.second;
      if (g[bx][by] == 1) {
        reach = true;
        break;
      }
    }
  }
  row--;
  for (const auto& b : block) {
    int bx = row + b.first;
    int by = x + b.second;
    g[bx][by] = 1;
  }
  for (int i = 0; i < maxr; ++i) {
    for (int j = 0; j < maxc; ++j) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

/*
  模拟游戏即可，从上往下。
*/