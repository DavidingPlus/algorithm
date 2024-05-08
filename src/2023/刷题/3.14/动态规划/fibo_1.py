# fibo数列 自顶向下的备忘录法
# 基本思想:
# 创建了一个n+1大小的数组来保存求出的斐波拉契数列中的每一个值，在递归的时候如果发现前面fibo（n）的值计算出来了就不再计算，
# 如果未计算出来，则计算出来后保存在一个Meno数组中，下次在调用fibo（n）的时候就不会重新递归了。

n = int(input())
Meno = [0] * n


def fibo(n):
    if n == 1 or n == 2:
        Meno[n - 1] = 1
        return 1
    # 没计算出来的时候Meno数组里的值是0
    if Meno[n - 1] == 0:  # 没计算出来
        Meno[n - 1] = fibo(n - 1) + fibo(n - 2)
        return Meno[n - 1]
    # 计算出来
    return Meno[n - 1]


ans = fibo(n)
print(ans)
