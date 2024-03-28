n = int(input())
num_list = list(map(int, input().split(' ')))

#用一个变量存储num_list所有的值相加的和 这样后面求和就只用算一个减法了 大大减少了时间复杂度!!!
num_sum = 0
for i in range(n):
    num_sum += num_list[i]

sum = 0
for i in range(n):
    num_sum -= num_list[i]
    sum += num_list[i] * num_sum

print(sum)
