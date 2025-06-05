# 欧拉函数

# 求出 [1, n] 中和 n 互质的个数
# 根据欧拉函数的公式，需要所有的质因数，使用筛法求解
def phi(n):
    res = n

    i = 2
    # 这里使用一个技巧，由反证法知道 n 的所有质因数中，大于 sqrt(n) 的质因数最多只有一个，因此这里的返回筛选到 sqrt(n) 即可（类似判断素数的条件），最后循环结束以后判断除法剩下的是不是 1 即可
    while i*i <= n:
        if 0 == n % i:
            while 0 == n % i:
                n //= i
            res *= 1-1/i
        i += 1

    if 1 != n:
        res *= 1-1/n

    return int(res)


print(phi(int(1e9)+7))
