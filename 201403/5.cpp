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

  int v = max(x, max(y, z));
  if (v > ans) return;

  if (i == n + 1) {
    ans = min(ans, v);
    return;
  }

  dp[x][y][z] = i;

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

// csp官网数据有误，仅30分，在下面的网站测试可通过。
// https://www.acwing.com/problem/content/3204/
/*
  f(x, y, z) = n 表示CPU0 CPU1 GPU分别使用了x y z时间后，完成了前n个任务，
  所以消耗的时间应该时t(n, f(x, y, z)) = max(x, y, z)。
  最终答案表示为ans(n) = min(t(n, f(x, y, z)))，即对于所有能够完成前n个任务的状态中用时最小的。

  考虑六种状态转移：
  1. 使用CPU0 CPU1 GPU，即 t(i, f(x, y, z)) -> t(i + 1, f(x + di, y + di, z + di))
  2. 使用CPU0 CPU1，即 t(i, f(x, y, z)) -> t(i + 1, f(x + bi, y + bi, z))
  3. 使用CPU0 GPU，即 t(i, f(x, y, z)) -> t(i + 1, f(x + ci, y, z + ci))
  4. 使用CPU1 GPU，即 t(i, f(x, y, z)) -> t(i + 1, f(x, y + ci, z + ci))
  5. 使用CPU0，即 t(i, f(x, y, z)) -> t(i + 1, f(x + ai, y, z))
  6. 使用CPU1，即 t(i, f(x, y, z)) -> t(i + 1, f(x, y + ai, z))

  容易看出没有单GPU的任务处理方式，所以1和2可以合并为增加较小的任务处理时间，即
  ki = min(bi, di)
  t(i, f(x, y, z)) -> t(i + 1, f(x + ki, y + ki, z + ki))

  根据上述转移，不太好写成循环，使用DFS比较简单快捷。

  同时考虑简单的剪枝：
  1. 对于相同的一组 x y z，新的f(x, y, z)比旧的f(x, y, z)小，则不需要再调度下去了。
  2. 当前t(i, f(x, y, z))大于目前的结果时，也不需要再搜索下去了。
*/