# 快速幂求余数
def quickPowerMod(base: int, power: int, mod: int):
    if 0 == power:
        return 1

    if power & 1:
        return (base * quickPowerMod(base, power-1, mod)) % mod
    else:
        tmp = quickPowerMod(base, power//2, mod)
        return (tmp*tmp) % mod


print(quickPowerMod(20190324, 7835954031267158017, 1001733993063167141))
