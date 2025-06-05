#用类来表示二叉树
class BinaryTree:

    def __init__(self, root) -> None:
        self.value = root
        self.leftchild = None
        self.rightchild = None

    def InsertNode(self, newNode, place=False):  #默认在左边插入 False
        if place == False:
            #左边插入
            if not self.leftchild:  #不存在则直接插入
                self.leftchild = BinaryTree(newNode)

        if place == True:
            #右边插入
            if not self.rightchild:
                self.rightchild = BinaryTree(newNode)

    def GetRoot(self):
        return self.value
