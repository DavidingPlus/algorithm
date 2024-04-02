# 递归快速幂取余算法（求一个数的次方，也就是个大数对某个数的取模）
def quickPowModRecursion(a, n, mod):
    # 递归出口
    if 0 == n:
        return 1
    # 下面的推导会用到一个公式，两个数乘积除以某个数的余数，等于这两个数分别取余再相乘再取余；因此就可以递归了
    elif n % 2 == 1:
        return quickPowModRecursion(a, n - 1, mod) * a % mod
    else:
        tmp = quickPowModRecursion(a, n / 2, mod) % mod
        return tmp * tmp % mod


a, n, mod = 20190324, 7835954031267158017, 1001733993063167141
print(quickPowModRecursion(a, n, mod))  # 579706994112328949
