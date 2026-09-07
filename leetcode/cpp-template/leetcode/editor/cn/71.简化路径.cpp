/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30404
 *
 * [71] 简化路径
 */

#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"


// @lc code=start
class Solution
{

public:

    std::string simplifyPath(std::string path)
    {
        std::deque<std::string> parts;
        std::stringstream ss(path);
        std::string token;

        // 例如对 "/home//foo/" 切分，会得到 ""、"home"、""、"foo"，题目规定是以 '/' 开头的绝对路径，因此不用特殊处理相对路径和绝对路径。
        while (std::getline(ss, token, '/'))
        {
            // 遇到空字符或者 '.' 跳过当前循环。
            if (token.empty() || "." == token)
            {
                continue;
            }
            // 遇到 ".."，弹出栈顶元素，这里使用双端队列 deque 模拟栈。
            else if (".." == token)
            {
                // std::vector 和 std::deque 为空时调用：container.pop_back() 是未定义行为（Undefined Behavior），极可能发生内存泄漏。
                // 有可能遇到 "/../" 这种用例，需要判断下当前栈是否为空，才能判断能否弹出。
                if (!parts.empty()) parts.pop_back();
            }
            else
            {
                parts.push_back(token);
            }
        }

        std::string res;
        for (auto &part : parts) res += '/' + part;


        // 如果 res 为空，输出根目录 "/"。
        return !res.empty() ? res : "/";
    }
};
// @lc code=end


int main()
{
    Solution solution;

    std::cout << solution.simplifyPath("/home/") << std::endl;
    std::cout << solution.simplifyPath("/home//foo/") << std::endl;
    std::cout << solution.simplifyPath("/home/user/Documents/../Pictures") << std::endl;
    std::cout << solution.simplifyPath("/../") << std::endl;
    std::cout << solution.simplifyPath("/.../a/../b/c/../d/./") << std::endl;
}


/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
