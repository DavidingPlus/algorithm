/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <unordered_map>

class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto iter = keyVal.find(key);
        if (keyVal.end() == iter)
            return -1;

        int freq = keyToIter[key].first;
        auto listIter = keyToIter[key].second;
        // 从这个freq中弹掉
        freqToKeys[freq].erase(listIter);
        // 弹出后为空记得删除!!!
        if (freqToKeys[freq].empty())
            freqToKeys.erase(freq);
        // 添加到下一个的头部
        if (freqToKeys.end() != freqToKeys.find(1 + freq))
            freqToKeys[1 + freq].push_front(key);
        else
            freqToKeys.insert({1 + freq, list<int>{key}});
        // 修改keyToIter
        keyToIter[key] = {1 + freq, freqToKeys[1 + freq].begin()};

        return iter->second;
    }

    void put(int key, int value) {
        if (capacity == keyVal.size()) {
            // 弹掉使用频率最小的并且最久未使用的
            int targetKey = freqToKeys.begin()->second.front();
            // 从freqToKeys中删除
            freqToKeys.begin()->second.pop_front();
            // 弹出后为空记得删除!!!
            if (freqToKeys.begin()->second.empty())
                freqToKeys.erase(freqToKeys.begin());
            // 从keyVal中删除
            keyVal.erase(targetKey);
            // 从keyToIter中删除
            keyToIter.erase(targetKey);
        }
        // TODO
    }

private:
    int capacity;

    // 经过分析需要三个数据结构
    unordered_map<int, int> keyVal;                                // 存储键值对
    map<int, list<int>, less<int>> freqToKeys;                     // 存储使用频率到键值的映射，为了有序使用map
    unordered_map<int, pair<int, list<int>::iterator>> keyToIter;  // 存储键值到freq和迭代器的映射，方便修改
};

/**
 * Your LFUCache object will be instantiated && called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
