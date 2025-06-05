# 单点修改、区间查询（线段树）
# https://www.lanqiao.cn/problems/2340/learning/

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

N = int(input())
nums = [0]+list(map(int, input().split()))

# 一般定义线段树的节点个数为 4*n ，因为其中可能包含一些空节点，并且节点编号从 1 开始
f = [0 for _ in range(4*N)]


def build(left, right, id):
    global nums, f

    if left == right:
        f[id] = nums[left]
        return

    mid = (left+right)//2
    build(left, mid, 2*id)
    build(1+mid, right, 2*id+1)
    f[id] = f[2*id]+f[2*id+1]


def update(pos, v, left, right, id):
    global nums, f

    if left == right:
        f[id] += v
        return

    mid = (left+right)//2
    if pos <= mid:
        update(pos, v, left, mid, 2*id)
    else:
        update(pos, v, 1+mid, right, 2*id+1)

    # 和 build 保持统一
    f[id] = f[2*id]+f[2*id+1]


def get(l, r, left, right, id):
    global f

    if l == left and r == right:
        return f[id]

    mid = (left+right)//2
    # 如果不在同一区间，分开处理
    if l <= mid and r >= 1+mid:
        return get(l, mid, left, mid, 2*id)+get(1+mid, r, 1+mid, right, 2*id+1)
    elif r <= mid:
        return get(l, r, left, mid, 2*id)
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
