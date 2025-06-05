# https://www.lanqiao.cn/problems/3521/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup&page=1


# 通过单调队列求出数组当中滑动窗口的最大值和最小值数组
def slidingWindow(nums: list, k: int, maxOrMin: bool) -> list:
    res = []
    q = []
    # note： 其实这个严格意义来讲应该交单调双端队列
    # 然后维持单调队列性质
    # 这个 i 代表滑动窗口的末尾下标，从 0 开始，包含了初始状态
    for i in range(0, len(nums)):
        # 先看队头是否出队
        if 0 != len(q) and i - k + 1 > q[0]:
            q.pop(0)
        if True == maxOrMin:
            while 0 != len(q) and nums[i] >= nums[q[len(q)-1]]:
                q.pop(len(q)-1)
        else:
            while 0 != len(q) and nums[i] <= nums[q[len(q)-1]]:
                q.pop(len(q)-1)
        q.insert(len(q), i)
        if i - k + 1 >= 0:
            res.append(nums[q[0]])
    return res


n, m, a, b = map(int, input().split(' '))
matrix = [[-1] * m for _ in range(n)]
for i in range(n):
    matrix[i] = list(map(int, input().split(' ')))

maxs = [[-1]*(m-b+1) for _ in range(n)]
mins = [[-1]*(m-b+1) for _ in range(n)]
for i in range(n):
    maxs[i] = slidingWindow(matrix[i], b, True)
    mins[i] = slidingWindow(matrix[i], b, False)

# TODO 针对竖向也计算滑动窗口，目前 10 个点过了 7 个

# 开始计算价值和
ans = 0
for i in range(n-a+1):
    for j in range(m-b+1):
        maxVal = maxs[i][j]
        minVal = mins[i][j]
        for k in range(a):
            maxVal = max(maxVal, maxs[i+k][j])
            minVal = min(minVal, mins[i+k][j])
        ans += maxVal*minVal
print(ans)
