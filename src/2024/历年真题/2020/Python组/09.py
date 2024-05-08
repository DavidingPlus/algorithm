# https://www.lanqiao.cn/problems/503/learning/?page=1&first_category_id=1&name=%E5%B9%B3%E9%9D%A2%E5%88%87%E5%88%86


# 测试数据
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
# 结果： 36

# 题目规定 斜率 A 不为正无穷，因此可以用解析式
# 题目保证两条直线不为同一条
def calcPoint(k1, b1, k2, b2) -> set:
    if k1 == k2:
        return (-1)
    return (-1 * (b1 - b2) / (k1 - k2), (k1 * b2 - k2 * b1) / (k1 - k2))


# 在目前的图形基础上加入一条直线，增加的部分个数 = 1 + 该直线与其他直线的交点个数（在新产生的交点里面需要考虑重复）
ans = 1
lines = []
n = int(input())
for i in range(n):
    k, b = map(int, input().split())
    # 这个题目有病吧，他后面输入的直线还有可能和前面重复的。。。
    if [k, b] in lines:
        continue

    # python 中的 set 可以自动去重，符号是 ()
    points = set()
    for e in lines:
        point = calcPoint(k, b, e[0], e[1])
        if (-1) != point:
            points.add(point)
    ans += 1 + len(points)
    lines.append([k, b])
print(ans)
