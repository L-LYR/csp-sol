// Time: 04/04/21
// Author: HammerLi
// Tags: [Euler Path] [Fleury] [DFS]
// Title: 送货
// Content:
//      为了增加公司收入，F公司新开设了物流业务。由于F公司在业界的良好口碑，物流业务一开通即受到了消费者的欢迎，
//      物流业务马上遍及了城市的每条街道。然而，F公司现在只安排了小明一个人负责所有街道的服务。
//      任务虽然繁重，但是小明有足够的信心，他拿到了城市的地图，准备研究最好的方案。城市中有n个交叉路口，
//      m条街道连接在这些交叉路口之间，每条街道的首尾都正好连接着一个交叉路口。除开街道的首尾端点，街道不会在其他位置与其他街道相交。
//      每个交叉路口都至少连接着一条街道，有的交叉路口可能只连接着一条或两条街道。
//      小明希望设计一个方案，从编号为1的交叉路口出发，每次必须沿街道去往街道另一端的路口，再从新的路口出发去往下一个路口，直到所有的街道都经过了正好一次。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
int n, m;
set<int> g[maxn];
stack<int> path;
stack<int> stk;
auto fleury(int start) -> void {  // actually this is a DFS
  stk.push(start);
  while (!stk.empty()) {
    int v = stk.top();
    if (g[v].empty()) {
      stk.pop();
      path.push(v);
    } else {
      int u = *g[v].begin();
      g[u].erase(v);
      g[v].erase(u);
      stk.push(u);
    }
  }
}

auto main() -> int {
  cin >> n >> m;
  int from, to;
  for (int i = 0; i < m; ++i) {
    cin >> from >> to;
    g[from].insert(to);
    g[to].insert(from);
  }
  int odd = 0;
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() % 2) odd++;
  }
  if (odd == 0 || (odd == 2 && g[1].size() % 2)) {
    fleury(1);                   // must start from 1
    if (path.size() != m + 1) {  // must check, or will be 90
      cout << -1 << endl;
    } else {
      while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
      }
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}

/*
    固定起点的欧拉路径裸题，注意欧拉路径的存在条件，奇数度的节点为0个或者2个，
    所以要特判当奇数度的节点存在时，1号节点是否是其中之一，
    最后得出路径之后还要判断长度是否是边数+1。
*/