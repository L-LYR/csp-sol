# Time: 03/18/21
# Author: HammerLi
# Tags: [Simulation]
# Title: 字符串匹配
# Content:
#   给出一个字符串和多行文字，在这些文字中找到字符串出现的那些行。
#   你的程序还需支持大小写敏感选项：当选项打开时，表示同一个字母的大写和小写看作不同的字符；
#   当选项关闭时，表示同一个字母的大写和小写看作相同的字符。

tar = input()
strict = bool(int(input()))
n = int(input())

for i in range(0, n):
    src = input()
    if strict:
        if src.find(tar) != -1:
            print(src)
    else:
        if src.lower().find(tar.lower()) != -1:
            print(src)
