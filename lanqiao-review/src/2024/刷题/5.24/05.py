# 线段树，在蓝桥杯中主要用于处理区间维护、区间查询的问题
# 能用树状数组解决的问题，一定能用线段树解决，线段树的功能比树状数组更强大
# 例题：单点修改、区间查询
# https://www.lanqiao.cn/problems/2340/learning/
# 通过这个题，可以记忆线段树的模板

from sys import setrecursionlimit
# 一般递归无脑开 1e8 就行了
setrecursionlimit(int(1e8))

N = int(input())

# 传入的原 nums 数组下标要从 1 开始，这样才能符合满二叉树的性质
# 注意这个时候， n == len(nums)-1 ，这个 n 是我们想要的 n ，他的值不等于数组的长度，因为头部加上一个空元素
nums = [0]+list(map(int, input().split()))
# 满二叉树的节点个数是 2n-1 ，但是最后一排可能有空结点，因此一般开 4n 大小的 f 数组
f = [0 for _ in range(4*N)]


# 建树
def build(left, right, id):
    global nums, f

    if left == right:
        f[id] = nums[left]
        return

    mid = (left+right)//2
    build(left, mid, 2*id)
    build(1+mid, right, 2*id+1)
    f[id] = f[2*id]+f[2*id+1]


# 更新结点，在 pos 位置加上 v
def update(pos, v, left, right, id):
    global f

    # pos 满足本区间，先修改 f 数组
    f[id] += v

    # 递归出口，到达叶结点
    if left == right:
        return

    mid = (left+right)//2
    if pos <= mid:
        update(pos, v, left, mid, 2*id)
    else:
        update(pos, v, 1+mid, right, 2*id+1)


# 查询
def get(l, r, left, right, id):
    global f

    if l == left and r == right:
        return f[id]

    mid = (left+right)//2
    # 如果 l 和 r 分别位于左右两个区间
    if l <= mid and r >= 1+mid:
        return get(l, mid, left, mid, 2*id) + get(1+mid, r, 1+mid, right, 2*id+1)
    # 都在左区间
    elif r < 1+mid:
        return get(l, r, left, mid, 2*id)
    # 都在右区间
    else:
        return get(l, r, 1+mid, right, 2*id+1)


build(1, N, 1)
m = int(input())
for _ in range(m):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        update(l[1], l[2], 1, N, 1)
    else:
        print(get(l[1], l[2], 1, N, 1))
