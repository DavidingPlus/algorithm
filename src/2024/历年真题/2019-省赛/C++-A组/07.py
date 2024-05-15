# https://www.lanqiao.cn/problems/184/learning/?page=1&first_category_id=1&name=%E5%A4%96%E5%8D%96%E5%BA%97%E4%BC%98%E5%85%88%E7%BA%A7

# 测试数据
# 3 10 10
# 7 1
# 10 3
# 5 3
# 3 2
# 5 3
# 7 3
# 9 1
# 7 1
# 1 3
# 9 3
# ans: 1

# TODO 8/10，超时一个点，内存溢出一个点
N, M, T = map(int, input().split())
orders = [[0 for _ in range(1+T)]
          for _ in range(N)]  # 下标代表店面下标，里面记录各个时刻的订单数

# 在输入的过程就处理输入的数据
for _ in range(M):
    ts, id = map(int, input().split())
    orders[id-1][ts] += 1  # 注意下标

# 计算优先级
ans = 0
for i in range(0, N):
    count = 0  # 对每个店来讲在在某时刻的订单数，因此外层是店面
    isInCache = False
    for j in range(1, 1+T):
        if 0 == orders[i][j]:
            count = 0 if 0 == count else count - 1
        else:
            count += 2*orders[i][j]
        # 这里注意一个细节，如果一个店面在 3 时刻为 7 ，那么进入缓存，最后时刻如果降到 5 ，那么仍在缓存，所以需要在过程中判断
        # 不在缓存到进入缓存
        if False == isInCache and count > 5:
            isInCache = True
        # 进入缓存到离开缓存
        elif True == isInCache and count <= 3:
            isInCache = False
    if isInCache:
        ans += 1
print(ans)
