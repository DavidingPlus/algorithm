# 组合数 2 （公式法 + 逆元 + 打表）
# https://www.acwing.com/file_system/file/content/whole/index/content/4412/

MOD = 10**9+7


def quickPower(base, power, mod):
    res = 1
    while power > 0:
        if power & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        power >>= 1
    return res


# 打表
fac = [1 for _ in range(1+10**5)]
facNi = [1 for _ in range(1+10**5)]

for i in range(1, 1+10**5):
    fac[i] = (fac[i-1]*i) % MOD
    facNi[i] = (facNi[i-1]*quickPower(i, MOD-1-1, MOD)) % MOD

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    ans = 1
    # 计算 a 阶乘的模
    ans = (ans*fac[a]) % MOD
    # 利用欧拉公式，计算 b 阶乘的逆元
    ans = (ans*facNi[b]) % MOD
    # 计算 a-b 阶乘的逆元
    ans = (ans*facNi[a-b]) % MOD

    print(ans)
