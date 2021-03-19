// Time: 03/18/21
// Author: HammerLi
// Tags: [BFS] [Optimize]
// Title: 无线网络
// Content:
//    目前在一个很大的平面房间里有 n 个无线路由器,
//    每个无线路由器都固定在某个点上。任何两个无线路由器只要距离不超过 r 就能互相建立网络连接。
//    除此以外, 另有 m 个可以摆放无线路由器的位置。
//    你可以在这些位置中选择至多 k 个增设新的路由器。
//    你的目标是使得第 1 个路由器和第 2 个路由器之间的网络连接经过尽量少的中转路由器。
//    请问在最优方案下中转路由器的最少个数是多少 ?
#include <bits/stdc++.h>
using namespace std;

const int maxn = 201;

struct point {
  int64_t x, y;
  point(int64_t x = 0, int64_t y = 0) : x(x), y(y) {}
};

inline auto dis(point& l, point& r) -> long double {
  return sqrt(powl(l.x - r.x, 2) + powl(l.y - r.y, 2));
}

bool mat[maxn][maxn];

int cnt[maxn];

struct step {
  int r, i, l;
  step(int r = 0, int i = 0, int l = 0) : r(r), i(i), l(l) {}
};

auto main() -> int {
  int n, m, k, r;
  cin >> n >> m >> k >> r;
  int tot = n + m;
  vector<point> routers(tot);
  for (int i = 0; i < tot; ++i) {
    cin >> routers[i].x >> routers[i].y;
  }

  memset(mat, false, sizeof(mat));
  memset(cnt, 0x3f, sizeof(cnt));

  for (int i = 0; i < tot; ++i) {
    for (int j = i + 1; j < tot; ++j) {
      if (dis(routers[i], routers[j]) <= r) {
        mat[i][j] = mat[j][i] = true;
      }
    }
  }

  queue<step> q;
  q.push(step(0, 0, 0));
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    if (cur.i == 1) {
      cout << cur.l - 1 << endl;
      break;
    }
    if (cur.l >= n) continue;
    for (int i = 0; i < tot; ++i) {
      if (i == cur.i) continue;
      if (!mat[i][cur.i]) continue;
      if (i >= n && cur.r == k) break;

      if (cnt[i] <= cur.l + 1) continue;  // must use <=
      cnt[i] = cur.l + 1;

      if (i >= n) {
        q.push(step(cur.r + 1, i, cur.l + 1));
      } else {
        q.push(step(cur.r, i, cur.l + 1));
      }
    }
  }

  return 0;
}

/*
  输入路由器坐标，建图，数据量不大，邻接矩阵即可（bool类型），跑BFS即可。
  普通BFS仅过50%样例，需要剪枝：
  使用一个数组来存储从起点到其余节点的最短路径，如果当前step的路径小于
  最短路径则更新，如果大于等于则不再继续搜索。
*/