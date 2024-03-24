# https://www.lanqiao.cn/problems/2154/learning/?page=1&first_category_id=1&name=%E7%9F%A9%E5%BD%A2%E6%8B%BC%E6%8E%A5

# 即使是最差的情况，也能有八条边
# 最终的答案只可能是 4 6 8
# 六条边：
# 1. 两个矩形的某两边和加起来等于另一个矩形的某条边，并且这两个矩形的另外两边不相等
# 2. 任意两边且仅两边相等
# 四条边：
# 1. 上面情况 六条边的情况 1 的另外两边相等
# 2. 三个矩形的某三边相等
# 八条边：剩余情况

# 判断三个矩形是否存在某三边相等
def triEqual(rect1: list, rect2: list, rect3: list) -> bool:
    return (rect1[0] in rect2 and rect1[0] in rect3) or (rect1[1] in rect2 and rect1[1] in rect3)


# 判断两个矩形的某两边和能否等于另一个矩形的某条边
# 等于返回 True ，如果另外两边相等，再次返回一个 True
# 因此，三种返回情况： [False]; [True, True]; [True, False]
def douSum(rect1: list, rect2: list, rect3: list) -> list:
    # rect1 加上 rect2
    flag = False
    for i in range(2):
        for j in range(2):
            # 这三个判断是平行的，因此不是 elif
            if rect1[i] + rect2[j] in rect3:
                # 这里不能直接 return ，因为前面不满足不代表后面就不满足了，只是遇到四边形的情况就可以直接返回了，我们关心的是八边形还是六边形，因此用 flag 记录
                flag = True
                if rect1[1-i] == rect2[1-j]:
                    return [True, True]
            if rect2[i] + rect3[j] in rect1:
                flag = True
                if rect2[1-i] == rect3[1-j]:
                    return [True, True]
            if rect3[i] + rect1[j] in rect2:
                flag = True
                if rect3[1-i] == rect1[1-j]:
                    return [True, True]
    return [False] if False == flag else [True, False]


# 判断是否两个矩形的两边相等（仅两边而不是三边）
def douEqual(rect1: list, rect2: list, rect3: list) -> list:
    return 1 == (rect1[0] in rect2) + (rect1[0] in rect3) or 1 == (rect1[1] in rect2) + (rect1[1] in rect3) or 1 == (rect2[0] in rect1) + (rect2[0] in rect3) or 1 == (rect2[1] in rect1) + (rect2[1] in rect3) or 1 == (rect3[0] in rect1) + (rect3[0] in rect2) or 1 == (rect3[1] in rect1) + (rect3[1] in rect2)


n = int(input())
for i in range(n):
    a1, b1, a2, b2, a3, b3 = map(int, input().split(' '))
    # 四边形
    if True == triEqual([a1, b1], [a2, b2], [a3, b3]) or [True, True] == douSum([a1, b1], [a2, b2], [a3, b3]):
        print(4)
    elif [True, False] == douSum([a1, b1], [a2, b2], [a3, b3]) or True == douEqual([a1, b1], [a2, b2], [a3, b3]):
        print(6)
    else:
        print(8)
