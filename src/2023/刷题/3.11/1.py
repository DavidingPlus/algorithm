#谈判
#贪心 每次都找人数最少的人进行谈判 这样到最后必然花的钱最少
n=int(input())
num_list=list(map(int,input().split(' ')))

coin=0
while len(num_list)>1:
    #找到列表中人数最少的两项
    index1=num_list.index(min(num_list))
    tmp_list=list(num_list)
    #这里如果写tmp_list=num_list的话会认为tmp_list和num_list指向的是同一块内存单元，会有问题，必须要重新建立一个列表
    tmp_list.pop(index1)
    index2=num_list.index(min(tmp_list))
    #将原列表进行处理
    coin+=num_list[index1]+num_list[index2]
    num_list[index1]+=num_list[index2]
    num_list.pop(index2)
print(coin)
