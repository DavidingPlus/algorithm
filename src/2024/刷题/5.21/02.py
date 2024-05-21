# 数的幂次
# https://www.lanqiao.cn/problems/1514/learning/?page=1&first_category_id=1&name=%E5%BF%AB%E9%80%9F%E5%B9%82

from functools import lru_cache


# 快速幂算法，这里使用递归的方法实现
@lru_cache(None)
def quickPower(n, m, p):
    if 0 == m:
        return 1
    if m & 1:
        return (quickPower(n, m-1, p) % p)*(n % p) % p
    else:
        tmp = quickPower(n, m//2, p) % p
        return tmp*tmp % p


# 快速幂算法，使用迭代实现（推荐）
def quickPower2(n, m, p):
    res = 1
    while m > 0:
        if m & 1:  # 这一位是 1 ，表示这一位参与计算
            res = (res * n) % p
        n = (n*n) % p  # 底数按平方扩张
        m >>= 1  # 右移一位
    return res


n, m, p = map(int, input().split())
# print(quickPower(n, m, p))
print(quickPower2(n, m, p))
