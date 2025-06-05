# https://www.lanqiao.cn/problems/603/learning/?page=1&first_category_id=1&name=RSA%E8%A7%A3%E5%AF%86


# 递归快速幂取余算法（对大素数取模）
def quickPowModRecursion(a, n, mod):
    if n == 0:
        return 1
    elif n % 2 == 1:
        return quickPowModRecursion(a, n - 1, mod) * a % mod
    else:
        temp = quickPowModRecursion(a, n / 2, mod) % mod
        return temp * temp % mod


n = 1001733993063167141
d = 212353
C = 20190324

# n = p * q 先把他们找出来，p, q 是质数，因此 n 的因式分解除了 1 * n 和 p * q 就没有其他的了
# 程序见 05_1.cpp
p = 891234941
q = 1123984201

# d * e 除以 (p-1) 和 (q-1) 乘积的余数为 1，并且符合解密和加密的条件
# 倍数从 1 开始试，枚举出符合条件的 e ，cpp 程序越界，就在 py 下了
# 这里有多个 e ，我找出第一个 e 看下
i = 1
while True:
    if 0 == (i * (p - 1) * (q - 1) + 1) % d:
        e = (i * (p - 1) * (q - 1) + 1) // d
        X = quickPowModRecursion(C, e, n)
        if C == quickPowModRecursion(X, d, n):
            print(X)
            break
    i += 1

# print(579706994112328949)
