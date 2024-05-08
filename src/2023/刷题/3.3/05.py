# 给出一个非负整数，将它表示成十六进制的形式。
#ord函数 获取ASCII码
#chr函数 将数字转化为ASCII码
num = int(input())
ret_list: str = list()


def traverse(num: int) -> str:
    if num < 10:
        return chr(ord('0') + num)
    return chr(ord('A') + num - 10)


while num > 0:
    ret_list.append(traverse(num % 16))
    num = num // 16

ret_list = ret_list[::-1]
for ch in ret_list:
    print(ch, end='')
print('\n')
