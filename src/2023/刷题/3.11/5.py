# num1=6.00000
# num2=6
# print(type(num1)) #float
# print(type(num2)) #int
# print(num1==num2) #True

# 给定一个正整数n, 请找到最小的正整数x,使得它们的乘积是一个完全平方数。

n = int(input())
# 暴力会超时
# 注意到x==n时必然成立，但是x不一定最小，将x进行质因数分解，那么最小的x必然是n的因数
# 答案的最大值就是n本身，如果将n质因数分解的过程中可以找到一个完全平方数，那么n除以这个完全平方数也是满足条件的x解,将完全平方数加大直到完全平方数比n大则停止，这就是优化
j = 2
ans = n
while True:
    if n / (j**2) == n // (j**2):
        ans = n // (j**2)
    j += 1
    if j**2 > n:
        break

print(ans)
