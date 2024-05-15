ans = 0
a = 1
b = 0

for i in range(1, 2024041331404202+1):
    a = (a*i) % 100
    b = (b+i) % 100
    if a == b:
        ans += 1
print(ans)
