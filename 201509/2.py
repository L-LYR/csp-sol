# Time: 04/01/21
# Author: HammerLi
# Tags: [Simulation]
# Title: 日期计算
# Content:
# 　　给定一个年份y和一个整数d，问这一年的第d天是几月几日？
# 　　注意闰年的2月有29天。满足下面条件之一的是闰年：
# 　　1） 年份是4的整数倍，而且不是100的整数倍；
# 　　2） 年份是400的整数倍。

from datetime import date, timedelta

y = int(input())
d = int(input())

cur = date(y, 1, 1)
tar = cur + timedelta(days=(d-1))
print(tar.month, tar.day, sep='\n')

# 投机取巧型做法，因为之后的CSP可以使用多语言了hhhh