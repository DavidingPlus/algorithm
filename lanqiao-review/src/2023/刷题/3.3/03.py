# 问题描述:
# Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
# 当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
# 输入格式:
# 输入包含一个整数n。
# 输出格式:
# 输出一行，包含一个整数，表示Fn除以10007的余数。

import math

n = int(input())


def fibo(n: int) -> int:
    if n == 1 or n == 2:
        return 1
    return (fibo(n - 1) + fibo(n - 2)) % 10007


print(fibo(n))
