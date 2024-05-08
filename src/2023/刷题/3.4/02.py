#给定n个数,找到这n个数的最大值,最小值,和
n = int(input())
num_list = list(map(int, input().split(' ')))

print(max(num_list))
print(min(num_list))
print(sum(num_list))
