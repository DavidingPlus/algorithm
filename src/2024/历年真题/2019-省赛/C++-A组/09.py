# https://www.lanqiao.cn/problems/186/learning/?page=1&first_category_id=1&name=%E7%B3%96%E6%9E%9C

N, M, K = map(int, input().split())
candy = [set() for _ in range(N)]

for i in range(N):
    candy[i] = set(map(int, input().split()))

# TODO
