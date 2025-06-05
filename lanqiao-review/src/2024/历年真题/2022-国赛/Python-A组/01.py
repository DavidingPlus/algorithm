MOD = 10
a, b = 1, 1

ans = 0
for _ in range(1, 1+202202011200):
    if 7 == a % MOD:
        ans += 1

    c = (a+b) % MOD
    a, b = b, c

print(ans)
