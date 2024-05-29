# 仪仗队
# https://www.lanqiao.cn/problems/18419/learning/?page=1&first_category_id=1&name=%E4%BB%AA%E4%BB%97%E9%98%9F

# TODO 超时 9/15 ，主要就是删除一个元素以后更新线段树太慢了

from sys import setrecursionlimit
setrecursionlimit(int(1e8))

MAX = 10**9

# 利用线段树存储区间内的最小值的下标
N = int(input())

# 当每次删除一个元素以后，个人不想重构整棵树的结构，因此做一个伪删除，将该位置的元素改成最大，然后更新整棵树
# 并且由于传入的 l 和 r 是依据新数组的，因此存储一个新的数组映射，下标对应的值是原数组的下标，这样比如 1 2 3 ，删除 2 ，如果新传入的是第 2 个，对应在原数组中就是 3
nums = [0]+list(map(int, input().split()))
ref = [i for i in range(1+N)]
# 存储线段树需要的 f 数组
f = [0 for _ in range(4*N)]


# 建树
def build(left, right, id):
    global nums, f

    if left == right:
        f[id] = left
        return

    mid = (left+right)//2
    build(left, mid, 2*id)
    build(1+mid, right, 2*id+1)

    if nums[f[2*id]] == nums[f[2*id+1]]:
        f[id] = f[2*id]
    else:
        f[id] = f[2*id] if nums[f[2*id]] < nums[f[2*id+1]] else f[2*id+1]


def get(l, r, left, right, id):
    global nums, f

    # 先找到最小的点
    if l == left and r == right:
        return f[id]

    mid = (left+right)//2
    if l <= mid and r >= 1+mid:
        lans = get(l, mid, left, mid, 2*id)
        rans = get(1 + mid, r, 1+mid, right, 2*id+1)
        if nums[lans] == nums[rans]:
            return lans
        else:
            return lans if nums[lans] < nums[rans] else rans
    elif r < 1+mid:
        return get(l, r, left, mid, 2*id)
    else:
        return get(l, r, 1+mid, right, 2*id+1)


# 在进入 update() 函数之前已经更新好了 nums 数组
def update(pos, left, right, id):
    global nums, f

    if left == right:
        f[id] = left
        return

    # 查询 pos 所在区间，另一半不变
    mid = (left+right)//2
    if pos <= mid:
        update(pos, left, mid, 2*id)
    else:
        update(pos, 1+mid, right, 2*id+1)

    f[id] = f[2*id] if nums[f[2*id]] <= nums[f[2*id+1]] else f[2*id+1]


build(1, N, 1)
ans = sum(nums)
K = int(input())
for _ in range(K):
    l, r = map(int, input().split())
    pos = get(ref[l], ref[r], 1, N, 1)

    # 更新答案以及 nums 和 ref 数组
    ans -= nums[pos]
    nums[pos] = 1+MAX
    # 注意 pos 是相对 nums 的下标，对于 ref 就相当于元素的值
    ref.remove(pos)

    update(pos, 1, N, 1)

print(ans)
