# https://www.lanqiao.cn/problems/2137/learning/?page=1&first_category_id=1&name=%E5%85%A8%E6%8E%92%E5%88%97%E7%9A%84%E4%BB%B7%E5%80%BC

# 观察 (1,2,3) 和 (3,2,1) ，看下他们的价值和
# (1,2,3) 是 3 ; (3,2,1) 是 0 加起来刚好为 3，即 3 * (3 - 1) // 2
# 其他正与反的和的结果也如此
# 因此在考试的情况下，经过推到，推测公式是 n!*n*(n-1)/4，验证测试样例后通过，记得取余数

mod = 998244353
n = int(input())
ans = n*(n-1)/4
for i in range(1, n+1):
    ans *= i
    ans %= mod
print(int(ans))
