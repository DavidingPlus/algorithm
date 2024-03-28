# 小蓝有一个数字矩阵，里面只包含数字 0 和 2。小蓝很喜欢 2020，他想找到这个数字矩阵中有多少个 2020 。 小蓝只关注三种构成 2020 的方式：
# • 同一行里面连续四个字符从左到右构成 2020。
# • 同一列里面连续四个字符从上到下构成 2020。
# • 在一条从左上到右下的斜线上连续四个字符，从左上到右下构成 2020。
# 例如，对于下面的矩阵：
# 2 2 0 0 0 0
# 0 0 0 0 0 0
# 0 0 2 2 0 2
# 0 0 0 0 0 0
# 0 0 0 0 2 2
# 0 0 2 0 2 0
# 一共有 5 个 2020。
# 其中 1 个是在同一行里的，1 个是在同一列里的，3 个 是斜线上的。 小蓝的矩阵比上面的矩阵要大，由于太大了，他只好将这个矩阵放在了一个文件里面，在试题目录下有一个文件 2020.txt，里面给出了小蓝的矩阵，请问有多少个2020？

# TODO
fs = open(file="D://Code//蓝桥杯//备战//3.13//3_2020.txt", mode="r", encoding="utf-8")
# 这么读可以去掉每行后面的换行符
nums = fs.read().splitlines()
# 除了最后一行其他全是以'\n'结尾
fs.close()
# print(nums)

ans = 0

# 先得到该矩阵的参数
n = len(nums[0])
# 按行枚举
for i in range(n):
    for j in range(n - 3):
        if (
            nums[i][j] == "2"
            and nums[i][j + 1] == "0"
            and nums[i][j + 2] == "2"
            and nums[i][j + 3] == "0"
        ):
            ans += 1

# 按列枚举
for j in range(n):
    for i in range(n - 3):
        if (
            nums[i][j] == "2"
            and nums[i + 1][j] == "0"
            and nums[i + 2][j] == "2"
            and nums[i + 3][j] == "0"
        ):
            ans += 1

# 按斜线枚举 斜线枚举的情况下只有 n-3 参数的矩阵可以不越界
for i in range(n - 3):
    for j in range(n - 3):
        if (
            nums[i][j] == "2"
            and nums[i + 1][j + 1] == "0"
            and nums[i + 2][j + 2] == "2"
            and nums[i + 3][j + 3] == "0"
        ):
            ans += 1

print(ans)
