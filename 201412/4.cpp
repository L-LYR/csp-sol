// Time: 03/23/21
// Author: HammerLi
// Tags: [MST]
// Title: 最优灌溉
// Content:
//      雷雷承包了很多片麦田，为了灌溉这些麦田，雷雷在第一个麦田挖了一口很深的水井，所有的麦田都从这口井来引水灌溉。
//      为了灌溉，雷雷需要建立一些水渠，以连接水井和麦田，雷雷也可以利用部分麦田作为“中转站”，
//      利用水渠连接不同的麦田，这样只要一片麦田能被灌溉，则与其连接的麦田也能被灌溉。
//      现在雷雷知道哪些麦田之间可以建设水渠和建设每个水渠所需要的费用（注意不是所有麦田之间都可以建立水渠）。
//      请问灌溉所有麦田最少需要多少费用来修建水渠。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxm = 1e5 + 5;

struct edge {
  int from, to, weight;
  edge(int f = 0, int t = 0, int w = 0)
      : from(f), to(t), weight(w) {}
};

struct DSU {
  int f[maxn];
  DSU(int n) {
    for (int i = 1; i <= n; ++i) f[i] = i;
  }
  int find(int x) { return (x == f[x]) ? x : (f[x] = find(f[x])); }
  void merge(int l, int r) { f[find(l)] = find(r); }
};

auto main() -> int {
  int n, m;
  cin >> n >> m;
  vector<edge> es(m);
  for (int i = 0; i < m; ++i) {
    cin >> es[i].from >> es[i].to >> es[i].weight;
  }
  sort(es.begin(), es.end(), [](const edge& l, const edge& r) {
    return l.weight < r.weight;
  });
  DSU s(n);
  int ans = 0;
  for (auto& e : es) {
    if (s.find(e.from) == s.find(e.to)) continue;
    s.merge(e.from, e.to);
    ans += e.weight;
  }
  cout << ans << endl;
  return 0;
}

/*
  最小生成树裸题。
*/