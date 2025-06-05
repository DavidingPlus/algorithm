#include "MyLinkedList.h"

// 显式实例化模板
template class MyLinkedList<int>;

/**
 * @brief 以下是对类内成员函数的初始化
 */
template <class value_type>
MyLinkedList<value_type>::MyLinkedList() {
    _init();
}

// 这里为了防止未初始化，先进行构造函数委托
template <class value_type>
MyLinkedList<value_type>::MyLinkedList(std::initializer_list<value_type> list) : MyLinkedList() {
    for (constref val : list)
        push_back(val);
}

template <class value_type>
MyLinkedList<value_type>::MyLinkedList(MyLinkedList<value_type>& other) {
    *this = other;
}

template <class value_type>
MyLinkedList<value_type>& MyLinkedList<value_type>::operator=(MyLinkedList<value_type>& other) {
    // 检测自我赋值
    if (this == &other)
        return *this;

    // 开始深拷贝
    length = other.length;

    std::vector<value_type> vals;
    for (int i = 0; i < other.size(); ++i)
        vals.push_back(other[i]);

    // 清空
    clear();

    for (auto val : vals)
        push_back(val);

    return *this;
}

template <class value_type>
MyLinkedList<value_type>::~MyLinkedList() {
    // 需要销毁所有堆上的结点
    nodeptr_t move = head;
    while (move) {
        nodeptr_t tmp = move;

        move = move->next;

        delete tmp;
    }
}

template <class value_type>
void MyLinkedList<value_type>::insert_before(int index, constref val) {
    _link_before(index, val);
}

template <class value_type>
void MyLinkedList<value_type>::insert_after(int index, constref val) {
    _link_before(index + 1, val);
}

template <class value_type>
void MyLinkedList<value_type>::push_back(constref val) {
    _link_before(length, val);
}

template <class value_type>
void MyLinkedList<value_type>::push_front(constref val) {
    _link_before(0, val);
}

template <class value_type>
value_type MyLinkedList<value_type>::remove(int index) {
    _check_index(index, "remove");

    // 定位到结点的位置
    nodeptr_t move = head->next;

    for (int i = 0; i < index; ++i)
        move = move->next;

    value_type ret = move->val;

    move->prior->next = move->next;
    move->next->prior = move->prior;

    delete move;

    --length;

    return ret;
}

template <class value_type>
value_type MyLinkedList<value_type>::pop_front() {
    return remove(0);
}

template <class value_type>
value_type MyLinkedList<value_type>::pop_back() {
    return remove(length - 1);
}

template <class value_type>
void MyLinkedList<value_type>::set(int index, constref val) {
    (*this)[index] = val;
}

template <class value_type>
typename MyLinkedList<value_type>::reference MyLinkedList<value_type>::operator[](int index) {
    _check_index(index, "get");

    // 得到指定结点的指针
    nodeptr_t move = get_node(index);

    return move->val;
}

template <class value_type>
value_type MyLinkedList<value_type>::get(int index) {
    return std::move((*this)[index]);
}

template <class value_type>
value_type MyLinkedList<value_type>::front() {
    return get(0);
}

template <class value_type>
value_type MyLinkedList<value_type>::back() {
    return get(length - 1);
}

template <class value_type>
void MyLinkedList<value_type>::traverse(call_back call) {
    for (nodeptr_t move = head->next; move != tail; move = move->next)
        call(move->val);
}

template <class value_type>
size_t MyLinkedList<value_type>::size() {
    return length;
}

template <class value_type>
bool MyLinkedList<value_type>::isEmpty() {
    return 0 == length;
}

template <class value_type>
void MyLinkedList<value_type>::clear() {
    this->~MyLinkedList<value_type>();

    _init();
}

template <class value_type>
void MyLinkedList<value_type>::_init() {
    head = new node;
    tail = new node;

    head->next = tail;
    tail->prior = head;
    length = 0;
}

template <class value_type>
void MyLinkedList<value_type>::_check_index(int index, std::string func_name) {
    // 在插入的时候index是可以等于length的，这时候相当于在末尾插入
    try {
        bool ret = false;
        if (func_name == "insert")
            ret = index < 0 || index > length;
        else
            ret = index < 0 || index >= length;

        if (ret) {
            char exception_str[1024] = {0};
            sprintf(exception_str, "%s position out of range.", func_name.c_str());

            throw std::out_of_range(exception_str);
        }
        return;
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}

template <class value_type>
void MyLinkedList<value_type>::_link_before(int index, constref val) {
    _check_index(index, "insert");

    // 得到指定结点的指针
    nodeptr_t move = get_node(index);

    // 插入
    nodeptr_t newnode = new node{val};

    newnode->next = move;
    newnode->prior = move->prior;
    move->prior->next = newnode;
    move->prior = newnode;

    ++length;
}

template <class value_type>
typename MyLinkedList<value_type>::nodeptr_t MyLinkedList<value_type>::get_node(int index) {
    // 定位到结点的位置
    nodeptr_t move = head->next;

    for (int i = 0; i < index; ++i)
        move = move->next;

    return move;
}
