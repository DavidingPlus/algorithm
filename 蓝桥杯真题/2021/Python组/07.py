# https://www.lanqiao.cn/problems/1457/learning/?page=1&first_category_id=1&name=%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92%E5%BD%A2

# 初始化一个杨辉三角的雏形，答案就在构造杨辉三角的过程中就可以得到
n = int(input())
# 直接存储上一层即可，计算出下一层在赋值
matrix = [1, 1]

# 开始生成杨辉三角
ans = 1
# n 为 1 的情况需要特判，不进入下面的计算
# TODO 算法超时，4/10
if 1 != n:
    while True:
        flag = False
        tmp = [1]
        i = len(matrix)
        for j in range(1, i):
            tmp.append(matrix[j-1]+matrix[j])
            # 第一次出现，计算下标
            if (n == tmp[j]):
                flag = True
                ans = i * (i+1)//2 + j + 1
                break
        if True == flag:
            break
        tmp.append(1)  # 不要忘了末尾补上 1
        matrix = tmp
print(ans)
