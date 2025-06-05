# 保险箱
# https://www.lanqiao.cn/courses/38752/learning/?id=2546143

from sys import maxsize

# 从低位到高位进行考虑，每一位变到目标值有三种做法，不进位不退位、进位、退位，三种做法都会对高位产生影响，而下一位同样有这些考虑，因此 dp 数组可以设计为从最低位开始，多少个位数相同的最小次数，因为每位有三种情况，因此另开一维存储
n = int(input())
x = input()[::-1]
y = input()[::-1]
a = []
b = []
for i in range(len(x)):
    a.append(int(x[i]))
    b.append(int(y[i]))

# 改为滚动数组
dp = [maxsize for _ in range(3)]

# 处理第一位
dp[0] = abs(a[0]-b[0])
dp[1] = (10-a[0])+(b[0]-0)
dp[2] = (a[0]-0)+(10-b[0])

for i in range(1, n):
    # 对于这一位有三种情况，每一种情况又可能从前一位的三种情况延申出来
    # 对于前一位的进位和退位，很简单，对于当前位的影响就是当位加 1 或者 减 1 而已，当前位做出操作以后会自动影响下一位的变化，这就是状态转移过程

    tmp = [maxsize for _ in range(3)]

    tmp[0] = min(abs(a[i]-b[i])+dp[0],
                 abs(a[i]+1-b[i])+dp[1],
                 abs(a[i]-1-b[i])+dp[2])

    tmp[1] = min((10-a[i])+(b[i]-0)+dp[0],
                 (10-(a[i]+1))+(b[i]-0)+dp[1],
                 (10-(a[i]-1))+(b[i]-0)+dp[2])

    tmp[2] = min((a[i]-0)+(10-b[i])+dp[0],
                 (a[i]+1-0)+(10-b[i])+dp[1],
                 (a[i]-1-0)+(10-b[i])+dp[2])

    dp = tmp

print(min(dp))
