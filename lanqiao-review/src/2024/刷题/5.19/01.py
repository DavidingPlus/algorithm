# https://www.lanqiao.cn/problems/558/learning/

# 测试数据
# 4500 12
# 100 3 0
# 400 5 0
# 300 5 0
# 1400 2 0
# 500 2 0
# 800 2 4
# 1400 5 4
# 300 5 0
# 1400 3 8
# 500 2 0
# 1800 4 0
# 440 5 10

N, m = map(int, input().split())
v_pre = [0 for _ in range(m)]
p_pre = [0 for _ in range(m)]
q = [0 for _ in range(m)]
for i in range(m):
    v_pre[i], p_pre[i], q[i] = map(int, input().split())

# 有一些物品的购买，需要前置物品，题目条件说明每个物品最多有两个附件物品。现在我们尝试将这几个物品绑在一起，分为一组，其他组怎么选跟他们根本没有关系，组内自己会商讨出一个结果，选择哪些能够获得最大的收益，这不就是分组背包吗？因此可以完美转化为分组背包问题
v = []
p = []

# 附件依赖的主件肯定先出现，因此不用考虑顺序的问题
d = {}
for i in range(m):
    if 0 == q[i]:
        v.append([v_pre[i]])
        p.append([p_pre[i]])
        d[i] = len(v)-1
    else:
        # 分组以后，主件和附件占用一个 i ，因此在 v 数组中的下标就会往前推移，因此开一个映射记录
        v[d[q[i]-1]].append(v_pre[i])
        p[d[q[i]-1]].append(p_pre[i])


# 物品价钱是 10 的倍数，所以除以 10 ，可以节省一些时间
dp = [0 for _ in range(1+N//10)]
for i in range(len(v)):
    tmp = [0 for _ in range(1+N//10)]
    # 处理每组，处理所有情况
    for j in range(1+N//10):
        # 不取
        tmp[j] = dp[j]
        # 若取一个，只能取主件
        if j >= v[i][0]//10:
            tmp[j] = max(tmp[j], dp[j-v[i][0]//10]+v[i][0]*p[i][0])
        # 若取两个，只能取一个主件和一个附件
        if len(v[i]) >= 2:
            for k in range(1, len(v[i])):
                if j >= (v[i][0]+v[i][k])//10:
                    tmp[j] = max(tmp[j],
                                 dp[j-(v[i][0]+v[i][k])//10]+v[i][0]*p[i][0]+v[i][k]*p[i][k])
        # 若取三个，三个都取
        if (3 == len(v[i])):
            if j >= sum(v[i])//10:
                tmp[j] = max(tmp[j],
                             dp[j-sum(v[i])//10]+v[i][0]*p[i][0]+v[i][1]*p[i][1]+v[i][2]*p[i][2])
    dp = tmp

print(dp[N//10])
