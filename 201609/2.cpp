// Time: 04/09/21
// Author: HammerLi
// Tags: [Simulation]
// Title: 火车购票
// Content:
//      请实现一个铁路购票系统的简单座位分配算法，来处理一节车厢的座位分配。
//      假设一节车厢有20排、每一排5个座位。为方便起见，我们用1到100来给所有的座位编号，
//      第一排是1到5号，第二排是6到10号，依次类推，第20排是96到100号。
//      购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安排在同一排编号相邻的座位，
//      则应该安排在编号最小的相邻座位。否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
//      假设初始时车票全部未被购买，现在给了一些购票指令，请你处理这些指令。
#include <bits/stdc++.h>
using namespace std;
int seat[20];
auto main() -> int {
  int n, p;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    bool flag = false;
    for (int j = 0; j < 20; ++j) {
      if (5 - seat[j] >= p) {
        for (int k = 1; k <= p; k++) {
          cout << seat[j] + k + j * 5 << " ";
        }
        cout << endl;
        seat[j] += p;
        flag = true;
        break;
      }
    }
    if (!flag) {
      for (int j = 0; j < 20 && p > 0; ++j) {
        while (5 - seat[j] > 0 && p > 0) {
          seat[j]++;
          cout << seat[j] + j * 5 << " ";
          p--;
        }
      }
    }
  }
  return 0;
}


/*
  简单模拟，优先遍历全部，找不到连续的就再来一波。
*/