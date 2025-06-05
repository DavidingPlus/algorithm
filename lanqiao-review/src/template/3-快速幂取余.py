# 递归快速幂取余算法（求一个数的次方，也就是个大数对某个数的取模）
def quickPowModRecursion(base: int, power: int, mod: int) -> int:
    # 递归出口
    if 0 == power:
        return 1
    # 下面的推导会用到一个公式，两个数乘积除以某个数的余数，等于这两个数分别取余再相乘再取余；因此就可以递归了
    elif power & 1:
        return (base * quickPowModRecursion(base, power - 1, mod)) % mod
    else:
        tmp = quickPowModRecursion(base, power // 2, mod) % mod
        return (tmp * tmp) % mod


# 非递归快速幂取余算法（利用位运算，迭代）
# 以 2 ** 5 次方为例，5 的二进制为 101，并且发现 2 ** 5 == (2 ** (2 ** 2)) * (2 ** (2 ** 0))
# 而每一位的指数对应的值都是按指数增长的，比如 2**(2**0) ， 2**(2**1) ， 2**(2**2) ， 2**(2**3) ，每一个都是上一个的平方，这就是状态转移方程
# 这里的 a, n ,mod 都是基本数据类型，pass by value，不会改变形参，可以直接修改
def quickPowModNoRecursion(base: int, power: int, mod: int) -> int:
    res = 1
    while power > 0:
        if power & 1:  # 得到末尾结果是 1 还是 0 ，以此判断该位是否需要乘上去
            res = (res * base) % mod
        base = (base * base) % mod  # base 每次平方，到达当前位的时候才是正确的底数
        power >>= 1  # 指数后移，得到每一位的 01 值
    return res


a, n, mod = 20190324, 7835954031267158017, 1001733993063167141
print(quickPowModRecursion(a, n, mod))  # 579706994112328949
print(quickPowModNoRecursion(a, n, mod))  # 579706994112328949
