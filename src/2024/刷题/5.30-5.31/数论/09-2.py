# 组合数 2 （公式法 + 逆元 + 打表）
# https://www.acwing.com/file_system/file/content/whole/index/content/4412/

def quickPower(a, b, mod):
    res = 1
    base = a

    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1

    return res


# 注意，以下除法都是整除， a//b % mod == a*(b 的逆元) % mod
# 例如 (6 // 3) % 5 == 2 ， 3 对于 5 的逆元是 7 ，(6 * 7) % 5 == 2
# C(a, b) == a! // (b! * (a-b)!) ，需要求出 b 阶乘的逆元和 a-b 阶乘的逆元

MOD = int(1e9)+7

# 打表记录 [1, 2000] 的所有阶乘取模和逆元阶乘取模
MAX = 2000
fac = [1 for _ in range(1+MAX)]
facNi = [1 for _ in range(1+MAX)]

for i in range(1, 1+MAX):
    fac[i] = (fac[i-1]*i) % MOD
    facNi[i] = (facNi[i-1]*quickPower(i, MOD-2, MOD)) % MOD

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    print((fac[a]*facNi[b]*facNi[a-b]) % MOD)
