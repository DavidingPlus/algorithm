# -*- coding:utf-8 -*-
# 区间修改、区间求和
# https://www.lanqiao.cn/problems/1133/learning/

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

N, Q = map(int, input().split())

# 使用延迟标记进行优化
# 区间修改，在每个结点加上一个 tag 标记，用作记录，例如给[1, 3] 区间加上 3 ，那么到达[1, 3] 的结点位置的时候，这个时候按理来讲修改完本结点以后需要继续往下传递，修改[1, 2] 和[3, 3] 等，但是由于现在区间完全匹配，因此把这部分工作先保存在 tag 标记当中，如果下一次我需要查询[1, 2] 的区间，需要通过[1, 3] 继续向下递归，就需要将这个 tag 进行传递，后面的就递归了。因此这个 tag 标记又叫做延迟标记，或者懒标记
nums = [0]+list(map(int, input().split()))
f = [0 for _ in range(4*N)]
tag = [0 for _ in range(4*N)]


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


def toDown(leftLen, rightLen, id):
    global f, tag

    f[2*id] += tag[id]*leftLen
    f[2*id+1] += tag[id]*rightLen
    tag[2*id] += tag[id]
    tag[2*id+1] += tag[id]
    tag[id] = 0


def update(l, r, v, left, right, id):
    global f, tag

    if l == left and r == right:
        f[id] += (right-left+1)*v
        tag[id] += v
        return

    mid = (left+right)//2
    # 区间不匹配，向自己的两个子节点传递，注意，只有当区间完美匹配的时候 tag 才会被延迟保留，所以需要传递的 tag 都是包含当前整个区间的 update 的，因此不管 l r 落在哪个区间，当前如果有 tag 滞留，必然是上一次完美匹配的遗留产物，因此需要向左右子节点进行传递，因此用的是 left 和 right
    toDown(mid-left+1, right-(1+mid)+1, id)

    if l <= mid and r >= 1+mid:
        update(l, mid, v, left, mid, 2*id)
        update(1+mid, r, v, 1+mid, right, 2*id+1)
    elif r < 1+mid:
        update(l, r, v, left, mid, 2*id)
    else:
        update(l, r, v, 1+mid, right, 2*id+1)

    f[id] = f[2*id]+f[2*id+1]


def get(l, r, left, right, id):
    global f, tag

    if l == left and r == right:
        return f[id]

    mid = (left+right)//2
    # 同理这里也需要向下传递
    toDown(mid-left+1, right-(1+mid)+1, id)

    if l <= mid and r >= 1+mid:
        return get(l, mid, left, mid, 2*id) + get(1+mid, r, 1+mid, right, 2*id+1)
    elif r < 1+mid:
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
