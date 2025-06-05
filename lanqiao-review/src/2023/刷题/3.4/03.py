#对长度为n的01串,每一位都可能是0或者1 一共2的n次方种可能 按照顺序输入这次字符串
#在十进制里面就是从0输入到2的n次方-1 输入十进制数再将其转化为二进制即可
n = int(input())

for i in range(pow(2, n)):
    #bin()函数 求二进制数
    num_str = bin(i)  #0bxxxxx 需要除掉前面两位还要把位数不够的补上位数凑成n位
    num_str = num_str[2:]
    while (len(num_str) < n):
        num_str = '0' + num_str  #这样可以在num_str的前面加上字符!!!!
    print(num_str)
