// Time: 03/18/21
// Author: HammerLi
// Tags: [Simulation] [LRU]
// Title: 窗口
// Content:
//      在某图形操作系统中,有 N 个窗口,每个窗口都是一个两边与坐标轴分别平行的矩形区域。窗口的边界上的点也属于该窗口。
//      窗口之间有层次的区别,在多于一个窗口重叠的区域里,只会显示位于顶层的窗口里的内容。
//      当你点击屏幕上一个点的时候, 你就选择了处于被点击位置的最顶层窗口, 并且这个窗口就会被移到所有窗口的最顶层,
//      而剩余的窗口的层次顺序不变。如果你点击的位置不属于任何窗口, 则系统会忽略你这次点击。
//      现在我们希望你写一个程序模拟点击窗口的过程。
#include <bits/stdc++.h>
using namespace std;

struct window {
  int lx, ly, rx, ry, id;
  window(int x1, int y1, int x2, int y2, int id)
      : lx(x1), ly(y1), rx(x2), ry(y2), id(id) {}
  auto inRange(int x, int y) -> bool {
    return x <= rx && y <= ry && x >= lx && y >= ly;
  }
};

list<window> windows;

auto main() -> int {
  int n, m;
  cin >> n >> m;
  int x1, x2, y1, y2;
  for (int i = 1; i <= n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    windows.emplace_front(x1, y1, x2, y2, i);
  }
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;

    auto it = find_if(windows.begin(), windows.end(),
                      [x, y](window& w) -> bool { return w.inRange(x, y); });

    if (it != windows.end()) {
      cout << it->id << endl;
      windows.push_front(*it);
      windows.erase(it);
    } else {
      cout << "IGNORED" << endl;
    }
  }
  return 0;
}

/*
  类似LRU算法，模拟即可
*/