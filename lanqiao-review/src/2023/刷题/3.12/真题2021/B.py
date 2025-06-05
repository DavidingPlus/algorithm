# 创建二维数组存储这些点
points = [[x, y] for x in range(20) for y in range(21)]  # 可以这样定义二维数组

# 遍历二维数组中所有的两个点找到所有的直线解 利用斜率和截距公式
# 用一个不重复的列表(也就是集合)才存入斜率和截距
# 这里不知道为什么用列表会超时 用集合就不会
k_b_list = set()
for i in points:
    for j in points:
        x1, y1 = i[0], i[1]
        x2, y2 = j[0], j[1]
        # 计算斜率和截距
        # 注意斜率可能为正无穷 这就是特殊的20条斜率为正无穷的直线
        if x1 == x2:
            continue
        k = (y1 - y2) / (x1 - x2)
        b = (x2 * y1 - x1 * y2) / (x2 - x1)
        # if (k, b) not in k_b_list: #由于集合不重复那么这句话判断无所谓
        k_b_list.add((k, b))
print(len(k_b_list) + 20)
