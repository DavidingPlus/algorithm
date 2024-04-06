#给定一个只包含大写字母的字符串S,请你输出其中出现次数最多的字符。
#如果有多个字母均出现了最多次, 按字母表顺序依次输出所有这些字母。
strs=input()

str_dict=dict()
for ch in strs:
    try:
        str_dict[ch]
    except KeyError:
        str_dict[ch]=1
    else:
        str_dict[ch]+=1

str_times=str_dict.items()
str_times=sorted(str_times,key=lambda elem:elem[1],reverse=True)
max_times=str_times[0][1]
ans_str=str()
for elem in str_times:
    if elem[1]!=max_times:
        break
    #由于还要按照字母表进行排序，所以插入字符串中
    ans_str+=elem[0]
ans_list=sorted(ans_str,key=lambda ch:ch)
for elem in ans_list:
    print(elem,end='')
print(end='\n')
