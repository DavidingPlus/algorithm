n=int(input())

#用一个二维数组来存储某个节点的子节点
#使得每个节点的下标里存的就是子节点
Nodes=list([]for i in range(1000001))
#根节点没有父亲 不需要存入
for i in range(2,n+1):
    node=int(input())
    Nodes[node].append(i)

#要使得这么操作下来的树长度最大，那么肯定最好优先选择孩子少的节点，因为这样可以避免左孩子右子树公用一个根节点
#将每个节点循环递归得出最大的值
def get_height(root):
    ans=0
    for i in range(len(Nodes[root])):
        node=Nodes[root][i]
        ans=max(ans,len(Nodes[root])+get_height(node))
    return ans

print(get_height(1))
