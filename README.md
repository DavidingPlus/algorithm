# algorithm

（待修改）

算法学习的仓库，记录了自己和朋友们的算法学习。

注：这些分支各自之间并不关联，只是用于区分工作和存储空间，也不要轻易的进行合并。

各分支功能概述：

- feature-liuzx-algo-learning：网上各种算法课程的学习。

- feature-liuzx-hello-algo：hello-algo 算法项目的学习。

- feature-liuzx-lanqiao-review：蓝桥杯的复习。

- feature-liuzx-leetcode：记录 leetcode 刷题。

- feature-yangjx-algo-learning：yangjx 同学的算法学习。

- feature-chengj-algo-learning：chengj 同学的算法学习。

- feature-xiaoyf-algo-learning：xiaoyf 同学的算法学习。

## XMake

根目录提供了与现有 CMake 架构对应的 `xmake.lua` 入口：

```bash
# 配置并构建默认目标
xmake

# 构建全部章节和题目
xmake -a

# 构建指定 target，例如 hello-algo 或 LeetCode 题目
xmake binary_search
xmake lc_1_cn
```

LeetCode 题目会自动扫描 `leetcode/editor/cn` 和 `leetcode/editor/en`，公共代码编译为 `common` 静态库；hello-algo 仍按章节维护独立可执行文件。
