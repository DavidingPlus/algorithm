# X 质数
# https://www.lanqiao.cn/problems/17128/learning/

# 得到一个数字有多少位
def get(n):
    res = 0

    while n > 0:
        n //= 10
        res += 1

    return res


# 首先用筛法打表打出 [1, 1000000] 中是否为质数的列表，方便后续查询
MAX = 1000000
isPrime = [True for _ in range(1+MAX)]
isPrime[0], isPrime[1] = False, False

for i in range(2, 1+MAX):
    if isPrime[i]:
        for j in range(i+i, 1+MAX, i):
            isPrime[j] = False


# 对于每一个数字，使用二进制表示状态（类似于状压 DP 的状态表示方法）
ans = 0
for i in range(1, 1+MAX):
    cnt = get(i)
    l = [int(str(i)[j]) for j in range(cnt)]

    for i in range(1 << cnt):
        num = 0
        for j in range(cnt):
            if i & (1 << j):
                num = 10*num + l[j]

        if isPrime[num]:
            ans += 1
            break

print(ans)
# print(989457)
