// Time: 03/22/21
// Author: HammerLi
// Tags: [Simulation]
// Titile: 门禁系统
// Content:
//      涛涛最近要负责图书馆的管理工作，需要记录下每天读者的到访情况。
//      每位读者有一个编号，每条记录用读者的编号来表示。给出读者的来访记录，请问每一条记录中的读者是第几次出现。
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> cnt;
auto main(void) -> int {
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cnt[x]++;
    cout << cnt[x] << " ";
  }
  return 0;
}