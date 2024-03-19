# https://www.lanqiao.cn/problems/3521/learning/?subject_code=3&group_code=5&match_num=14&match_flow=1&origin=cup&page=1

n, m, a, b = map(int, input().split(' '))
matrix = [[0] * m for _ in range(n)]
for i in range(n):
    matrix[i] = list(map(int, input().split(' ')))
