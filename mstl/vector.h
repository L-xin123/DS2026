// mstl/vector.h
#ifndef MSTL_VECTOR_H
#define MSTL_VECTOR_H

#include <cstddef> // 用于 size_t
#include <stdexcept> // 用于异常

// 所有自定义的 STL 组件都放在 mstl 命名空间内，避免与标准库冲突
namespace mstl {

template <typename T>
class Vector {
public:
    // 构造函数：创建空向量
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    // 析构函数：释放内存
    ~Vector() {
        delete[] data_;
    }

    // 添加元素到末尾
    void push_back(const T& value) {
        if (size_ == capacity_) {
            // 容量不足时，按 2 倍扩容
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            reserve(new_capacity);
        }
        data_[size_] = value;
        ++size_;
    }

    // 重载 [] 运算符，支持下标访问
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // 返回当前元素个数
    size_t size() const {
        return size_;
    }

    // 返回当前容量
    size_t capacity() const {
        return capacity_;
    }

    // 判断是否为空
    bool empty() const {
        return size_ == 0;
    }

    // insert(r,e)  在秩为r处，插入元素e，无返回值
    void insert(size_t r,const T&e){
        //1.检查下标是否越界
        if(r>size_) return;

        //2.如果容量满了，触发成倍扩容
        if (size_ == capacity_){
            reserve(capacity_==0?1:capacity_*2);
        }
        //3.数据后移：从最后一个元素开始，依次向后移一位
        for(size_t i=size_;i>r;i--){
            data_[i] = data_[i-1];
        }

        //4.输入新元素，并更新size
        data_[r]=e;
        size_++;
    }

    //删除秩为r的元素，并且返回删除值
    T remove(size_t r){
        //1.检查下标是否越界
        if(r>=size_) return T();

        //2.备份要删除的元素
        T old_value = data_[r];

        //3.数据前移：从r+1开始，依次向前移一位覆盖
        for(size_t i = r;i+1<size_;i++){
            data_[i] = data_[i+1];
        }

        //4.更新size
        size_--;

        //5.输出被删除的元素
        return old_value;
    }

private:
    // 重新分配内存，将容量调整为 new_capacity
    void reserve(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    T* data_;           // 指向动态数组的指针
    size_t size_;       // 当前元素个数
    size_t capacity_;   // 当前容量
};

} // namespace mstl

#endif // MSTL_VECTOR_H