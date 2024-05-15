# https://www.lanqiao.cn/problems/3526/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup


def getChild(m, k):
    return [k * m - (m - 2), k * m + 1]


count = int(input())
for i in range(count):
    n, m, k = map(int, input().split(' '))
    # 第 k 个节点对应的子树的节点坐标是 [ k * m - (m - 2) , k * m + 1 ]
    # 一层一层来，从左到右，当访问到边界的时候就停止
    ans = 0
    left, right = [k, k]
    while True:
        #          1
        #     2           3
        #  4    5      6     7
        # 8 9 10 11  12 13 14 15
        # 解释一下这个判断，注意这个二叉树，现在我先不管节点的个数，ans 能够维护到某层为止的以 k 为根节点的子树的节点个数，假设现在 k==3 ，现在到达节点 6 这一层，他下一层子树起点是 12 ，如果我的 n 在 [6, 11]之间，那么就可以在这一层跳出循环，并且计算出当前这一层的个数，得到最终的结果，下面的判断恰好就维护了这个操作，并且由于循环的存在， n 不可能比 6 小，否则再上一层就跳出，因此 n 的范围就确定了，这样最下面一层的值的个数就能确定了
        if getChild(m, left)[0] > n:
            ans += min(right, n)-left+1
            break
        ans += right-left+1
        left, right = [getChild(m, left)[0], getChild(m, right)[1]]
    print(ans)
