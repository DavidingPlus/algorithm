a = [5, 7, 6, 3, 4, 1, 2]
b = sorted(a)  # 默认是降序排列
print(a)
# [5, 7, 6, 3, 4, 1, 2]
print(b)
# [1, 2, 3, 4, 5, 6, 7]

L = [('b', 2), ('a', 1), ('c', 3), ('d', 4)]
print(L)
L2 = sorted(L, key=lambda elem: elem[0], reverse=False)
# lambda 匿名函数
# key是选择按照什么元素进行排序 这里是选择了字符
# reverse代表是升序还是降序 默认False代表降序
print(L2)

#注意sorted()函数返回对象是一个新的列表,所以在对字典对象排序的时候请将字典转化为元素为列表或者元组(最好是元组)的列表,否则输出结果如果按照key排序不会将value保存下来
score_dict = {"张三": 60, "李四": 100, "王五": 80}
print(score_dict)
#按照成绩进行排序
scores = score_dict.items()
# print(score_dict.keys())
final_list = sorted(scores, key=lambda elem: elem[1], reverse=False)
print(final_list)
