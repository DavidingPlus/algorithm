# https://www.lanqiao.cn/problems/592/learning/?page=1&first_category_id=1&name=%E9%97%A8%E7%89%8C%E5%88%B6%E4%BD%9C

ans = 0
for i in range(1, 2021):
    ans += list(str(i)).count("2")
print(ans)
# print(624)
