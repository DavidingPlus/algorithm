#include "MyArrayList.h"

// 需要显式模板实例化
template class MyArrayList<int>;

/**
 * @brief 静态变量类外初始化
 */
template <class value_type>
size_t MyArrayList<value_type>::INIT_CAP = 1;

/**
 * @brief 下面是对类内函数的实现
 */
template <class value_type>
inline void MyArrayList<value_type>::_init() {
    capacity = INIT_CAP;
    data = new value_type[capacity];
    _size = 0;
}

template <class value_type>
inline void MyArrayList<value_type>::_resize(size_t cap) {
    // 开辟一段新空间
    pointer newdata = new value_type[cap];
    // 将原来的数组值
    memcpy(newdata, data, sizeof(value_type) * _size);

    // 更新capacity
    capacity = cap;

    pointer tmp = data;
    data = newdata;
    delete[] tmp;
}

template <class value_type>
void MyArrayList<value_type>::_check_index(int index, std::string func_name) {
    // insert可以是size，但是其他的接口不能用size，这里进行特殊判断
    try {
        bool ret = false;
        if (func_name == "insert")
            ret = index < 0 || index > _size;
        else
            ret = index < 0 || index >= _size;

        if (ret) {
            char exception_str[1024] = {0};
            sprintf(exception_str, "%s postion was out of range.", func_name.c_str());

            throw std::out_of_range(exception_str);
        }
        return;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}

template <class value_type>
inline MyArrayList<value_type>::MyArrayList() {
    _init();
}

// 这里需要初始化，所以需要构造函数委托
template <class value_type>
inline MyArrayList<value_type>::MyArrayList(std::initializer_list<value_type> list) : MyArrayList<value_type>() {
    for (constref val : list)
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
    _size = array._size;
    capacity = array.capacity;

    auto tmp = data;

    data = new value_type[array.capacity];
    memcpy(data, array.data, sizeof(value_type) * _size);

    delete[] tmp;

    return *this;
}

template <class value_type>
inline MyArrayList<value_type>::MyArrayList(const MyArrayList<value_type> &array) {
    *this = array;
}

template <class value_type>
void MyArrayList<value_type>::insert(int index, constref val) {
    _check_index(index, "insert");

    // 判断是否需要进行扩容
    if (_size == capacity)
        _resize(2 * capacity);
    // 从最后一个(下标size-1)到index下标都往后移动
    // 第一次插入pos这里为-1，size_t会转化为补码，就会访问非法内存，所以这里pos使用ssize_t类型并且加上pos>0的判断
    for (ssize_t pos = _size - 1; pos > 0 && pos >= index; --pos)
        data[pos + 1] = data[pos];
    // 将新元素插入
    data[index] = val;
    ++_size;
}

template <class value_type>
inline void MyArrayList<value_type>::push_back(constref val) {
    insert(_size, val);
}

template <class value_type>
value_type MyArrayList<value_type>::remove(int index) {
    _check_index(index, "remove");

    // 删除元素
    value_type del_val = data[index];

    for (int pos = index; pos < _size - 1; ++pos)
        data[pos] = data[pos + 1];

    data[_size - 1] = (value_type)0;

    // 如果删除之后的大小小于capacity的四分之一，那么我们进行缩容
    if (--_size < capacity / 4)
        _resize(capacity / 2);

    return del_val;
}

template <class value_type>
value_type MyArrayList<value_type>::pop_back() {
    return remove(_size - 1);
}

template <class value_type>
value_type MyArrayList<value_type>::set(int index, constref val) {
    _check_index(index, "set");

    value_type pre_val = data[index];
    data[index] = val;

    return pre_val;
}

template <class value_type>
value_type MyArrayList<value_type>::get(int index) {
    _check_index(index, "get");

    return data[index];
}

template <class value_type>
typename MyArrayList<value_type>::reference MyArrayList<value_type>::operator[](int index) {
    _check_index(index, "operator []");

    return data[index];
}

template <class value_type>
inline void MyArrayList<value_type>::traverse(call_back call) {
    for (int i = 0; i < _size; ++i)
        call(data[i]);
}

template <class value_type>
size_t MyArrayList<value_type>::size() {
    return _size;
}

template <class value_type>
bool MyArrayList<value_type>::isEmpty() {
    return 0 == _size;
}
