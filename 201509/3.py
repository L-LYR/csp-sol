# Time: 04/02/21
# Author: HammerLi
# Tags: [Simulation]
# Title: 模板生成系统
# Content:
#    给定字符串替换

from collections import defaultdict

m, n = map(int, input().split(' '))

template = ""
for _ in range(m):
    template += "\n" + input()
template = template[1:]

vars = defaultdict(str)

for _ in range(n):
    line = input()
    sep = line.find(' ')
    var, tar = line[:sep], line[sep+2:-1]
    vars[var] = tar

i = 0
while i < len(template):
    left = template.find("{{ ", i)
    if left == -1:
        break
    right = template.find(" }}", left)
    if right == -1:
        break
    key = template[left+3:right]
    template = template[:left] + vars[key] + template[right + 3:]
    i = left + len(vars[key])

print(template)

# 防止递归替换，这里只能在输入完之后，逐个查询