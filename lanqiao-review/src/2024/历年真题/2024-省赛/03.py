from math import sqrt

n = int(input())
nums = list(map(int, input().split()))


def check(n: int):
    for i in range(0, 1+int(sqrt(2*n))):
        for j in range(0, i):
            if 2*n == (i+j)*(i-j+1):
                return True
    return False


ans = 0
memo = {}
for e in nums:
    if e not in memo:
        memo[e] = check(e)
    if False == memo[e]:
        ans += 1
print(ans)
