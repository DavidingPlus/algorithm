# X 质数
# https://www.lanqiao.cn/problems/17128/learning/

# 先筛选质数
N = 1000000
isPrime = [True for _ in range(1+N)]
isPrime[0], isPrime[1] = False, False
for i in range(2, 1+N):
    if isPrime[i]:
        for j in range(i+i, 1+N, i):
            isPrime[j] = False

# 利用二进制枚举思想来表示每一位删或者不删
ans = 0
for num in range(1, 1+N):
    l = [int(ch) for ch in str(num)]
    for i in range(1 << len(l)):
        e = 0
        for j in range(len(l)):
            if i & (1 << j):
                e = 10*e + l[j]
        if isPrime[e]:
            ans += 1
            break

print(ans)
# print(989457)
