# Counter 计数器
from collections import Counter

# 包括列表或者字符串等容器都可以使用 Counter 计数器帮我们自动化处理
l = ['a', 'b', 'b', 'c', 'c', 'c']

d = Counter(l)

# 这些东西都是可以直接通过 for in 语句遍历的
print(d)  # Counter({'c': 3, 'b': 2, 'a': 1})
print(list(d))  # ['a', 'b', 'c']
print(d.keys())  # dict_keys(['a', 'b', 'c'])
print(d.values())  # dict_values([1, 2, 3])
print(d.items())  # dict_items([('a', 1), ('b', 2), ('c', 3)])
