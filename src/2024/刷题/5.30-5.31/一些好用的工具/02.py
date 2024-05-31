# defaultDict 默认字典
from collections import defaultdict

# 默认字典的作用和普通字典差不多，只不过普通字典对不存在的 key 做运算会报错，需要先复制， defaultdict 直接可以做运算，会默认创建默认值为 0 ， 和 c++ 的 unorder_map<> 一样
d = defaultdict(int)
for i in range(0, 10):
    # ord 将字母转化为 ASCII 码
    # chr 将数字转化为对应字符
    d[i] = chr(ord('a')+i-0)
print(d)
