# 乘法逆元
# https://www.lanqiao.cn/problems/1157/learning/?page=1&first_category_id=1&name=%E4%B9%98%E6%B3%95%E9%80%86%E5%85%83

N = 10**9+7


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


T = int(input())
for _ in range(T):
    a = int(input())
    # N 是质数，所以 phi(N) 为 N-1
    print(quickPower(a, N-1-1, N))
