#喝饮料 喝三瓶换一瓶
n = int(input())

count = 0
#创建一个列表
drink_list = [1] * n

flag = 0
while len(drink_list) != 0:
    drink_list.pop()
    count += 1
    flag += 1
    if flag == 3:
        drink_list.append(1)
        flag = 0

print(count)