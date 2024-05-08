# https://www.lanqiao.cn/problems/202/learning/?page=1&first_category_id=1&second_category_id=6

s = input()
if len(list(s)) == len(set(s)):
    print("YES")
else:
    print("NO")
