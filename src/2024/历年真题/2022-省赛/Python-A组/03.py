# https://www.lanqiao.cn/problems/2155/learning/?page=1&first_category_id=1&second_category_id=3&name=%E8%B4%A8%E5%9B%A0%E6%95%B0
# 按照分解质因数的思维去做
n = int(input())


def isPrime(n):
    if n <= 1:
        return False
    i = 2
    while i * i <= n:
        if 0 == n % i:
            return False
        i += 1
    return True


i = 1
num = 0
while i * i <= n:
    if 0 == n % i:
        if isPrime(i):
            num += 1
        if isPrime(n // i):
            num += 1
    i += 1
print(num)
