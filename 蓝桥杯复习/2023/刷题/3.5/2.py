#fibo变式
#前三项为1 第四项开始后面全是前三项的和 求第n项的最后四位数字
n = int(input())

#1.利用循环递推来做 这个时间之内能跑出来
a, b, c = 1, 1, 1
for i in range(4, n + 1):
    a1 = a
    b1 = b
    c1 = c
    #求最后四位数字 就是求除以10000的余数
    a = b1 % 10000
    b = c1 % 10000
    c = (a1 + b1 + c1) % 10000

print(c)

#2.利用递归 这个显然时间复杂度就起来了 因为调用了函数 还是递归
# def get_n_last_4(n: int) -> int:
#     if n == 1 or n == 2 or n == 3:
#         return 1
#     else:
#         return (get_n_last_4(n - 1) + get_n_last_4(n - 2) +
#                 get_n_last_4(n - 3)) % 10000

# print(get_n_last_4(n))