# 判断一个数是否为质数
def isPrime(n):
    if n < 2:
        return False

    i = 2
    while i*i <= n:
        if 0 == n % i:
            return False
        i += 1
    return True


print(isPrime(4))
print(isPrime(89))


# 判断 1 到 n 之间（包括 n 这个数）有多少个素数（厄拉多塞筛法）：
def countPrim(n):
    count = 0
    signs = [True] * (1+n)  # 先假设全为质数

    for i in range(2, 1+n):
        if signs[i]:
            count += 1
            # 质数的倍数一定不是质数，置为False ，通过最开始的质数一步步将合数剔除掉，这是比较快的做法
            for j in range(i+i, 1+n, i):
                signs[j] = False
    return count


print(countPrim(5))  # 2 3 5
