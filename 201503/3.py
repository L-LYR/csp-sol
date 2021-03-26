# Time: 03/26/21
# Author: HammerLi
# Tags: [Simulation]
# Title: 节日
# Content:
# 　　有一类节日的日期并不是固定的，而是以“a月的第b个星期c”的形式定下来的，比如说母亲节就定为每年的五月的第二个星期日。
# 　　现在，给你a，b，c和y1, y2(1850 ≤ y1, y2 ≤ 2050)，希望你输出从公元y1年到公元y2年间的每年的a月的第b个星期c的日期。
# 　　提示：关于闰年的规则：年份是400的整数倍时是闰年，否则年份是4的倍数并且不是100的倍数时是闰年，
#    其他年份都不是闰年。例如1900年就不是闰年，而2000年是闰年。
# 　　为了方便你推算，已知1850年1月1日是星期二。

from datetime import date, timedelta

a, b, c, y1, y2 = map(int, input().split(' '))

inc = timedelta(days=1)

for y in range(y1, y2 + 1):
    cur = date(y, a, 1)
    cnt = 0
    while cur.month == a:
        if cur.isoweekday() == c:
            cnt += 1
        if cnt == b:
            print("{}/{:02}/{:02}".format(cur.year, cur.month, cur.day))
            break
        cur += inc
    if cnt < b:
        print("none")
