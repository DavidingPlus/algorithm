# 利用埃式筛法筛选素数
# 见 08-埃式筛法.png

# 求 2 到 n 中的所有素数
def getPrime(n: int) -> list:
    prime = []
    isPrime = [True for _ in range(1+n)]
    for i in range(2, 1+n):
        if isPrime[i]:
            prime.append(i)
            for j in range(i+i, 1+n, i):
                isPrime[j] = False
    return prime


print(getPrime(100))
