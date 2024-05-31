# -*- coding:utf-8 -*-
# 区间修改、区间查询（线段树 + 延迟标记 tag 优化）
# https://www.lanqiao.cn/problems/1133/learning/

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

N, Q = map(int, input().split())

nums = [0]+list(map(int, input().split()))
f = [0 for _ in range(1+4*N)]
tag = [0 for _ in range(1+4*N)]


def build(left, right, id):
    global nums, f, tag

    tag[id] = 0

    if left == right:
        f[id] = nums[left]
        return

    mid = (left+right)//2
    build(left, mid, 2*id)
    build(1+mid, right, 2*id+1)
    f[id] = f[2*id]+f[2*id+1]


# 将 tag 向下传递，向下传递的条件是调用 get() 和 update() 函数区间在当前区间不是完美匹配就需要向下转发
def toDown(leftLen, rightLen, id):
    global nums, f, tag

    f[2*id] += leftLen*tag[id]
    f[2*id+1] += rightLen*tag[id]
    tag[2*id] += tag[id]
    tag[2*id+1] += tag[id]
    tag[id] = 0


def update(l, r, v, left, right, id):
    global nums, f, tag

    # 完美匹配，延迟 tag 转发
    if l == left and r == right:
        f[id] += (r-l+1)*v
        tag[id] += v
        return

    mid = (left+right)//2
    # 区间不匹配，向自己的两个子节点传递，注意，只有当区间完美匹配的时候 tag 才会被延迟保留，所以需要传递的 tag 都是包含当前整个区间的 update 的，因此不管 l r 落在哪个区间，当前如果有 tag 滞留，必然是上一次完美匹配的遗留产物，因此需要向左右子节点进行传递，因此用的是 left 和 right
    toDown(mid-left+1, right-(1+mid)+1, id)

    if l <= mid and r >= 1+mid:
        update(l, mid, v, left, mid, 2*id)
        update(1+mid, r, v, 1+mid, right, 2*id+1)
    elif r <= mid:
        update(l, r, v, left, mid, 2*id)
    else:
        update(l, r, v, 1+mid, right, 2*id+1)

    # toDown 对于本节点修改的是两个子节点的 f 数组，所以本节点的更新以后的内容取决于子节点
    f[id] = f[2*id]+f[2*id+1]


def get(l, r, left, right, id):
    global nums, f, tag

    if l == left and r == right:
        return f[id]

    mid = (left+right)//2
    toDown(mid-left+1, right-(1+mid)+1, id)

    if l <= mid and r >= 1+mid:
        return get(l, mid, left, mid, 2*id) + get(1+mid, r, 1+mid, right, 2*id+1)
    elif r <= mid:
        return get(l, r, left, mid, 2*id)
    else:
        return get(l, r, 1+mid, right, 2*id+1)


build(1, N, 1)
for _ in range(Q):
    l = list(map(int, input().split()))
    if 1 == l[0]:
        update(l[1], l[2], l[3], 1, N, 1)
    else:
        print(get(l[1], l[2], 1, N, 1))
