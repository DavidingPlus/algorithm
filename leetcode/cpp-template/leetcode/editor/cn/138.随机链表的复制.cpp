/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30404
 *
 * [138] 随机链表的复制
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
// #include "../common/Node.h"


class Node
{

public:

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }


    int val;
    Node *next;
    Node *random;
};


// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{

public:

    Node *copyRandomList(Node *head)
    {
        // 先按 next 顺序构造一遍，在遍历一遍填充 random 指针。
        // 由于第二遍需要通过旧链表的 random，来对应新链表的指向哪个节点，因此需要把旧链表和新链表的节点对应起来，这里使用哈希表。

        Node *dummyHead = new Node(-1), *pDummy = dummyHead;
        std::unordered_map<Node *, Node *> um;

        for (Node *p = head, *pDummy = dummyHead; p; p = p->next, pDummy = pDummy->next)
        {
            pDummy->next = new Node(p->val);
            um[p] = pDummy->next;
        }

        for (Node *p = head; p; p = p->next) um[p]->random = um[p->random];


        return dummyHead->next;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
