# 自底向上的动态规划 先计算子再计算父的值
# 链接
# 映射到这个题目里面就是写循环一层一层往上套
n = int(input())
a, b = 1, 1

if n == 1 or n == 2:
    print(1)
else:
    for i in range(2, n):
        c = b
        b = a + b
        a = c
    print(b)
