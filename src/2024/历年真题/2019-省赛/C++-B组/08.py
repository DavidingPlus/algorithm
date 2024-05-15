# https://www.lanqiao.cn/problems/192/learning/?page=1&first_category_id=1&name=%E7%AD%89%E5%B7%AE%E6%95%B0%E5%88%97

n = int(input())
A = list(map(int, input().split()))
A.sort(reverse=False)

# 由于排过序，只需要找出相邻两项差值最小的即可
# 题目给的数据能够保证一定能够构成等差数列，所以不用我操心了
d = A[len(A)-1]-A[0]
for i in range(1, len(A)-1):
    d = min(d, A[i]-A[i-1])
# 如果 d 是 0 ，则是恒等数列
if 0 == d:
    print(n)
else:
    print((A[len(A)-1]-A[0]) // d + 1)
