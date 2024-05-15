n = int(input())
X = list(map(int, input().split()))
F = list(map(int, input().split()))

ans = -1
for i in range(n):
    for j in range(1+i, n):
        if F[i] == j or F[j] == i:
            continue
        ans = max(ans, X[i] ^ X[j])
print(ans)
