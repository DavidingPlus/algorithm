# https://www.lanqiao.cn/problems/1443/learning/?page=1&first_category_id=1&name=%E5%8D%A1%E7%89%87

d = dict()
for i in range(10):
    d[i] = 2021

ans = 1
flag = False
while True:
    l = list(str(ans))
    for e in l:
        d[int(e)] -= 1
        if d[int(e)] < 0:
            flag = True
            break
    if True == flag:
        break
    ans += 1
print(ans-1)
# print(3181)
