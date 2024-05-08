# 货物摆放
# 先找到n的所有因数 从1遍历到sqrt(n)即可，因为n//这个数必然也是因数
factor = list()
n = int(input())
for i in range(1, int(n**0.5) + 1):
    if n % i == 0:
        factor.append(i)
        # 这里要注意不要重复 重复可能是因为n是完全平方数比如4=2*2
        if i != n // i:
            factor.append(n // i)

count = 0
# 两层循环 如果第三个能被n整除那么必然可以
# 运行时间 3秒多
for i in factor:
    for j in factor:
        if n % (i * j) == 0:
            count += 1
print(count)
