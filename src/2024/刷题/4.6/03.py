# https://www.lanqiao.cn/problems/5128/learning/?page=1&first_category_id=1&second_category_id=15&difficulty=20

# 完全二叉树，往右走坐标 * 2，往左走 * 2 - 1
# 但是这个题，每一层的坐标是独立的，因此需要简单转化一下
n, q = map(int, input().split())
for _ in range(q):
    s = input()
    # 先计算真实编号
    ans = 1
    for c in s:
        ans *= 2
        if 'R' == c:
            ans += 1
    ans -= 2**(len(s))-1
    print(ans)
