# 2 的 2023 次方
# https://www.lanqiao.cn/problems/17095/learning/

from math import gcd
from sys import setrecursionlimit

setrecursionlimit(int(1e8))


def quickPower(a, b, mod):
    res = 1
    base = a
    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1

    return res


def phi(n):
    res = n

    i = 2
    while i*i <= n:
        if 0 == n % i:
            while 0 == n % i:
                n //= i
            res *= 1-1/i
        i += 1

    if 1 != n:
        res *= 1-1/n

    return int(res)


def f(a, b, mod):
    if a+1 == b:
        return quickPower(a, b, mod)

    power = f(a+1, b, phi(mod))
    if 1 != gcd(a, mod):
        power += phi(mod)

    return quickPower(a, power, mod)


print(f(2, 2023, 2023))
# print(869)
