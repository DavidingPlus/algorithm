# https://www.lanqiao.cn/problems/1457/learning/?page=1&first_category_id=1&name=%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92%E5%BD%A2

from math import comb, factorial

# math 里面没有计算排列的公式，根据这个组合和阶乘的公式自己写一个
# 要保证 a 等于 b ，否则会报错
# def Comb(n, m):
#     return factorial(n) // factorial(m) // factorial(n - m)
# def perm(a, b):
#     return Comb(a, b) * factorial(b)
# print(comb(5, 2))  # 10
# print(perm(5, 2))  # 20

# 从第三行开始，如果最大值和最小值满足范围，则查询（不包括 1）
# TODO 超时，4/10
n = int(input())
ans = 1
if 1 != n:
    i = 2  # 注意 2 是下标不是行号
    while True:
        if comb(i, 1) <= n and comb(i, i // 2) >= n:
            flag = False
            for j in range(1, 1 + i // 2):
                if n == comb(i, j):
                    ans = i * (i + 1) // 2 + j + 1
                    flag = True
                    break
            if True == flag:
                break
        i += 1
print(ans)
