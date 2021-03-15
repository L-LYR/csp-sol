// Time: 03/15/21
// Author: HammerLi
// Tags: [BFS]
// Title: I’m stuck!
// Content:
// 　给定一个R行C列的地图，地图的每一个方格可能是 '#', '+', '-', '|', '.', 'S', 'T'七个字符中的一个，分别表示如下意思：
// 　　'#' : 任何时候玩家都不能移动到此方格；
// 　　'+' : 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非 '#'方格移动一格；
// 　　'-' : 当玩家到达这一方格后，下一步可以向左右两个方向相邻的一个非 '#'方格移动一格；
// 　　'|' : 当玩家到达这一方格后，下一步可以向上下两个方向相邻的一个非 '#'方格移动一格；
// 　　'.' : 当玩家到达这一方格后，下一步只能向下移动一格。如果下面相邻的方格为 '#'，则玩家不能再移动；
// 　　'S' : 玩家的初始位置，地图中只会有一个初始位置。玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非 '#'方格移动一格；
// 　　'T' : 玩家的目标位置，地图中只会有一个目标位置。玩家到达这一方格后，可以选择完成任务，也可以选择不完成任务继续移动。
//          如果继续移动下一步可以向上下左右四个方向相邻的任意一个非 '#'方格移动一格。
// 　　此外，玩家不能移动出地图。
// 　　请找出满足下面两个性质的方格个数：
// 　　1. 玩家可以从初始位置移动到此方格；
// 　　2. 玩家不可以从此方格移动到目标位置。
#include <bits/stdc++.h>
using namespace std;
using point = pair<int, int>;
const int maxn = 50;
char maze[maxn][maxn];
int n, m;
bool reachable = false;
bool counting = false;
bool vis[maxn][maxn];
bool accessible[maxn][maxn];
bool memo[maxn][maxn];
int tot = 0, cnt = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

point s, t;

inline auto check(int x, int y) -> bool {
  if (x < 0 || y < 0 || x >= n || y >= m) return false;
  if (maze[x][y] == '#') return false;
  if (vis[x][y]) return false;
  return true;
}

inline auto forward(int l, int r, int x, int y, queue<point>& q) -> void {
  int nx, ny;
  for (int i = l; i <= r; ++i) {
    nx = x + dx[i];
    ny = y + dy[i];
    if (check(nx, ny)) {
      q.push({nx, ny});
      vis[nx][ny] = true;
      if (!counting) {
        accessible[nx][ny] = true;
      }
    }
  }
}

auto bfs(int x, int y) -> void {
  memset(vis, false, sizeof(vis));

  queue<point> q;

  q.push({x, y});
  vis[x][y] = true;
  if (!counting) {
    accessible[x][y] = true;
  }

  point cur;
  char c;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    if (cur == t) {
      if (counting) {
        cnt++;
        return;
      } else {
        reachable = true;
      }
    }
    c = maze[cur.first][cur.second];
    if (c == '+' || c == 'S' || c == 'T') {
      forward(0, 3, cur.first, cur.second, q);
    } else if (c == '|') {
      forward(0, 1, cur.first, cur.second, q);
    } else if (c == '-') {
      forward(2, 3, cur.first, cur.second, q);
    } else if (c == '.') {
      forward(0, 0, cur.first, cur.second, q);
    }
  }
}

auto main() -> int {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> maze[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 'S') {
        s = {i, j};
      } else if (maze[i][j] == 'T') {
        t = {i, j};
      }
    }
  }
  bfs(s.first, s.second);
  if (!reachable) {
    cout << "I'm stuck!" << endl;
    return 0;
  }
  counting = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (accessible[i][j]) {
        tot++;
        bfs(i, j);
      }
    }
  }

  cout << tot - cnt << endl;

  return 0;
}