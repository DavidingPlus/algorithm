# https://www.lanqiao.cn/problems/3532/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup

# 之前的版本，主要是学习这个排序规则的写法
# n = int(input())
# nums = [[] for _ in range(n)]
# for i in range(n):
#     nums[i] = list(map(int, input().split(' ')))
# # 排序规则：按照第一个参数升序，当第一个参数相同的时候按照第二个参数升序来，注意下面的写法
# nums = sorted(nums,key= lambda e:(e[0],e[1]),reverse= False)

n = int(input())
# nums 是一个大小为 10 的数组，下标就代表每个数，里面存储的就是权重，按照递增的方式来
nums = [[] for _ in range(10)]
for i in range(n):
    a, b = map(int, input().split(' '))
    nums[a].append(b)
# 进行排序
for i in range(10):
    nums[i].sort(reverse=False)

# 最终所有数应该出现的次数
count = n // 10
ans = 0
# 开始修改
for i in range(10):
    if count < len(nums[i]):
        for j in range(len(nums[i])-count):
            ans += nums[i][j]
print(ans)
