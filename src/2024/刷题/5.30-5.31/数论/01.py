# 利用埃式筛法筛选素数

# 筛选 [1, n] 范围内的所有素数列表
def prime(n):
    isPrime = [True for _ in range(1+n)]
    isPrime[0], isPrime[1] = False, False
    res = []

    for i in range(2, 1+n):
        if isPrime[i]:
            res.append(i)
            for j in range(i+i, 1+n, i):
                isPrime[j] = False

    return res


print(prime(int(1e5)))
