n = int(input())
num_list = list()
for i in range(n):
    num_list.append(int(input()))

num_dict = dict()
for each in num_list:
    try:
        num_dict[each]
    except KeyError:
        num_dict[each] = 1
    else:
        num_dict[each] += 1
# print(num_dict)

#按照键值的大小进行排序 得到一个键值的顺序列表
#这个sorted内置函数对字典排序默认是针对键值进行排序 里面还有个key= 可以用来写匿名函数指明排序规则
key_sorted_list = sorted(num_dict, reverse=False)
for each in key_sorted_list:
    print(f"{each} {num_dict[each]}")
