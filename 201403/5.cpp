// Time: 03/18/21
// Author: HammerLi
// Tags: [DP]
// Title: 任务调度
// Content:
// 有若干个任务需要在一台机器上运行。
// 它们之间没有依赖关系，因此可以被按照任意顺序执行。
// 该机器有两个 CPU 和一个 GPU。
// 对于每个任务，你可以为它分配不同的硬件资源 :
// 在单个 CPU 上运行。
// 在两个 CPU 上同时运行。
// 在单个 CPU 和 GPU 上同时运行。
// 在两个 CPU 和 GPU 上同时运行。
// 一个任务开始执行以后，将会独占它所用到的所有硬件资源，不得中断，直到执行结束为止。
// 第 i 个任务用单个 CPU，两个 CPU，单个 CPU 加 GPU，两个 CPU 加 GPU
// 运行所消耗的时间分别为 ai, bi, ci 和 di。
// 现在需要你计算出至少需要花多少时间可以把所有给定的任务完成。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 42;
const int maxVal = 401;

struct task {
  int a, b, c, d;
  task(int a = 0, int b = 0, int c = 0, int d = 0)
      : a(a), b(b), c(c), d(d) {}
};

int n;
task ts[maxn];
int dp[maxVal][maxVal][maxVal];
int ans = INT_MAX;

auto dfs(int i, int x, int y, int z) -> void {
  if (dp[x][y][z] >= i) return;
  dp[x][y][z] = i;

  int v = max(x, max(y, z));
  if (v > ans) return;
  if (i == n + 1) {
    ans = min(ans, v);
    return;
  }
  dfs(i + 1, x + ts[i].b, y + ts[i].b, z + ts[i].b);
  dfs(i + 1, x, y + ts[i].a, z);
  dfs(i + 1, x + ts[i].a, y, z);
  dfs(i + 1, x, y + ts[i].c, z + ts[i].c);
  dfs(i + 1, x + ts[i].c, y, z + ts[i].c);
}

auto main() -> int {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ts[i].a >> ts[i].b >> ts[i].c >> ts[i].d;
    if (ts[i].b > ts[i].d) ts[i].b = ts[i].d;
  }

  dp[0][0][0] = -1;
  dfs(0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}