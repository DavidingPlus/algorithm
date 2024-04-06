src_list = list()
for i in range(10):
    src_list.append([i, 2021])

ans = 1
while True:
    flag = False
    for ch in str(ans):
        # 先判断是否为0 为0则跳出
        if src_list[int(ch)][1] == 0:
            flag = True
            break
        src_list[int(ch)][1] -= 1

    if flag == True:
        break
    ans += 1

# 拼不出这个 所以ans要-1
ans -= 1
print(ans)
