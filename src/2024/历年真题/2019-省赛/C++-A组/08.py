# https://www.lanqiao.cn/problems/185/learning/?page=1&first_category_id=1&name=%E4%BF%AE%E6%94%B9%E6%95%B0%E7%BB%84

n = int(input())
A = list(map(int, input().split()))

# TODO 4/10
isUsed = [False for _ in range(1+10**6)]

for i in range(0, n):
    if isUsed[A[i]]:
        j = 1
        while True:
            if False == isUsed[j + A[i]]:
                A[i] += j
                break
            j += 1
    isUsed[A[i]] = True

for e in A:
    print(e, end=' ')
