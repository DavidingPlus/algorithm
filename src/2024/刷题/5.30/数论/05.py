# 乘积幂次
# https://www.lanqiao.cn/problems/1155/learning/


# def phi(n):
#     res = n

#     i = 2
#     while i*i <= n:
#         if 0 == n % i:
#             while 0 == n % i:
#                 n //= i
#             res *= 1-1/i
#         i += 1
#     if 1 != n:
#         res *= 1-1/n

#     return int(res)


def quickPower(a, b, mod):
    res = 1
    base = a

    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1

    return res


MOD = int(1e9)+7  # 质数
n, m = map(int, input().split())


# 根据欧拉公式，原来的指数转化为 m! % phi(MOD)
# MOD 是质数， phi(MOD) == MOD - 1
power = 1
for i in range(1, 1+m):
    power = (power*i) % (MOD-1)

print(quickPower(n, power, MOD))
