// Time: 04/01/21
// Author: HammerLi
// Tags: [SCC] [Kosaraju]
// Title: 高速公路
// Content:
//      某国有n个城市，为了使得城市间的交通更便利，该国国王打算在城市之间修一些高速公路，
//      由于经费限制，国王打算第一阶段先在部分城市之间修一些单向的高速公路。
//      现在，大臣们帮国王拟了一个修高速公路的计划。看了计划后，国王发现，有些城市之间可以通过高速公路直接
//      （不经过其他城市）或间接（经过一个或多个其他城市）到达，而有的却不能。如果城市A可以通过高速公路到达城市B，
//      而且城市B也可以通过高速公路到达城市A，则这两个城市被称为便利城市对。
//      国王想知道，在大臣们给他的计划中，有多少个便利城市对。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

vector<int> g[maxn];   // origin graph
vector<int> tg[maxn];  // transpose graph
vector<int> seq;       // sequence for preorder
int n, m;
int color[maxn];     // color for node
int SCC_cnt = 0;     // counter of SCC
int SCC_size[maxn];  // size of each SCC
bool vis[maxn];      // visited status for node

auto DFS_g(int u) -> void {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) DFS_g(v);
  }
  seq.push_back(u);
}

auto DFS_tg(int u) -> void {
  color[u] = SCC_cnt;
  SCC_size[SCC_cnt]++;
  for (auto v : tg[u]) {
    if (color[v] == 0) DFS_tg(v);
  }
}

auto kosaraju() -> void {
  SCC_cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) DFS_g(i);
  }
  for (auto i = seq.rbegin(); i != seq.rend(); i++) {
    if (color[*i] == 0) {
      ++SCC_cnt;
      DFS_tg(*i);
    }
  }
}

auto main() -> int {
  cin >> n >> m;
  int from, to;
  for (int i = 0; i < m; ++i) {
    cin >> from >> to;
    g[from].push_back(to);
    tg[to].push_back(from);
  }
  kosaraju();
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += SCC_size[i] * (SCC_size[i] - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}

/*
  有向图强连通分量裸题。
*/