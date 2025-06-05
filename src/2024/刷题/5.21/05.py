# 乘积幂次
# https://www.lanqiao.cn/problems/1155/learning/

from functools import lru_cache

# 使用欧拉函数判断 10**9+7 是否为一个质数
# def phi(n):
#     res = float(n)
#     i = 2
#     while i*i <= n:
#         if 0 == n % i:
#             while 0 == n % i:
#                 res *= 1-1/i
#             n /= i
#         i += 1
#     # 处理最后一个可能大于 sqrt(n) 的质数
#     if 1 != n:
#         res *= 1-1/n
#     return int(res)

# print(phi(10**9+7))  # 10**9+6，代表他是质数

# 测试数据：131955674 417236 -> 424832133

mod = 10**9+7
n, m = map(int, input().split())


def quickPower(n, m, p):
    res = 1
    while m > 0:
        if m & 1:
            res = (res*n) % p
        n = (n*n) % p
        m >>= 1
    return res


# 根据欧拉定理，原始的指数转化为 m! % (mod - 1)
newM = 1
for i in range(1, 1+m):
    newM = (newM*i) % (mod - 1)

print(quickPower(n, newM, mod))
