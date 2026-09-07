/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */


#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"

// @lc code=start


class Solution
{

public:


    int lengthLongestPath(std::string input)
    {
        // 切分出来的目录结构如下：
        /*
            "dir"
            "\tsubdir1"
            "\t\tfile1.ext"
            "\t\tsubsubdir1"
            "\tsubdir2"
            "\t\tsubsubdir2"
            "\t\t\tfile2.ext"
        */
        // 除了根目录，下面所有的子目录和都以 \t 制表符起手，只是根据不同级别的子目录对应的制表符个数不同。以上面的例子为例，当遇到文件的时候，就计算当前路径的长度，并维护全局最大值。当遇到级别更低的子目录时，代表进入新子目录，例如上面从 subdir1 进入 subdir2，应当抛弃 subdir1 的部分。因此使用栈。

        // 另一个例子是没有根目录的。
        /*
            "file1.txt"
            "file2.txt"
            "longfile.txt"
        */


        int res = 0;

        // 栈中存储当前级别目录的长度即可。因为需要 for each，使用双端队列。
        std::deque<int> st;

        auto parts = spilt(input, '\n');
        for (auto &part : parts)
        {
            // 使用 int 类型接受 rfind 返回值，找不到返回 -1。下面的 pop_back() 逻辑会把栈清空，并且 push_back() 整个字符串的长度，这是符合预期的。
            int pos = static_cast<int>(part.rfind('\t'));

            while (st.size() > pos + 1) st.pop_back();
            st.push_back(part.size() - pos - 1);

            if (std::string::npos != part.find('.'))
            {
                int sum = 0;
                for (auto &len : st) sum += len;
                // 加上分隔符。
                sum += st.size() - 1;

                res = std::max(res, sum);
            }
        }


        return res;
    }


private:

    std::vector<std::string> spilt(const std::string &s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::stringstream ss(s);

        while (std::getline(ss, token, delimiter)) tokens.emplace_back(token);


        return tokens;
    }
};
// @lc code=end


int main()
{
    Solution solution;
    // your test code here

    std::string s("\t\t\tsubdir1");
    std::cout << s.rfind('\t') << std::endl;
    std::cout << static_cast<int>(s.rfind('3')) << std::endl;
}
