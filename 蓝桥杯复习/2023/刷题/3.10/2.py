n=int(input())
m=int(input())

def get_sum(num:int)->int:
    num_list=list(str(num))
    sum=0
    for elem in num_list:
        sum+=int(elem)
    return sum

data_list=list()
for i in range(1,n+1):
    # data_list.append((i,get_sum(i)))
    data_list.append((i, sum(int(i)for i in str(i))))

data_list.sort(key=lambda elem:elem[1])

print(data_list[m-1][0])
