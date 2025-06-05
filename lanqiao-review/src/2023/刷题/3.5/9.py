#完全二叉树在字符串这边的应用
#完全二叉树 左右节点必须都有 如果层数为n 则节点个数 2^n-1
#第k层的节点编号返回 2^(k-1)到2^k-1

#将层数和该层数的权值依次放到字典中
n = int(input())  #n代表节点个数
weight_list = list(map(int, input().split(' ')))

layer_weight_dict = dict()
layer = 1
for i in range(n):
    #第一层既是开始又是结束 需要单独判断
    if i == 0:
        layer_weight_dict[1] = weight_list[0]
        layer += 1

    elif (i + 1) == 2**(layer - 1):  #第layer层开始
        layer_weight_dict[layer] = weight_list[i]
    else:
        layer_weight_dict[layer] += weight_list[i]
        if (i + 1) == 2**layer - 1:  #如果是层末需要将层数加1
            layer += 1
#将层数存下来
layer -= 1
# print(layer_weight_dict)

#取出权值并找到最大的 并在字典中从开始到后面开始遍历直到找到第一个权值，保证了多个权值相同最小的深度
weights = layer_weight_dict.values()
max_weight = max(weights)

ans = 1
for i in range(1, layer + 1):
    if layer_weight_dict[i] == max_weight:
        ans = i
        break
print(ans)