// Time: 04/09/21
// Author: HammerLi
// Tags: [Dijkstra][SPT]
// Title: 交通规划
// Content:
//    G国国王来中国参观后，被中国的高速铁路深深的震撼，决定为自己的国家也建设一个高速铁路系统。
//    建设高速铁路投入非常大，为了节约建设成本，G国国王决定不新建铁路，而是将已有的铁路改造成高速铁路。
//    现在，请你为G国国王提供一个方案，将现有的一部分铁路改造成高速铁路，使得任何两个城市间都可以通过高速铁路到达，
//    而且从所有城市乘坐高速铁路到首都的最短路程和原来一样长。请你告诉G国国王在这些条件下最少要改造多长的铁路。
#include <bits/stdc++.h>
using namespace std;
using out_edge = pair<int, int>;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
vector<out_edge> g[maxn];
bool vis[maxn];
int dis[maxn];
int pre[maxn];

struct edge_cmp {
  bool operator()(const out_edge& l, const out_edge& r) {
    return l.second > r.second;
  }
};

void dijkstra(int start) {
  memset(dis, 0x3f, sizeof(dis));
  memset(pre, 0x3f, sizeof(pre));
  dis[start] = 0;
  priority_queue<out_edge, vector<out_edge>, edge_cmp> pq;
  pq.push({start, 0});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (vis[cur.first]) {
      continue;
    }
    vis[cur.first] = true;
    for (const auto& e : g[cur.first]) {
      int v = e.first;
      int d = cur.second + e.second;
      if (dis[v] > d) {
        dis[v] = d;
        pre[v] = e.second;
        pq.push({v, dis[v]});
      } else if (dis[v] == d) {
        pre[v] = min(pre[v], e.second);
      }
    }
  }
}

auto main() -> int {
  int n, m;
  cin >> n >> m;
  int from, to, weight;
  for (int i = 0; i < m; ++i) {
    cin >> from >> to >> weight;
    g[from].push_back({to, weight});
    g[to].push_back({from, weight});
  }
  dijkstra(1);
  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    ans += pre[i];
  }
  cout << ans << endl;
  return 0;
}

/*
  裸的最短路径树。
*/