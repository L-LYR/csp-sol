// Time: 03/15/21
// Author: HammerLi
// Tags: [DP]
// Title: 有趣的数
// Content:
// 　　我们把一个数称为有趣的，当且仅当：
// 　　1. 它的数字只包含0, 1, 2, 3，且这四个数字都出现过至少一次。
// 　　2. 所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
// 　　3. 最高位数字不为0。
// 　　因此，符合我们定义的最小的有趣的数是2013。除此以外，4位的有趣的数还有两个：2031和2301。
// 　　请计算恰好有n位的有趣的数的个数。由于答案可能非常大，只需要输出答案除以1000000007的余数。
#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
const int maxn = 1001;

int64_t dp[maxn][6];

auto main() -> int {
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    dp[i][1] = (dp[i - 1][1] * 2 + dp[i - 1][0]) % mod;
    dp[i][2] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
    dp[i][3] = (dp[i - 1][3] * 2 + dp[i - 1][1]) % mod;
    dp[i][4] = (dp[i - 1][4] * 2 + dp[i - 1][2] + dp[i - 1][1]) % mod;
    dp[i][5] = (dp[i - 1][5] * 2 + dp[i - 1][4] + dp[i - 1][3]) % mod;
  }
  cout << dp[n][5] << endl;

  return 0;
}