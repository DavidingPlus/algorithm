# https://www.lanqiao.cn/problems/1065/learning/?page=1&first_category_id=1&name=2020

# 填空题，暴力即可
with open("./02_2020.txt", mode="r", encoding="utf-8") as file:
    data = []
    while True:
        s = file.readline()
        # readline() 读取完毕的时候返回空字符串
        if "" == s:
            break
        # 弹掉末尾的 '\n'
        if '\n' == s[len(s)-1]:
            s = s[:-1:]  # 字符串没有 pop 方法，所以用切片了
        data.append(s)
    # 真正处理的逻辑
    ans = 0
    # 横向
    for i in range(len(data)):
        for j in range(0, len(data[0])-4+1):
            if "2020" == data[i][j:j+4]:
                ans += 1
    # 纵向
    for j in range(len(data[0])):
        for i in range(0, len(data)-4+1):
            if "2020" == data[i][j] + data[i+1][j] + data[i+2][j] + data[i+3][j]:
                ans += 1
    # 斜着
    for i in range(len(data[0])-4+1):
        for j in range(len(data)-4+1):
            if "2020" == data[i][j] + data[i+1][j+1] + data[i+2][j+2] + data[i+3][j+3]:
                ans += 1
    print(ans)
# print(16520)
