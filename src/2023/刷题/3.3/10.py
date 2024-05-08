# 利用字母可以组成一些美丽的图形，下面给出了一个例子：
# ABCDEFG
# BABCDEF
# CBABCDE
# DCBABCD
# EDCBABC
# 这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。

n, m = input().split()
n = int(n)
m = int(m)
#先初始化一个列表，里面的元素是字符串
word_list = list("" * m for i in range(n))  #也相当于初始化一个二维数组
for i in range(n):
    for j in range(m - i):
        word_list[i] += chr(ord('A') + j)
    word_list[i] = word_list[i][::-1]
    for j in range(i):
        word_list[i] += chr(ord('B') + j)
    word_list[i] = word_list[i][::-1]

#print
for i in range(n):
    print(word_list[i])