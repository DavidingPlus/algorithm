# 修改数组
# TODO
n = int(input())
num_list = list(map(int, input().split(" ")))

# 第一个不用管，从第二个开始
for i in range(1, n):
    while True:
        # try:
        #     new_list.index(num_list[i])
        # except ValueError:
        #     break
        # else:
        #     num_list[i] += 1
        if num_list[i] in num_list[:i]:
            num_list[i] += 1
        else:
            break

for elem in num_list:
    print(elem, end=" ")
print(end="\n")
