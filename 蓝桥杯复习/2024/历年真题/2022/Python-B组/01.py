# https://www.lanqiao.cn/problems/2118/learning/?page=1&first_category_id=1&name=%E6%8E%92%E5%88%97%E5%AD%97%E6%AF%8D

# 将列表转化为字符串的方法!!!
l = sorted("WHERETHEREISAWILLTHEREISAWAY", reverse=False)
s = "".join(e for e in l)
print(s)
