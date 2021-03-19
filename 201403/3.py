# Time: 03/18/21
# Author: HammerLi
# Tags: [Simulation][LRU]
# Title: 窗口
# Content:
#       请你写一个命令行分析程序, 用以分析给定的命令行里包含哪些选项。每个命令行由若干个字符串组成,
#       它们之间恰好由一个空格分隔。这些字符串中的第一个为该命令行工具的名字, 由小写字母组成,
#       你的程序不用对它进行处理。
#       在工具名字之后可能会包含若干选项, 然后可能会包含一 些不是选项的参数。
#       选项有两类: 带参数的选项和不带参数的选项。一个合法的无参数选项的形式是一个减号后面跟单个小写字母,
#       如"-a" 或"-b"。而带参数选项则由两个由空格分隔的字符串构成, 前者的格式要求与无参数选项相同,
#       后者则是该选项的参数, 是由小写字母, 数字和减号组成的非空字符串。
#       该命令行工具的作者提供给你一个格式字符串以指定他的命令行工具需要接受哪些选项。
#       这个字符串由若干小写字母和冒号组成, 其中的每个小写字母表示一个该程序接受的选项。
#       如果该小写字母后面紧跟了一个冒号, 它就表示一个带参数的选项, 否则则为不带参数的选项。
#       例如, "ab:m:" 表示该程序接受三种选项, 即"-a"(不带参数), "-b"(带参数), 以及"-m"(带参数)。
#       命令行工具的作者准备了若干条命令行用以测试你的程序。对于每个命令行, 你的工具应当一直向后分析。
#       当你的工具遇到某个字符串既不是合法的选项, 又不是某个合法选项的参数时, 分析就停止。
#       命令行剩余的未分析部分不构成该命令的选项, 因此你的程序应当忽略它们。

fmt = input()
args = {}
for i in range(0, len(fmt)):
    if fmt[i] == ':':
        args['-' + fmt[i-1]] = True
    else:
        args['-' + fmt[i]] = False


n = int(input())
for i in range(1, n + 1):
    ans = {}
    inArgs = input().split(' ')[1:]

    j = 0
    while j < len(inArgs):
        if len(inArgs[j]) == 2 and inArgs[j] in args:
            if args[inArgs[j]]:
                if j < len(inArgs)-1:
                    ans[inArgs[j]] = inArgs[j + 1]
                j += 1
            else:
                ans[inArgs[j]] = ""
        else:
            break
        j += 1

    res = ["Case {}:".format(i)]
    for a, p in sorted(ans.items(), key=lambda x: x[0]):
        res.append(a)
        if p:
            res.append(p)
    print(' '.join(res))


# 模拟即可，记得排序