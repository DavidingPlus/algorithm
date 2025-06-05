flag = False
ans = 0

for i in range(1, 1000000007 + 1):
    if i * 2021 % 1000000007 == 999999999:
        ans = i
        flag = True
        break

if flag == False:
    print(0)
else:
    print(ans)