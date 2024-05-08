# 测试数据
# 5
# 7
# 3 8
# 8 1 0
# 2 7 4 4
# 4 5 2 6 5

# 6
# 1
# 2 3
# 7 5 6
# 4 3 2 3
# 5 6 5 7 4
# 7 8 9 6 10 9

n = int(input())
angle_list = list()
for i in range(n):
    angle_list.append(list(map(int, input().split(" "))))


ans_list = list()
for i in range(n):
    if i == 0:
        ans_list.append(angle_list[0])
    else:
        # 该层的数等于该数字上面那个左上方那个
        # 先判断上面的两个数字是否存在
        line_list = list()
        for j in range(i + 1):
            num1, num2 = 0, 0
            # 查看是否越界 只可能越一个界
            # 先看左上的
            if j - 1 >= 0:
                num1 = ans_list[i - 1][j - 1]
            # 再看正上方
            if j <= i - 1:
                num2 = ans_list[i - 1][j]
            line_list.append(max(num1, num2) + angle_list[i][j])
        ans_list.append(line_list)

# print(ans_list)
# 由于向左下走的次数与向右下走的次数相差不能超过1，所以肯定在中间的位置附近
mid = n // 2
if n % 2 == 1:
    ans = ans_list[n - 1][mid]
else:
    ans = max(ans_list[n - 1][mid - 1], ans_list[n - 1][mid])

print(ans)
