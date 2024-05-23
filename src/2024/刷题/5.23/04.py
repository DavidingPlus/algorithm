# 最短循环节问题
# https://www.lanqiao.cn/problems/1628/learning/?page=1&first_category_id=1&name=%E6%9C%80%E7%9F%AD%E5%BE%AA%E7%8E%AF%E8%8A%82%E9%97%AE%E9%A2%98

n = int(input())
s = input()
# 对于 S 而言，由于只是截取原串的部分，因此可能缺失了部分字母，可以从前面缺失，也可以从后面缺失，所以从 S 反推原串是有多种情况的，就是因为我们不知道到底是前面还是后面缺失。例如 cabcabca ，可以是 cab （后面缺失），可以是 bca（前面缺失），甚至是 abc （前后都），但是对于最短长度而言，这三种情况没有任何影响，因此当作后面缺失去做即可，使用滑动窗口去检测即可，当然在字符串比较的时候可以加上哈希的优化
for i in range(1, 1+n):
    flag = True
    for j in range(i, 1+n, i):
        if j+i <= n and s[:i] != s[j:j+i]:
            flag = False
            break
    if flag:
        print(i)
        break
