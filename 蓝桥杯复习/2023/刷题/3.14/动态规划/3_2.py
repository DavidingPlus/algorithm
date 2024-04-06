# 自底向上用循环做
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

# 定义一个列表来存长度和该长度下对应的最大价格
len_money = [(0, 0), (1, 1)]
n = int(input())

for i in range(2, n + 1):
    # 同样到一半就可以了
    money = length_price[i][1]
    for j in range(1, i // 2 + 1):
        if money < len_money[j][1] + len_money[i - j][1]:
            money = len_money[j][1] + len_money[i - j][1]
    len_money.append((i, money))
print(money)
