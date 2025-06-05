# 153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求所有满足这种条件的三位十进制数。

for n in range(100, 1000):
    #将其转化为列表 注意列表元素是字符
    num_list: str = list(str(n))
    sum = 0
    for elem in num_list:
        sum += pow(ord(elem) - ord('0'), 3)
    if sum == n:
        print(n)
