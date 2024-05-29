# https://www.lanqiao.cn/problems/17133/learning/


def quickPower(a, b, mod):
    res = 1
    base = a
    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1
    return res


MOD = 2146516019
ans = 0  # 0 异或任何数等于该数本身
for i in range(1, 1+233333333):
    ans ^= quickPower(i, MOD-2, MOD)

print(ans)
# print(1307261675)
