#2*20220514=40441028
#sqrt(40441028)=6359.32
#6358*6359=40430522<40441028
#6359*6360=40443240>44041028

num=6359
while True:
    n=int(num*(num+1)/2)
        #判断n是不是回文数
    n_str=str(n)

    if len(n_str)%2==0:#长度为偶数
        #注意事项:len(n_str)/2得到的是浮点数的值 需要将其转化为整形或者采用整除运算!!!
        if n_str[:len(n_str)//2]==n_str[len(n_str)//2:][::-1]:
            print(n)
            break
    else:
         if n_str[:len(n_str)//2]==n_str[len(n_str)//2+1:][::-1]:
            print(n)
            break
    num+=1
