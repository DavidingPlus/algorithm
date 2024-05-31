from sys import setrecursionlimit

setrecursionlimit(int(1e8))


# 快速幂求余数
# 递归版
# def quickPower(a: int, b: int, mod: int):
#     if 0 == b:
#         return 1

#     if b & 1:
#         return (a * quickPower(a, b-1, mod)) % mod
#     else:
#         tmp = quickPower(a, b//2, mod)
#         return (tmp*tmp) % mod

# 迭代版（记住）
def quickPower(a, b, mod):
    res = 1
    base = a

    while b > 0:
        if b & 1:
            res = (res*base) % mod
        base = (base*base) % mod
        b >>= 1

    return res


print(quickPower(20190324, 7835954031267158017, 1001733993063167141))
