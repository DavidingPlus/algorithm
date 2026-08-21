/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    // 做一个备忘录
    int memo[20][20] = {0};

    int numTrees(int n) {
        // 每个节点都可以做根节点，一旦做了根节点，他的左右子树的集合就明确了，然后就可以以每个节点继续做根节点进行递归，以这个元素作为根节点的种类就是左子树和右子树种类的和

        // 所以我需要一个函数来记录一个数字范围构成的BST种类个数
        return countCategory(1, n);
    }

    int countCategory(int left, int right) {
        // 递归出口，大于表示没有，也就是只看另一边，因此返回1
        if (left >= right)
            return 1;

        if (0 != memo[left][right])
            return memo[left][right];

        //[left,right]中的种类就是把每个节点作为根节点去求和
        int res = 0, cl = 0, cr = 0;
        for (int i = left; i <= right; ++i) {
            cl = countCategory(left, i - 1);
            cr = countCategory(i + 1, right);
            res += cl * cr;
        }

        memo[left][right] = res;

        return res;
    }
};
// @lc code=end
