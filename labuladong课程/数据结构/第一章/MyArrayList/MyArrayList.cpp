#include "MyArrayList.h"

/**
 * @brief 下面是对类内函数的实现
 */
// 需要显式模板实例化
template class MyArrayList<int>;

template <class value_type>
inline void MyArrayList<value_type>::_init() {
    capacity = INIT_CAP;
    data = new value_type[capacity];
    size = 0;
}

template <class value_type>
inline void MyArrayList<value_type>::resize(int cap) {
    // 开辟一段新空间
    value_type *newdata = new value_type[cap];
    // 将原来的数组值
    memcpy(newdata, data, sizeof(value_type) * size);

    // 更新capacity
    capacity = cap;

    value_type *tmp = data;
    data = newdata;
    delete[] tmp;
}

template <class value_type>
inline MyArrayList<value_type>::MyArrayList() {
    _init();
}

// 这里需要初始化，所以需要构造函数委托
template <class value_type>
inline MyArrayList<value_type>::MyArrayList(std::initializer_list<value_type> list) : MyArrayList<value_type>() {
    for (auto &val : list)
        push_back(val);
}

template <class value_type>
inline MyArrayList<value_type>::~MyArrayList() {
    delete[] data;
}

template <class value_type>
inline MyArrayList<value_type> &MyArrayList<value_type>::operator=(const MyArrayList<value_type> &array) {
    // 检测自我赋值
    if (this == &array)
        return *this;

    // 不是先杀掉自己，然后赋值，深拷贝
    size = array.size;
    capacity = array.capacity;

    auto tmp = data;

    data = new value_type[array.capacity];
    memcpy(data, array.data, sizeof(value_type) * size);

    delete[] tmp;

    return *this;
}

template <class value_type>
inline MyArrayList<value_type>::MyArrayList(const MyArrayList<value_type> &array) {
    *this = array;
}

template <class value_type>
inline void MyArrayList<value_type>::push_back(const reference val) {
    if (size == capacity)  // 需要进行扩容
        resize(2 * capacity);

    // 否则在末尾插入
    data[size++] = val;
}

template <class value_type>
inline void MyArrayList<value_type>::tranverse(call_back call) {
    for (int i = 0; i < size; ++i)
        call(data[i]);
}