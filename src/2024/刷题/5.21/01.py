# 小凯的疑惑
# https://www.lanqiao.cn/problems/336/learning/

# 斐蜀定理
a, b = map(int, input().split())
# 题目保证 a b 互质，因此直接套公式即可
print((a-1)*(b-1)-1)
