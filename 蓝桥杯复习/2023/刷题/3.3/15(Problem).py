#卡片
num_dict = dict()
for i in range(10):
    num_dict[str(i)] = 2021
print(num_dict)

num = 1
while True:
    for i in range(10):
        if num_dict[str(i)] <= 0:
            num -= 1
            break

    str_list = list(str(num))
    for each in str_list:
        num_dict[each] -= 1
    num += 1

print(num)
