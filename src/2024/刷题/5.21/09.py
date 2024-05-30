# 乘法逆元
# https://www.lanqiao.cn/problems/1157/learning/


# N 是一个大质数，所以根据欧拉定理，a * (a ** (phi(N) - 1)) === 1 (mod N)
# 用快速幂算法即可求出
def quickPower(n, m, p):
    res = 1
    while m > 0:
        if m & 1:
            res = (res*n) % p
        n = (n*n) % p
        m >>= 1
    return res


N = 10**9+7

T = int(input())
for _ in range(T):
    a = int(input())
    # N 是质数，所以 phi(N) 为 N-1
    print(quickPower(a, N-1-1, N))
