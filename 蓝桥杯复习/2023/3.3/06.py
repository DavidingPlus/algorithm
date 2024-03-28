# 123321是一个非常特殊的数，它从左边读和从右边读是一样的。
# 输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n
# 暴力
n = int(input())

for i in range(10000, 1000000):
    #将其转化为字符串再转化为列表
    num_list = list(str(i))
    #先查看是不是回文数
    if num_list == num_list[::-1]:
        sum = 0
        for each in num_list:
            sum += ord(each) - ord('0')
        if sum == n:
            print(i)
