/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 代表分隔符的字符串。
const std::string SEP = ",";

// 代表 null 空指针的字符串。
// std::string(1, '#') 表示构造一个长度为 1、内容为 '#' 的字符串。
// 第一个参数是重复次数，第二个参数是要重复的字符；它等价于 std::string("#")。
const std::string NULL_CHAR = "#";


// 方法 1：递归遍历，这里使用前序遍历。
// class Codec
// {

// public:

//     // Encodes a tree to a single std::string.
//     std::string serialize(TreeNode *root)
//     {
//         // 单个字符构造 std::string。
//         // const char c = 'a';
//         // std::string s3(1, c); // "a"
//         if (!root) return NULL_CHAR + SEP;

//         std::string res = std::to_string(root->val) + SEP;

//         res += serialize(root->left);
//         res += serialize(root->right);


//         return res;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode *deserialize(std::string data)
//     {
//         // 使用 std::getline 按逗号切分序列化结果：std::getline(输入流, 保存读取结果的字符串, 分隔符);
//         // 每次调用会从输入流中读取一段内容，直到遇到指定的分隔符。例如："1,2,#,#" 会依次读取出 "1"、"2"、"#"、"#"。如果字符串以分隔符结尾，例如 "1,2,"，最后一个逗号后面没有内容，std::getline 不会额外读取出一个空字符串。但连续分隔符中间的空内容会被读取，例如 "1,,2" 会得到 "1"、""、"2"。
//         std::queue<std::string> nodes;
//         std::stringstream ss(data);
//         std::string token;

//         while (std::getline(ss, token, SEP[0]))
//         {
//             if (!token.empty()) nodes.push(token);
//         }


//         return deserialize(nodes);
//     }


// private:

//     TreeNode *deserialize(std::queue<std::string> &nodes)
//     {
//         // 前序遍历只维护节点的信息是没办法还原成为二叉树的，但是现在我们维护有空指针的信息，每一个位置就是一个节点。序列化时使用的是前序遍历，因此反序列化时也按照前序顺序消费节点。
//         if (nodes.empty()) return nullptr;

//         std::string node = nodes.front();
//         // 这一步弹出的操作很关键，为了保证子问题拿到的数据和原问题。
//         nodes.pop();

//         // 如果遇到 '#' 说明遇到了空结点。
//         if (NULL_CHAR == node) return nullptr;

//         TreeNode *root = new TreeNode(std::stoi(node));

//         // 这两行看着可能很奇怪，但由于在前序遍历的框架中，nodes 会一直变化，因此没问题。
//         root->left = deserialize(nodes);
//         root->right = deserialize(nodes);


//         return root;
//     }
// };


// 解法 2：层序遍历。
// 这个方法的好处是，每一层能够准确的给出下一层元素的个数。就是每一层非空的元素 * 2 就是 下一层的所有节点的个数，然后只有非空的节点是有效的。
class Codec
{

public:

    // Encodes a tree to a single std::string.
    std::string serialize(TreeNode *root)
    {
        std::string res;

        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if (!node)
                {
                    res += NULL_CHAR + SEP;
                }
                else
                {
                    res += std::to_string(node->val) + SEP;

                    // 层序遍历时，不需要专门判断当前层是不是叶子层。对于每一个非空节点，都将它的左、右孩子加入队列，即使孩子为空；对于空指针，只记录 NULL_CHAR，不再继续向下扩展。这样可以保留每个节点对应的左右孩子位置，避免因为跳过某些空指针而丢失树的结构信息。例如当前层同时存在叶子节点和非叶子节点时，叶子节点的空孩子也必须作为占位信息记录下来。当队列为空时，说明所有非空节点及其左右孩子都已经处理完毕，遍历结束。
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }


        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        std::vector<std::string> nodes;
        std::stringstream ss(data);
        std::string token;

        while (std::getline(ss, token, SEP[0]))
        {
            if (!token.empty()) nodes.emplace_back(token);
        }

        // 判断空树。
        if (nodes.empty() || NULL_CHAR == nodes[0]) return nullptr;

        // 创建根节点。
        TreeNode *root = new TreeNode(std::stoi(nodes[0]));
        // 按照层序遍历的板子去反解析。
        std::queue<TreeNode *> q;
        q.push(root);
        // index 指向下一个尚未处理的序列化 token。
        int index = 1;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // 反序列化时，队列中只保存非空节点。因为序列化过程中，每个非空节点都会按照层序遍历顺序输出自己的左、右孩子，而空孩子只输出一个 NULL_CHAR（例如 '#'），不会继续产生后续节点。因此，反序列化时每从队列中取出一个非空父节点，就从 nodes 中依次读取两个 token，分别作为它的左孩子和右孩子；如果 token 是 '#',说明对应位置为空，不创建节点，也不加入队列；如果 token 是普通数字，就创建新节点并加入队列，因为这个节点后面还需要继续解析自己的左右孩子。这样既能按照层序顺序还原节点，又能通过 '#' 保留空孩子的位置信息，同时避免让空指针继续参与后续解析。
                // 我们从 root 的角度思考一下 index 运作的过程，初始情况下 index 为 1，指向 root 的左孩子结点，然后层序遍历处理 root 这一层，经过了左右两个孩子，将这两个结点加入队列，这时 index 为 3。队列刚好进入下一层，同时 index 指向了第二层对应的孩子结点。然后依次循环。

                // 处理左子树。
                if (NULL_CHAR != nodes[index])
                {
                    node->left = new TreeNode(std::stoi(nodes[index]));
                    q.push(node->left);
                }
                ++index;

                // 处理右子树。
                if (NULL_CHAR != nodes[index])
                {
                    node->right = new TreeNode(std::stoi(nodes[index]));
                    q.push(node->right);
                }
                ++index;
            }
        }


        return root;
    }
};


// Your Codec object will be instantiated && called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


int main()
{
    Codec codec;

    // 测试空树。
    std::cout << "serialize empty tree: "
              << codec.serialize(nullptr) << std::endl;

    // 测试一棵带有空子树的二叉树：
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    std::vector<std::optional<int>> values{
        1, 2, 3, std::nullopt, std::nullopt, 4, 5};
    TreeNode *root = TreeNode::createRoot(values);

    std::string data = codec.serialize(root);
    std::cout << "serialize tree: " << data << std::endl;

    TreeNode *decoded = codec.deserialize(data);
    std::string decodedData = codec.serialize(decoded);
    std::cout << "round trip correct: "
              << std::boolalpha << (data == decodedData) << std::endl;

    TreeNode::freeTree(root);
    TreeNode::freeTree(decoded);
}
