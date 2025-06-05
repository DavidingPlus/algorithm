# 杨辉三角形
n = int(input())
ans = 0
# 将值存到一个二维数组当中
# 创建二维数组
num_matrix = [[1], [1, 1]]  # 初始化一个2*2的一阵 本质是一个列表嵌套列表!!!
# list([elem]*n for i in range(m)) m行n列!!!
# 用一个数组存数据
num_list = [1, 1, 1]
if n == 1:
    ans = 1

# 不是1就说明至少从第三行开始 第三行的row为2
else:
    row = 2
    while True:
        # 第row行
        num_matrix.append([1] * (row + 1))
        # 在每一行最开始压入一个1
        num_list.append(1)
        for j in range(1, row):
            num_matrix[row][j] = num_matrix[row - 1][j - 1] + num_matrix[row - 1][j]
            num_list.append(num_matrix[row][j])
        # 在每一行最末尾压入一个1
        num_list.append(1)
        if n not in num_list:
            row += 1
        else:
            ans = num_list.index(n) + 1
            break
print(ans)
