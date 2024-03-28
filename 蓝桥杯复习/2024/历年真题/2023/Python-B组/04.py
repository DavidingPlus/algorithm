# https://www.lanqiao.cn/problems/3544/learning/?subject_code=3&group_code=4&match_num=14&match_flow=1&origin=cup&page=1

n, size = map(int, input().split(' '))
water = [0] * size
L = [[] for _ in range(n)]
for i in range(n):
    L[i] = list(map(int, input().split(' ')))
    # 题目中 Li 代表的是第 i 段，实际的下标要减 1
    L[i][0] -= 1

# 开始灌水，每走一步代表过了一单位时间
time = 0
while 0 == min(water):
    time += 1
    # 遍历 L 数组，修改 water 数组 +1 代表有水进入
    for i in range(n):
        if time >= L[i][1]:
            if L[i][0] - (time - L[i][1]) >= 0:
                water[L[i][0] - (time - L[i][1])] += 1
            if L[i][0] + (time - L[i][1]) <= size - 1:
                water[L[i][0] + (time - L[i][1])] += 1
        if 0 != min(water):  # 做了一点小优化，当某次放水就放满了就直接返回
            break

print(time)
