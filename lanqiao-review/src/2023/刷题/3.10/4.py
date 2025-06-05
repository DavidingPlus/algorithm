#周一到周五刷a道题目 周六周天刷b道题目
#第几天实现做题数大于n题

a,b,n=input().split(' ')
a=int(a)
b=int(b)
n=int(n)

day=1
num=0
#这么一天一天遍历会超时 注意到每周做的题目个数相同 所以先算出有几周再对每周进行遍历即可
week_num=5*a+2*b
weeks=n//week_num
num+=week_num*weeks
day+=7*weeks
while num<n:
    if day%7>=1 and day%7<=5:
        num+=a
    else:
        num+=b
    day+=1

print(day-1)
