# 小明对数位中含有 2、0、1、9 的数字很感兴趣（不包括前导 0），在 1 到 40 中这样的数包括 1、2、9、10 至 32、39 和 40，共 28 个，他们的和是 574。
# 请问，在 1 到 n 中，所有这样的数的和是多少？
n = int(input())
count = 0
sum = 0

for i in range(1, n + 1):
    num_list = list()
    num_list += list(str(i))
    #遍历这个列表查找是否存在2 0 1 9
    for elem in num_list:
        if elem == '2' or elem == '0' or elem == '1' or elem == '9':
            count += 1
            sum += i
            break

print(f"一共{count}个")
print(f"和是{sum}")
