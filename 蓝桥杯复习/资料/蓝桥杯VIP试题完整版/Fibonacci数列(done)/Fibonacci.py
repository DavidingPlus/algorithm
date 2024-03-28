# 思路: 递归 第n-1项除以10007的玉树加上第n-2项的余数
def Fibonacci_n_10007(n: int) -> int:
    if n == 1 or n == 2:
        return 1
    else:
        return Fibonacci_n_10007(n-1) % 10007+Fibonacci_n_10007(n-2) % 10007


n = int(input())
# 求第n项除以10007的余数
print(Fibonacci_n_10007(n))
