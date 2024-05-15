from bisect import *

# 4 4 2
# 4 2 3 1
# 2 1 2 1
# 4 4 1 1
# 2 2 2 4

# TODO 编译报错。。。

n, m, T = map(int, input().split())
R = list(map(int, input().split()))
C = list(map(int, input().split()))
dictR1 = dict()
dictR2 = dict()
dictC1 = dict()
dictC2 = dict()

# 将其带上下标，然后进行排序
for i in range(n):
    R[i] = [R[i], i]
for j in range(m):
    C[j] = [C[j], j]

R.sort()
C.sort()

for i in range(n):
    dictR1[R[i][1]] = i
    dictR2[i] = R[i][1]
for j in range(m):
    dictC1[C[j][1]] = j
    dictC2[j] = C[j][1]


for i in range(n):
    R[i] = R[i][0]
for j in range(m):
    C[j] = C[j][0]


def work(R, C, sr, sc, tr, tc) -> int:
    if sr == tr and sc == tc:
        return 1

    ans = 0

    newSr = dictR1[sr]
    border = bisect_right(R, R[newSr]) - 1
    if border != len(R)-1:
        left = bisect_left(R, R[border+1])-1
        right = bisect_right(R, R[border+1])-1
        while left <= right:
            ans += work(R, C, dictR2[left], sc,  tr, tc)
            left += 1

    newSc = dictC1[sc]
    border = bisect_right(C, C[newSc])-1
    if border != len(C)-1:
        left = bisect_left(C, C[border+1])-1
        right = bisect_right(C, C[border+1])-1
        while left <= right:
            ans += work(R, C,  sr, dictC2[left],  tr, tc)
            left += 1

    return ans


for _ in range(T):
    sr, sc, tr, tc = map(int, input().split())
    print(work(R, C, sr-1, sc-1, tr-1, tc-1))
