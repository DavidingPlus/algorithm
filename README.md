# algorithm

算法学习仓库，记录 LeetCode、XMake、hello-algo、蓝桥杯以及其他算法资料。

当前分支统一使用 XMake 管理可以构建的 C++ 项目，仓库中没有保留 CMake 架构。

## 目录结构

| 目录 | 内容 |
| --- | --- |
| leetcode/cpp-template | LeetCode C++ 题解、公共数据结构和 XMake 配置 |
| leetcode/java-template | LeetCode Java 模板 |
| leetcode/python-template | LeetCode Python 模板 |
| leetcode/go-template | LeetCode Golang 模板 |
| leetcode/js-template | LeetCode JavaScript 模板 |
| hello-algo | hello-algo 项目的学习代码 |
| algo-learning | 算法课程和其他学习资料 |
| lanqiao-review | 蓝桥杯复习代码和资料 |

根目录的 xmake.lua 当前包含以下两个子项目：

- leetcode/cpp-template
- hello-algo

algo-learning 和 lanqiao-review 主要用于保存学习资料，不参与根目录的 XMake 构建。

## 环境要求

- [XMake](https://xmake.io/)
- 支持 C++17 的编译器，用于构建 hello-algo
- 支持 C++17 的编译器，用于构建 LeetCode C++ 题解

Linux、macOS 和 Windows 均可使用 XMake。当前 LeetCode C++ 代码已针对 Linux 和 Windows 配置；macOS 默认编译器不一定提供 `bits/stdc++.h`，使用前需要确认编译器支持该头文件。

## XMake 常用命令

在仓库根目录执行：

~~~bash
# 配置为 Debug 模式
xmake f -m debug

# 构建默认目标
xmake

# 构建全部目标
xmake -a

# 构建指定 target
xmake binary_search

# 运行指定 target
xmake run binary_search

# 运行 LeetCode 题目
xmake run '167.两数之和 II - 输入有序数组_cn'

# 清理构建产物
xmake clean
~~~

LeetCode target 的名称通常由“源文件名 + 语言后缀”组成：

~~~text
167.两数之和 II - 输入有序数组.cpp
                                ↓
167.两数之和 II - 输入有序数组_cn
~~~

中文、空格和标点可以出现在 XMake target 名称中；在命令行中运行时，建议使用引号包住完整名称。xmake -l 可以查看当前工程注册的全部 target。

## LeetCode C++ 架构

LeetCode C++ 代码位于：

~~~text
leetcode/cpp-template/
└── leetcode/editor/
    ├── cn/       # 中文题解
    ├── en/       # 英文题解
    └── common/  # 公共代码
~~~

leetcode/cpp-template/xmake.lua 会自动扫描 cn 和 en 目录中的 .cpp 文件，并为每个题解创建一个独立的可执行 target。

公共代码会先编译为 common 静态库，包含：

- ListNode.cpp：链表节点及链表辅助方法
- TreeNode.cpp：二叉树节点及二叉树辅助方法
- globalmacros.h：跨平台万能头文件入口

题解模板只需要包含：

~~~cpp
#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"
~~~

### 跨平台万能头文件

globalmacros.h 会根据平台选择标准库头文件：

- Linux：使用系统提供的 `<bits/stdc++.h>`
- Windows：使用仓库中的 common/bits/stdc++.h

macOS 目前会走非 Windows 分支，因此需要使用能够提供 `<bits/stdc++.h>` 的编译器。

因此题解代码不需要针对操作系统修改头文件引用。

## VS Code 与 Labuladong 插件

项目中的 .vscode/settings.json 保存了 labuladong-leetcode.filePath 配置，用于控制不同语言题解的生成目录和文件名。

labuladong-leetcode.customCodeTemplate 属于应用程序级设置，不能写入项目的 .vscode/settings.json。请在 VS Code 的“默认配置文件”用户设置中找到该配置项，并将值设置为以下模板内容：

~~~cpp
#include "../common/globalmacros.h"
#include "../common/ListNode.h"
#include "../common/TreeNode.h"
#include "../common/Node.h"

${question.code}

int main()
{
    Solution solution;
    // your test code here
}
~~~

其中 ${question.code} 是插件占位符，请保持不变：

~~~text
${question.code}
~~~

打开用户设置的方法：

1. 按 Ctrl+Shift+P
2. 执行 Preferences: Open User Settings (JSON)
3. 确认当前使用的是“默认配置文件”
4. 配置 labuladong-leetcode.customCodeTemplate

生成的 C++ 题解应位于 leetcode/cpp-template/leetcode/editor/cn 或 leetcode/cpp-template/leetcode/editor/en 中。

## 其他说明

- 构建过程中产生的 build/、.xmake/ 等目录已加入 .gitignore。
- .vscode/settings.json 已纳入版本控制，其他 .vscode 文件默认忽略。
- leetcode/README.md 保留了 LeetCode 插件模板的原始说明。

### 本地修改 `.vscode/settings.json`

`.vscode/settings.json` 已提交到仓库。如果只希望保留远端提交的版本，同时允许本地工具修改该文件而不显示为 Git 变更，可以在当前仓库执行：

~~~bash
git update-index --skip-worktree .vscode/settings.json
~~~

检查是否生效：

~~~bash
git ls-files -v .vscode/settings.json
~~~

输出以小写 `s` 开头表示已启用。恢复正常追踪：

~~~bash
git update-index --no-skip-worktree .vscode/settings.json
~~~

该设置只对当前本地仓库生效，不会同步给其他协作者或新克隆的仓库。

