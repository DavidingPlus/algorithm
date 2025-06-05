# 下面的博客对这些的定义与我想的不太一样，以下面的最基本的为准，延申自己推导即可
# https://geek-docs.com/python/python-ask-answer/36_tk_1701998299.html#ftoc-heading-1
# https://blog.csdn.net/qq_26502245/article/details/121807502

# 1. list
l1 = [1, 2, 2, 3]
l2 = [2, 2, 3, 4]
# 交集
print([e for e in l1 if e in l2])  # [2, 2, 3]
# 差集 l1-l2
print([e for e in l1 if e not in l2])  # [1]
# 并集 a + (b-a)
print(l1 + [e for e in l2 if e not in l1])  # [1, 2, 2, 3, 4]

# 2. set
s1 = {1, 2, 3}
s2 = {3, 2, 4}  # set 是会自动排序的，默认升序，并且去重
# 交集
print(s1 & s2)  # {2, 3}
# 差集 s1-s2
print(s1 - s2)  # {1}
# 并集
print(s1 | s2)  # {1, 2, 3, 4}

# 3. dict
d1 = {'a': 1, 'b': 2, 'c': 3}
d2 = {'b': 2, 'c': 3, 'd': 4}
# 交集
print({k: d1[k] for k in d1 if k in d2})  # {'b': 2, 'c': 3}
# 差集 d1-d2
print({k: d1[k] for k in d1 if k not in d2})  # {'a': 1}
# 并集
d3 = d1.copy()
d3.update(d2)
print(d3)  # {'a': 1, 'b': 2, 'c': 3, 'd': 4}
