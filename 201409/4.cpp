// Time: 03/19/21
// Author: HammerLi
// Tags: [BFS]
// Title: 最优配餐
// Content:
//      栋栋最近开了一家餐饮连锁店，提供外卖服务。随着连锁店越来越多，怎么合理的给客户送餐成为了一个急需解决的问题。
//      栋栋的连锁店所在的区域可以看成是一个n×n的方格图（如下图所示），
//      方格的格点上的位置上可能包含栋栋的分店（绿色标注）或者客户（蓝色标注），有一些格点是不能经过的（红色标注）。
//      方格图中的线表示可以行走的道路，相邻两个格点的距离为1。栋栋要送餐必须走可以行走的道路，而且不能经过红色标注的点。
//      送餐的主要成本体现在路上所花的时间，每一份餐每走一个单位的距离需要花费1块钱。
//      每个客户的需求都可以由栋栋的任意分店配送，每个分店没有配送总量的限制。
//      现在你得到了栋栋的客户的需求，请问在最优的送餐方式下，送这些餐需要花费多大的成本。
#include <bits/stdc++.h>

using namespace std;
using point = pair<int, int>;

// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
  seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val(std::size_t &seed, const T &val) {
  hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &...args) {
  hash_combine(seed, val);
  hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &...args) {
  std::size_t seed = 0;
  hash_val(seed, args...);
  return seed;
}

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    return hash_val(p.first, p.second);
  }
};

const int maxn = 1001;

struct step {
  point loc;
  int s;
  step(int x = 0, int y = 0, int s = 0)
      : loc(x, y), s(s) {}
};

int n, m, k, d;
bool vis[maxn][maxn];
unordered_set<point, pair_hash> bs;
unordered_map<point, int, pair_hash> cs;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

queue<step> q;
int64_t ans = 0;

auto bfs() -> void {
  step cur;
  int nx, ny;
  while (!q.empty()) {
    cur = q.front();
    q.pop();

    if (cs.count(cur.loc)) {
      ans += cs[cur.loc] * cur.s;
    }
    for (int i = 0; i < 4; ++i) {
      nx = cur.loc.first + dx[i];
      ny = cur.loc.second + dy[i];
      if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
      if (vis[nx][ny]) continue;
      if (bs.count({nx, ny})) continue;
      vis[nx][ny] = true;
      q.push({nx, ny, cur.s + 1});
    }
  }
}

auto main() -> int {
  cin >> n >> m >> k >> d;
  int a, b, w;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    q.emplace(a, b, 0);
    vis[a][b] = true;
  }
  for (int i = 0; i < k; ++i) {
    cin >> a >> b >> w;
    cs[{a, b}] += w;
  }
  for (int i = 0; i < d; ++i) {
    cin >> a >> b;
    bs.emplace(a, b);
  }

  bfs();
  cout << ans << endl;

  return 0;
}

/*
  没啥难度，码出普通的BFS即可，记得从餐馆开始BFS，从客户开始BFS要超时。
  注意，客户可能出现在同一地点，输入时要用+=。
*/