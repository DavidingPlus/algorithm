# https://www.lanqiao.cn/problems/3520/learning/?subject_code=3&group_code=3&match_num=14&match_flow=1&origin=cup

n = int(input())

for i in range(n):
    T = input()
    S = input()

    ans = 0
    for j in range(len(T)):
        if S[j] != T[j]:
            if S[j] == S[j + 1]:
                ans = -1
                break
            else:
                ans += 1
    print(ans)
