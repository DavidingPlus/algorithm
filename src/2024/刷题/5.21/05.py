# 2023 次方
# https://www.lanqiao.cn/problems/17095/learning/?page=1&first_category_id=1&name=2023%E6%AC%A1%E6%96%B9

from math import gcd
from sys import setrecursionlimit


# 欧拉函数
def phi(n: int) -> int:
    res = float(n)
    i = 2
    while i*i <= n:
        if 0 == n % i:
            while 0 == n % i:
                n /= i
            res *= 1-1/i
        i += 1
    if 1 != n:
        res *= 1-1/n
    return int(res)


# 快速幂算法
def quickPower(n, m, p):
    res = 1
    while m > 0:
        if m & 1:
            res = (res*n) % p
        n = (n*n) % p
        m >>= 1
    return res


# 欧拉定理推论
def f(a, b, n):
    # 递归出口
    if a+1 == b:
        return quickPower(a, b, n)

    # 递归公式推导见图 xxx
    m = f(a+1, b, phi(n))
    # 如果 a 和 n 互质，那么 a**phi(n) 为 1
    if 1 != gcd(a, n):
        m += phi(n)
    return quickPower(a, m, n)


# 设置递归深度，默认是 1000 ，显然不够
setrecursionlimit(2023+10)

print(f(2, 2023, 2023))
# print(869)
