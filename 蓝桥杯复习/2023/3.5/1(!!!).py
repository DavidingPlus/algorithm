#字符串处理
sor_str = input()
#以空格分开转化为列表存着
str_list = sor_str.split(' ')
print(str_list)
#由于可能存在多个空格 按照空格分开后多个空格会变成空(测试得出的) 需要消除
str_list2 = list()
for elem in str_list:
    if elem != '':
        str_list2.append(elem)
str_list = str_list2
print(str_list)

#将单词和字母分开
#一个一个遍历 先看这些字母里面是不是有混着数字的
#用一个新字符串来存放改造之后的字符串
new_str = str()
for elem in str_list:
    # Python中capitalize()函数的作用就是把字符串开始字符变为大写，其余字符变为小写 如果最开始是数字，那么数字不变，后面的字符全为小写
    #字符串是不可以修改的,所以只能重新生成一个字符串
    elem = elem.capitalize()  #先将首字符变为大写字母
    if elem.isalpha() == True:
        #字符串下的三个函数
        #str.isdigit() 字符串是否全为数字
        #str.isalpha() 字符串是否全为字母
        #str.isalnum() 字符串是否为数字和字母的组合 纯数字和纯字符也返回True!!! 但是如果字符串中含有其他字符的组合也会返回空格
        new_str += elem

    else:
        flag = False
        #这就证明该字符串中含有数字
        #遍历该字符串，修改字母和数字交界的地方
        for i in range(len(elem) - 1):
            #如果该字符和下一个字符都是字母或者数字 则正常 注意处理最后一个字符
            if (elem[i].isalpha()
                    and elem[i + 1].isalpha()) or (elem[i].isdigit()
                                                   and elem[i + 1].isdigit()):
                new_str += elem[i]
        #如果前面是字符后面是数字
            elif elem[i].isalpha() and elem[i + 1].isdigit():
                #这里的插入也是一样的
                new_str += elem[i]
                new_str += '_'
            #前面是数字后面是字符
            else:
                #插入数字并且做标记 因为下一个字母需要大写
                new_str += elem[i]
                new_str += '_'
                flag = True

        #处理最后一个字符
        new_str += elem[-1]

    new_str += ' '  #注意加上空格

#由于最后一个结束之后没有空格，手动将其去掉
new_str = new_str[:-1]
print(new_str)
