// Time: 03/22/21
// Author: HammerLi
// Tags: [Simulation]
// Titile: 集合竞价
// Content:
//      某股票交易所请你编写一个程序，根据开盘前客户提交的订单来确定某特定股票的开盘价和开盘成交量。
//      该程序的输入由很多行构成，每一行为一条记录，记录可能有以下几种：
//      1. buy p s 表示一个购买股票的买单，每手出价为p，购买股数为s。
//      2. sell p s 表示一个出售股票的卖单，每手出价为p，出售股数为s。
//      3. cancel i表示撤销第i行的记录。
//      如果开盘价为p0，则系统可以将所有出价至少为p0的买单和所有出价至多为p0的卖单进行匹配。
//      因此，此时的开盘成交量为出价至少为p0的买单的总股数和所有出价至多为p0的卖单的总股数之间的较小值。
//      你的程序需要确定一个开盘价，使得开盘成交量尽可能地大。如果有多个符合条件的开盘价，你的程序应当输出最高的那一个。
#include <bits/stdc++.h>
using namespace std;

enum RecordType : short {
  NOOP,
  BUY,
  SELL,
  CANCEL,
};

struct Record {
  RecordType t;
  int64_t s;
  double p;
  bool cancel;
  Record(RecordType t, int64_t s, double p = 0.0, bool c = false)
      : t(t), s(s), p(p), cancel(c) {}
};

int main() {
  vector<Record> records = {Record(NOOP, 0)};
  vector<int> buy, sell;
  string str;
  double p;
  int64_t s;
  while (cin >> str) {
    if (str == "cancel") {
      cin >> s;
      records.push_back(Record(CANCEL, 0));
      records[s].cancel = true;
    } else {
      cin >> p >> s;
      records.push_back(Record(str == "buy" ? BUY : SELL, s, p));
    }
  }
  int64_t buyS = 0, sellS = 0, ansS = 0;
  double ansP = 0.0;
  for (int i = 1; i < records.size(); ++i) {
    if (records[i].cancel) continue;
    if (records[i].t == BUY) {
      buy.push_back(i);
    } else if (records[i].t == SELL) {
      sell.push_back(i);
      sellS += records[i].s;
    }
  }

  auto cmp = [&records](int l, int r) {
    return records[l].p > records[r].p;
  };

  sort(buy.begin(), buy.end(), cmp);
  sort(sell.begin(), sell.end(), cmp);

  for (int i = 0, j = 0; i < buy.size() && j < sell.size(); ++i) {
    buyS += records[buy[i]].s;
    while (j < sell.size()) {
      if (records[sell[j]].p > records[buy[i]].p) {
        sellS -= records[sell[j]].s;
      } else {
        break;
      }
      j++;
    }
    if (ansS < buyS && ansS < sellS) {
      ansS = min(buyS, sellS);
      ansP = records[buy[i]].p;
    }
  }
  cout << fixed << setprecision(2) << ansP << " " << ansS << endl;
  return 0;
}