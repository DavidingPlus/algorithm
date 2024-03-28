#去重和排序
n = int(input())
num_list = list(map(int, input().split(' ')))  #这个与n无关 结束的标志是换行符
# print(num_list)

final_list = list()
#去重
for num in num_list:
    #注意列表index()函数的使用 找到返回下标 找不到报错
    try:
        final_list.index(num)
    except ValueError:
        final_list.append(num)
    else:
        pass

#排序
print(len(final_list))
final_list.sort()
for num in final_list:
    print(num, end=' ')
print(end='\n')
