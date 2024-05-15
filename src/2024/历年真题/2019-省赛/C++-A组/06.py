# https://www.lanqiao.cn/problems/183/learning/?page=1&first_category_id=1&name=%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9D%83%E5%80%BC

# 测试数据
# 10
# 0 3 -2 4 10 -10 -4 -2 3 -5
# ans: 2

# 上一题上了强度，这一题这么简单？？
n = int(input())
A = list(map(int, input().split()))

# 从第一层开始
depth = 0
layerSum = 0
ans = 0

while True:
    depth += 1
    # 注意 left 和 right 的坐标计算
    left = 2 ** (depth - 1) - 1
    right = min(2 ** depth - 1 - 1, n)

    if layerSum < sum(A[left:1+right]):
        layerSum = sum(A[left:1+right])
        ans = depth
    if right == n:
        break
print(ans)
