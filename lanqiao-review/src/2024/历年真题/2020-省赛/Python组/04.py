# https://www.lanqiao.cn/problems/594/learning/?page=1&first_category_id=1&name=%E8%9B%87%E5%BD%A2

# 填空题，按照题目规则填充数组即可
x, y = [0, 0]
ans = 1
directX = -1  # 记录沿 x 的变化趋势， y 预期相反

while True:
    # 循环出口
    if 19 == x and 19 == y:
        break

    # 模拟填充数组，换方向的条件是遇到边界，这个时候认为调整并且置为反方向即可
    ans += 1
    x, y = [x+directX, y-directX]
    # 显然，出界的情况下只能 x 出或者 y 出，不可能同时出
    if x < 0 or y < 0:
        if x < 0:
            x = 0
        if y < 0:
            y = 0
        directX *= -1
print(ans)
# print(761)
