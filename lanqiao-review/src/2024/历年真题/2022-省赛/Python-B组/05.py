# https://www.lanqiao.cn/problems/2134/learning/?page=1&first_category_id=1&name=%E8%9C%82%E5%B7%A2


from math import cos, sin, pi

# 将给定的坐标转化为直角坐标系（适用于本题的坐标系，与 xoy 不太一样，但差不多）
# 例如东偏北 60 度走 1 步， x 加 0.5 ，y 加 1（直角坐标系中是根号 3 ），这样有助于将实际斜着的运动轨迹投影到 y 轴


def convert(d, p, q):
    # 先向 d 方向走 p 步，其中 d 的 0 表示正西，也就是 pi
    x = p * cos(pi - d * pi / 3)
    y = p * sin(pi - d * pi / 3) / sin(pi / 3)
    # 再向 d+2 方向走 q 步
    x += q * cos(pi - (d + 2) * pi / 3)
    y += q * sin(pi - (d + 2) * pi / 3) / sin(pi / 3)
    # 可能有精度问题，保留两位小数就行
    return [round(x, 2), round(y, 2)]


# 测试数据
# 1 304 126 1 134 80 -> 170

d1, p1, q1, d2, p2, q2 = map(int, input().split(' '))
point1, point2 = convert(d1, p1, q1), convert(d2, p2, q2)

# 根据坐标规则计算最短距离
relX = point2[0] - point1[0]
relY = point2[1] - point1[1]

# 先移动 y 方向
ans = abs(relY)
# 再看 x 方向
# 注意一点，由于在实际移动的过程中移动 y 必然会带着 x 方向的移动，因此对于实际情况，y 方向移动之后，[-relY / 2, relY / 2] 的位置都能到达!!!这就是最开始的问题所在
if abs(relX) <= abs(relY) / 2:
    pass  # 能直接到达，do nothing
else:
    ans += abs(abs(relX) - abs(relY/2))
print(int(ans))
