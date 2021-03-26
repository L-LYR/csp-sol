// Time: 03/22/21
// Author: HammerLi
// Tags: [DP with Bitmasking][Fast Matrix Exponentiation]
// Title: 拼图
// Content:
//      给出一个n×m的方格图，现在要用如下L型的积木拼到这个图中，使得方格图正好被拼满，请问总共有多少种拼法。
//      其中，方格图的每一个方格正好能放积木中的一块。积木可以任意旋转。
#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 7;

int64_t n;
int m;

auto put(int status, int c1, int c2 = -1) -> int {
  status |= 1 << c1;
  if (c2 != -1) status |= 1 << c2;
  return status;
}

auto check_empty(int status, int c) -> bool {
  return c >= 0 && c < m && ((status & (1 << c)) == 0);
}

int64_t f[lim][lim];
auto DFS(int ori_status, int cur_status, int nxt_status, int c) -> void {
  if (cur_status == (1 << m) - 1) {
    f[ori_status][nxt_status]++;
    return;
  }
  if (check_empty(cur_status, c)) {
    // [][]
    // []
    if (check_empty(cur_status, c + 1) && check_empty(nxt_status, c)) {
      DFS(ori_status,
          put(cur_status, c, c + 1),
          put(nxt_status, c),
          c + 2);
    }
    // [][]
    //   []
    if (check_empty(cur_status, c + 1) && check_empty(nxt_status, c + 1)) {
      DFS(ori_status,
          put(cur_status, c, c + 1),
          put(nxt_status, c + 1),
          c + 2);
    }
    // []
    // [][]
    if (check_empty(nxt_status, c) && check_empty(nxt_status, c + 1)) {
      DFS(ori_status,
          put(cur_status, c),
          put(nxt_status, c, c + 1),
          c + 1);
    }
    //   []
    // [][]
    if (check_empty(nxt_status, c) && check_empty(nxt_status, c - 1)) {
      DFS(ori_status,
          put(cur_status, c),
          put(nxt_status, c - 1, c),
          c + 1);
    }
  } else {
    DFS(ori_status, cur_status, nxt_status, c + 1);
  }
}

int64_t buf[lim][lim];
int64_t ans[lim][lim];

auto matrix_copy(int64_t l[lim][lim], int64_t r[lim][lim], int dim) -> void {
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      l[i][j] = r[i][j];
    }
  }
}

auto matrix_multiply(int64_t l[lim][lim], int64_t r[lim][lim], int dim, int mod = 1e9 + 7) -> void {
  memset(buf, 0, sizeof(buf));
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      for (int k = 0; k < dim; ++k) {
        buf[i][j] = (buf[i][j] + l[i][k] * r[k][j] % mod) % mod;
      }
    }
  }
  matrix_copy(l, buf, dim);
}

auto fast_power(int64_t m[lim][lim], int dim, int64_t e, int mod = 1e9 + 7) -> void {
  while (e > 0) {
    if (e & 1) {
      matrix_multiply(ans, m, dim);
    }
    matrix_multiply(m, m, dim);
    e >>= 1;
  }
}

auto main() -> int {
  cin >> n >> m;

  for (int s = 0; s < (1 << m); ++s) {
    ans[s][s] = 1;
    DFS(s, s, 0, 0);
  }

  fast_power(f, 1 << m, n);

  cout << ans[0][0] << endl;

  return 0;
}

/*
  状态压缩动态规划+矩阵快速幂
  分析：
  1. 因为考虑到列数比较小，所以可以用二进制来表示每一行的状态，进而考虑到使用状态压缩动态规划。
  2. L型的拼图仅涉及到相邻两行的状态转换，因此从第一行开始，完全放满一行，则下一行的状态自然获得，
     进而继续填满，得到下下一行的状态，据此可以递推到最后一行，如果最后一行放慢，则说明该方案是满足题意的。
  3. 使用DFS来获取状态转移矩阵，转移矩阵f[i][j]表示从状态i到状态j有多少种转移方法。
  4. 为什么用矩阵快速幂可以得到结果呢？
     我们可以将该题抽象成图上的问题，每一种状态为图上的一点，状态间的转移关系为有向边，我们的目标就是
     求状态为0的点回到状态为0的点的路径中长度为n的路径个数。所以转移矩阵就变成了邻接矩阵。
     在图中，邻接矩阵n次方后f^n[i][j]表示从点i到点j路径长度为n的路径个数，所以快速幂就完事了。
*/