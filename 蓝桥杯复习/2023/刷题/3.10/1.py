#纸张大小
paper_str=input()
num=int(paper_str[1])

length=1189
width=841

for i in range(num):
    length=int(length/2)
    if length<=width:
        tmp=length
        length=width
        width=tmp

print(length)
print(width)
