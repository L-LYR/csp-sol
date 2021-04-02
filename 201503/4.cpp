// Time: 03/26/21
// Author: HammerLi
// Tags: [DFS]
// Title: 网络延时
// Content:
//      给定一个公司的网络，由n台交换机和m台终端电脑组成，交换机与交换机、交换机与电脑之间使用网络连接。交换机按层级设置，
//      编号为1的交换机为根交换机，层级为1。其他的交换机都连接到一台比自己上一层的交换机上，
//      其层级为对应交换机的层级加1。所有的终端电脑都直接连接到交换机上。
//      当信息在电脑、交换机之间传递时，每一步只能通过自己传递到自己所连接的另一台电脑或交换机。
//      请问，电脑与电脑之间传递消息、或者电脑与交换机之间传递消息、或者交换机与交换机之间传递消息最多需要多少步。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 1;

vector<int> g[maxn];

int ans = 0;
int max_depth_node = 0;

auto DFS(int cur, int pa, int dep) -> void {
  if (dep > ans) {
    ans = dep;
    max_depth_node = cur;
  }
  for (auto nxt : g[cur]) {
    if (nxt == pa) continue;
    DFS(nxt, cur, dep + 1);
  }
}

auto main() -> int {
  int n, m;
  cin >> n >> m;
  int j;
  for (int i = 2; i <= n + m; ++i) {
    cin >> j;
    g[i].push_back(j);
    g[j].push_back(i);
  }
  DFS(1, 0, 1);
  DFS(max_depth_node, 0, 0);
  cout << ans << endl;
  return 0;
}

/*
  n叉树的直径，裸题，两次DFS即可。
*/