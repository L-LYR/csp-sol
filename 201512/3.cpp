// Time: 04/04/21
// Author: HammerLi
// Tags: [Simulation] [BFS]
// Title: 画图
// Content:
//       用 ASCII 字符来画图是一件有趣的事情，并形成了一门被称为 ASCII Art 的艺术。例如，下图是用 ASCII 字符画出来的 CSPRO 字样。
//       ..____.____..____..____...___..
//       ./.___/.___||.._.\|.._.\./._.\.
//       |.|...\___.\|.|_).|.|_).|.|.|.|
//       |.|___.___).|..__/|.._.<|.|_|.|
//       .\____|____/|_|...|_|.\_\\___/.
//       本题要求编程实现一个用 ASCII 字符来画图的程序，支持以下两种操作：

//       画线：给出两个端点的坐标，画一条连接这两个端点的线段。简便起见题目保证要画的每条线段都是水平或者竖直的。
//       水平线段用字符 - 来画，竖直线段用字符 | 来画。如果一条水平线段和一条竖直线段在某个位置相交，则相交位置用字符 + 代替。

//       填充：给出填充的起始位置坐标和需要填充的字符，从起始位置开始，用该字符填充相邻位置，直到遇到画布边缘或已经画好的线段。
//       注意这里的相邻位置只需要考虑上下左右 4 个方向，如下图所示，字符 @ 只和 4 个字符 * 相邻。

//       .*.
//       *@*
//       .*.
#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
const int maxn = 103;
char g[maxn][maxn];
bool vis[maxn][maxn];
int n, m, q, op;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

auto fill_from(int x, int y, char c) -> void {
  memset(vis, false, sizeof(vis));
  queue<Point> q;
  q.push({x, y});
  vis[x][y] = true;
  while (!q.empty()) {
    auto cur = q.front();

    q.pop();

    g[cur.first][cur.second] = c;

    for (int i = 0; i < 4; ++i) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (vis[nx][ny]) continue;
      if (g[nx][ny] == '-' || g[nx][ny] == '|' || g[nx][ny] == '+') continue;
      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

auto draw(int x1, int y1, int x2, int y2) -> void {
  if (y1 == y2) {
    auto r = minmax(x1, x2);
    for (int i = r.first; i <= r.second; ++i) {
      if (g[y1][i] == '|' || g[y1][i] == '+') {
        g[y1][i] = '+';
      } else {
        g[y1][i] = '-';
      }
    }
  } else if (x1 == x2) {
    auto r = minmax(y1, y2);
    for (int i = r.first; i <= r.second; ++i) {
      if (g[i][x1] == '-' || g[i][x1] == '+') {
        g[i][x1] = '+';
      } else {
        g[i][x1] = '|';
      }
    }
  }
}

auto main() -> int {
  cin >> m >> n >> q;
  memset(g, '.', sizeof(g));
  for (int i = 0; i < q; ++i) {
    cin >> op;
    if (op == 1) {
      int x, y;
      char c;
      cin >> x >> y >> c;
      fill_from(n - 1 - y, x, c);
    } else if (op == 0) {
      int y1, y2, x1, x2;
      cin >> x1 >> y1 >> x2 >> y2;
      draw(x1, n - 1 - y1, x2, n - 1 - y2);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << g[i][j];
    }
    cout << endl;
  }
  return 0;
}

/*
  模拟，简单的BFS，但是一定要注意坐标系的转换关系。
*/