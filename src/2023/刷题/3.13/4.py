# 测试数据
# 3
# 1 1
# 2 2
# 3 3

# 10
# 1 2
# 7 8
# 1 4
# 9 6
# 4 6
# 5 1
# 1 8
# 1 4
# 5 6
# 5 8

# 还能重复插一条直线?????

# 平面切分
n = int(input())
stright_lines = list()
for i in range(n):
    k_b = tuple(map(int, input().split(" ")))
    # 去掉重复的直线 比如上面的1 4
    if k_b not in stright_lines:
        stright_lines.append(k_b)
n = len(stright_lines)
# print(stright_lines)

# 在有n个交点的情况下,新加入的直线与原来直线产生n个交点会多划分成为(n+1)个部分 注意该n个交点中可能含之前的交点,这n个交点不与之前已经有的交点判重，但是这些交点可能与多条直线交于同一个点，这个需要判重

# 第一条直线初始化信息
count = 2
# 后续进行循环
# 新加入第i条直线
for i in range(1, n):
    k1, b1 = stright_lines[i][0], stright_lines[i][1]
    # 从第一条直线开始求与新直线的交点
    points = set()
    for j in range(i):
        k2, b2 = stright_lines[j][0], stright_lines[j][1]
        # 如果k1==k2没有交点
        if k1 == k2:
            pass
        else:
            x = (b1 - b2) / (k2 - k1)
            y = (k2 * b1 - k1 * b2) / (k2 - k1)
            points.add((x, y))
    count += len(points) + 1

print(count)
