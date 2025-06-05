# 给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
n = int(input())
num_list = list(map(int, input().split(' ')))

num_list.sort(reverse=False)  #False代表从小到大输出
for num in num_list:
    print(num, end=' ')  #end可以指定输出字符的格式 是换行还是空格
print('\n')
