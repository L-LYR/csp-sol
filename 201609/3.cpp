// Time: 04/10/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 炉石传说
#include <bits/stdc++.h>
using namespace std;

int role;
list<pair<int, int>> summon[2];

auto main() -> int {
  int n;
  cin >> n;
  summon[1].push_back({30, 0});
  summon[0].push_back({30, 0});
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;
    if (op == "summon") {
      int h, a, p;
      cin >> p >> a >> h;
      auto pos = next(summon[role].begin(), p);
      summon[role].insert(pos, {h, a});
    } else if (op == "attack") {
      int l, r;
      cin >> l >> r;
      auto lp = next(summon[role].begin(), l);
      auto rp = next(summon[role ^ 1].begin(), r);
      rp->first -= lp->second;
      lp->first -= rp->second;
      if (rp->first <= 0 && rp != summon[role ^ 1].begin()) {
        summon[role ^ 1].erase(rp);
      }
      if (lp->first <= 0 && lp != summon[role].begin()) {
        summon[role].erase(lp);
      }
    } else if (op == "end") {
      role ^= 1;
    }
  }

  if (summon[1].begin()->first <= 0) {
    cout << 1 << endl;
  } else if (summon[0].begin()->first <= 0) {
    cout << -1 << endl;
  } else {
    cout << 0 << endl;
  }
  for (int j = 0; j < 2; ++j) {
    cout << summon[j].begin()->first << endl;
    cout << summon[j].size() - 1 << " ";
    for (auto it = next(summon[j].begin(), 1); it != summon[j].end(); ++it) {
      cout << it->first << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
  简单模拟，选链表，方便插入。
*/