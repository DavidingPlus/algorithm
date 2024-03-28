# https://www.lanqiao.cn/problems/1449/learning/?page=1&first_category_id=1&name=%E7%9B%B4%E7%BA%BF

# 由于这是一个填空题目，直接暴力了，遍历即可

def calc(x1, y1, x2, y2):
    # 注意斜率为正无穷的情况，这种情况返回一个预先设计好的特殊值即可，与 k 和 b 区分，又可以判断是否相等，因此返回 x1 即可
    if x1 == x2:
        return [x1]
    return [(y2-y1)/(x2-x1), (x2*y1-x1*y2)/(x2-x1)]


ans = 0
m = 20
n = 21
# 将点存储下来
points = []
for i in range(m):
    for j in range(n):
        points.append([i, j])
# 用列表记录已经出现过的直线数据
l = []
for i in range(len(points)):
    for j in range(i+1, len(points)):
        res = calc(points[i][0], points[i][1], points[j][0], points[j][1])
        if not res in l:
            l.append(res)
print(len(l))
# print(40257)
