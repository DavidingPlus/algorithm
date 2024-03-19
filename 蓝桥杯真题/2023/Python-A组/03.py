# https://www.lanqiao.cn/problems/3518/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup&page=1

n = int(input())

# 读取数据
data = [list(map(int, input().split())) for _ in range(3)]

# 初始化胜利贡献数组
wins = [[0] * n for _ in range(3)]

# 计算胜利贡献数组
for i in range(n):
    wins[0][i] = data[0][i] - data[1][i] - data[2][i]
    wins[1][i] = data[1][i] - data[0][i] - data[2][i]
    wins[2][i] = data[2][i] - data[0][i] - data[1][i]

# 对胜利贡献数组进行排序
for i in range(3):
    wins[i].sort(reverse=True)

# 寻找答案
ans = -1
for i in range(3):
    num = 0
    for j in range(n):
        num += wins[i][j]
        if num <= 0:
            ans = max(ans, j)
            break

# 输出结果
if ans == 0:
    ans = -1
print(ans)
