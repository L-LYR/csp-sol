// Time: 04/07/21
// Author: HammerLi
// Tags: [BFS]
// Title: 游戏
//      小明在玩一个电脑游戏，游戏在一个n*m的方格图上进行，小明控制的角色开始的时候站在第一行第一列，目标是前往第n行第m列。
//      方格图上有一些方格是始终安全的，有一些在一段时间是危险的，如果小明控制的角色到达一个方格的时候方格是危险的，
//      则小明输掉了游戏，如果小明的角色到达了第n行第m列，则小明过关。第一行第一列和第n行第m列永远都是安全的。
//      每个单位时间，小明的角色必须向上下左右四个方向相邻的方格中的一个移动一格。
//      经过很多次尝试，小明掌握了方格图的安全和危险的规律：每一个方格出现危险的时间一定是连续的。并且，小明还掌握了每个方格在哪段时间是危险的。
//      现在，小明想知道，自己最快经过几个时间单位可以达到第n行第m列过关。
#include <bits/stdc++.h>
using namespace std;
using point = pair<int, int>;
using duration = pair<int, int>;

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

struct step {
  int x, y, t;
  step(int x = 1, int y = 1, int t = 0) : x(x), y(y), t(t) {}
};

bool vis[105][105][300];
int n, m, t;
unordered_map<point, duration, pair_hash> dangers;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

auto main() -> int {
  cin >> n >> m >> t;
  int x, y, a, b;
  for (int i = 0; i < t; ++i) {
    cin >> x >> y >> a >> b;
    dangers[{x, y}] = {a, b};
  }
  queue<step> q;
  q.push(step());
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    // cout << cur.x << " " << cur.y << endl;
    if (cur.x == n && cur.y == m) {
      cout << cur.t << endl;
      return 0;
    }
    int nt = cur.t + 1;
    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
      if (vis[nx][ny][nt]) continue;
      auto it = dangers.find({nx, ny});
      if (it != dangers.end()) {
        if (nt >= it->second.first && nt <= it->second.second) {
          continue;
        }
      }
      vis[nx][ny][nt] = true;
      q.emplace(nx, ny, nt);
    }
  }

  return 0;
}

/*
  普通BFS
*/