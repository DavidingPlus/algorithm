/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>

class LRUCache {
public:
    // 存储的数据我们用一个键值对pair<int,int>即可
    // 关键是我们怎么优化get通过键值查找数据的时间，首先我们肯定能想到哈希表，但是我们需要判断缓存队列的弹出，需要在小的时间复杂度内删除指定的值，或者把某个元素移动到头部，这么看起来双向链表的结构非常合适
    // 因此总结得出，关于get接口，我们通过unorder_map处理，键是int，值是链表的迭代器；然后我们维护一个list，根据键定位到迭代器，然后就可以操作list了

    LRUCache(int capacity) : capacity(capacity) {
    }

    int get(int key) {
        if (um.end() == um.find(key))
            return -1;
        // 返回值并且修改缓存的顺序
        int res = um[key]->second;
        // 把这个值放到缓存头部
        l.erase(um[key]);
        l.emplace_front(key, res);
        um[key] = l.begin();  // 注意不要忘了更新迭代器的值

        return res;
    }

    void put(int key, int value) {
        // 如果存在的话就是修改值，那么就先删掉
        if (um.end() != um.find(key))
            l.erase(um[key]);
        // 不存在就是插入值，需要判断是否超了，清理缓存
        else if (um.end() == um.find(key) && capacity == l.size()) {
            um.erase(l.back().first);  // 就是这里需要l存储key所以才需要pair
            l.pop_back();              // 从l中删除
        }

        // 插入头部并且修改缓存
        l.emplace_front(key, value);
        um[key] = l.begin();
    }

private:
    int capacity;

    unordered_map<int, list<pair<int, int>>::iterator> um;

    list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated && called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
