# https://www.lanqiao.cn/problems/599/learning/?page=1&first_category_id=1&name=%E5%B9%B3%E6%96%B9%E5%92%8C

# 1 到 2019
ans = 0
for i in range(1, 2019+1):
    l = list(str(i))
    if '2' in l or '0' in l or '1' in l or '9' in l:
        ans += i**2
print(ans)
# print(2658417853)
