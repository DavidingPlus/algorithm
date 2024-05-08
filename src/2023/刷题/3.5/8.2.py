#转换思路 防止超时!!!
#原来的公式是对1到1000000007进行遍历
#现在转换思路就对1到2021进行遍历
flag = False
ans = 0
for i in range(2022):
    if (i * 1000000007 + 999999999) % 2021 == 0:
        ans = int((i * 1000000007 + 999999999) / 2021)
        flag = True
        break

if flag == False:
    print(0)
else:
    print(ans)