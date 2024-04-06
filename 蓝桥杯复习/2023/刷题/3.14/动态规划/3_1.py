# 递归思想
# 一次一次切 保证每次切一刀的钱最多
# 如果切出来没有原来的钱多 则不切
length_price = [
    (0, 0),
    (1, 1),
    (2, 5),
    (3, 8),
    (4, 9),
    (5, 10),
    (6, 17),
    (7, 17),
    (8, 20),
    (9, 24),
    (10, 30),
]

# 递归
# 备忘录优化
# 在递归的同时记录下长度为i时的分割位置 0代表不切 i代表一段长度是i
res_find = {0: 0}  # 第一个参数为长度 第二个参数为该长度下的最大的价格


def cut(len):
    if len == 1:
        return 1
    money = length_price[len][1]
    for i in range(1, len // 2 + 1):
        # 查询i值和len-i值在不在
        value1 = cut(i)
        value2 = cut(len - i)
        if i in res_find.keys():
            value1 = res_find[i]
        if len - i in res_find.keys():
            value2 = res_find[len - i]
        if money < value1 + value2:
            money = value1 + value2

    # 如果不在将其插入字典中
    if len not in res_find.keys():
        res_find[len] = money
    return money


length = int(input())
print(cut(length))
print(res_find)
