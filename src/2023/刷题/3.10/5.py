n=int(input())
ID_list=list()
for i in range(n):
    time_ID_str=input()
    time_ID_list=time_ID_str.split(' ')
    #注意存入的一定是数字,字符串的话比较会出错
    if not int(time_ID_list[1]) in ID_list:
        ID_list.append(int(time_ID_list[1]))

#排序
ID_list.sort()

for elem in ID_list:
    print(elem,end='\n')
