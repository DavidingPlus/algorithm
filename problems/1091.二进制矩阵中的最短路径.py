#
# @lc app=leetcode.cn id=1091 lang=python3
#
# [1091] 二进制矩阵中的最短路径
#

# @lc code=start
class Solution:
    def shortestPathBinaryMatrix(self, grid) -> int:
        n = len(grid)
        # 图为空
        if 0 == n:
            return 0
        # 起点和终点都是障碍物，无法到达
        if 1 == grid[0][0] or 1 == grid[n-1][n-1]:
            return -1

        # 使用广度优先的策略，每次向外探一步（意思是每次到达的点需要的最短步数就是 ans），这样最先到达终点的 ans 就是答案，注意需要排除已经探索过的点，否则会导致死循环，也不符合先前的定义，这样得出的结果也不是最短的
        isVisited = [[False for _ in range(n)] for _ in range(n)]
        q = [[0, 0]]
        isVisited[0][0] = True
        ans = 0
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0],
                [1, 1], [1, -1], [-1, 1], [-1, -1]]

        while len(q) > 0:
            # 为了计算路径的值，按照前面的观点，联系到二叉树的层序遍历，这里也应该按照路径长短划分层次
            ans += 1
            size = len(q)
            for _ in range(size):
                node = q.pop(0)
                x, y = node[0], node[1]

                if n-1 == x and n-1 == y:
                    return ans

                # 这个点可以往四面八方走，在这里就做判断，不符合条件就不插入了
                for d in dirs:
                    newX, newY = x+d[0], y+d[1]
                    if (newX >= 0 and newX < n) and (newY >= 0 and newY < n) and (0 == grid[newX][newY]) and (False == isVisited[newX][newY]):
                        # Tips: 由于节点个数众多，因此 isVisited 的设在在这里就可以做了，让 q 里面不要插入太多的节点，否则空循环也耗时间的（本题就是这样，不然过不了）
                        q.append([newX, newY])
                        isVisited[newX][newY] = True
        return -1


# @lc code=end
