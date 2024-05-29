# https://www.lanqiao.cn/problems/17110/learning/

# TODO 超时 4/20

# 求出区间 [l1, r1] 和 [l2, r2] 的相交的长度
def get(l1, r1, l2, r2):
    if l1 >= r2 or l2 >= r1:
        return 0
    # 两个线段要么一个包含另一个，要么有重合部分，长度就是排序以后中间两个的插值
    l = [l1, r1, l2, r2]
    l.sort()
    return l[2]-l[1]


n, m = map(int, input().split())
l1s = [[0, 0]for _ in range(n)]
l2s = [[0, 0]for _ in range(m)]

for i in range(n):
    l, r = map(int, input().split())
    l1s[i] = [l, r]
for i in range(m):
    l, r = map(int, input().split())
    l2s[i] = [l, r]

ans = [0 for _ in range(m)]
for i in range(m):
    for j in range(n):
        if float(get(l2s[i][0], l2s[i][1], l1s[j][0], l1s[j][1])) >= (l1s[j][1]-l1s[j][0])/2:
            ans[i] += 1

    print(ans[i])
