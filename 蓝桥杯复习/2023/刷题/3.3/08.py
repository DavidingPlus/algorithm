# 下面给出了杨辉三角形的前4行：
#
# 1
# 1 1
# 1 2 1
# 1 3 3 1
# 给出n，输出它的前n行。

n = int(input())
#将值存到一个二维数组当中
#创建二维数组
num_list = list([1] * n for i in range(n))  #初始化一个n*n的一阵 本质是一个列表嵌套列表!!!
#list([elem]*n for i in range(m)) m行n列!!!
if n < 3:
    pass

else:
    for i in range(2, n):
        for j in range(1, i):
            num_list[i][j] = num_list[i - 1][j - 1] + num_list[i - 1][j]

for i in range(n):
    for j in range(0, i + 1):
        print(num_list[i][j], end=' ')
    print(end='\n')
