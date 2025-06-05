# 乘法逆元
# https://www.lanqiao.cn/problems/1157/learning/

MOD = int(1e9)+7  # 质数，因此逆元是 a**(phi(MOD)-1) == a**(MOD-2)


def quickPower(a, b, mod):
    res = 1
    base = a

    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1

    return res


T = int(input())
for _ in range(T):
    N = int(input())
    print(quickPower(N, MOD-2, MOD))
