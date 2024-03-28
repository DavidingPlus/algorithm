n, m = map(int, input().split(" "))

# 用一个列表嵌套列表来存储元素
src_list = list()
for i in range(n):
    line_list = list(map(int, input().split(" ")))
    src_list.append(line_list)


def get_value(i, j):
    value = 0
    count = 0
    for line in range(-1, 2):
        for row in range(-1, 2):
            try:
                # 判断上面是不是越界了
                src_list[i + line][j + row]
            except IndexError:
                pass
            else:
                # 判断下界用IndexError异常会失败 因为在python当中列表lists[-1]表示最后一个!!!!而不是IndexError 后面以此类推!!!
                # 所以判断上界和下界的方法是不一样的
                if i + line < 0 or j + row < 0:
                    pass
                else:
                    value += src_list[i + line][j + row]
                    count += 1
    # 结果
    # 注意可能value为0并且count为0 出现0除以0需要排除
    if value == 0:
        return 0
    else:
        return int(value / count)


# 现在创建一个新的列表嵌套列表来存储模糊结果
ans_list = list()
for i in range(n):
    line_list = list()
    for j in range(m):
        # 计算某一点的模糊结果
        line_list.append(get_value(i, j))
    ans_list.append(line_list)

# 打印
for i in range(n):
    for j in range(m):
        print(ans_list[i][j], end=" ")
    print(end="\n")
