# 递归快速幂取余算法（对大素数取模）
def qPowMod(a, n, mod):
    if n == 0:
        return 1
    elif n % 2 == 1:
        return qPowMod(a, n - 1, mod) * a % mod
    else:
        temp = qPowMod(a, n / 2, mod) % mod
        return temp * temp % mod


a, n, mod = 20190324, 7835954031267158017, 1001733993063167141
print(qPowMod(a, n, mod))  # 579706994112328949
