# https://www.lanqiao.cn/problems/505/learning/?page=1&first_category_id=1&name=%E6%95%B0%E5%AD%97%E4%B8%89%E8%A7%92%E5%BD%A2

# 由于某个点的路径最大值之和上层左边和右边的那个数有关，因此如果我们知道上面那两个数的最大值，就可以知道当前点的最大值，这就是动态规划的状态转移方程
n = int(input())
matrix = []
for i in range(n):
    matrix.append(list(map(int, input().split())))


# 定义 dp 数组，只需要存储上一层即可
dp = matrix[0]
for i in range(1, n):
    tmp = []
    for j in range(0, i+1):
        if 0 == j:
            tmp.append(dp[j] + matrix[i][j])
        elif i == j:
            tmp.append(dp[j-1]+matrix[i][j])
        else:
            tmp.append(max(dp[j-1], dp[j])+matrix[i][j])
    dp = tmp
if 1 == n % 2:
    print(dp[n//2])
else:
    print(max(dp[n//2 - 1], dp[n//2]))
