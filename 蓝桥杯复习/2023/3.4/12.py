#最小字典序 贪心
#每次删除一个字母都保证得到最小的字典序 那么最后也必然会得到最小的字典序


#将字符列表转化为字符串
def list_to_str(list) -> str:
    string = str()
    for ch in list:
        string += ch
    return string


strs = input()
count = int(input())

#注意pop函数的返回值是弹出的元素!!!
for i in range(count):
    str_list = list(strs)  #这样可以将字符串转化为列表 列表中每个元素是字符串的字母
    str_list.pop(0)  #将第一个弹出 给一个初始值好比较
    cmp_str = list_to_str(list_to_str(str_list))
    str_list = list(strs)

    flag = 0
    for j in range(1, len(str_list)):  #第一个不用比较 从第二个开始比较
        str_list.pop(j)
        if list_to_str(str_list) <= cmp_str:
            cmp_str = list_to_str(str_list)
            flag = j  #制作标记
        str_list = list(strs)
    str_list = list(strs)
    str_list.pop(flag)
    strs = list_to_str(str_list)

print(strs)
