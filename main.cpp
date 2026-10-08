// main.cpp
#include <iostream>
#include "mstl/vector.h" // 注意路径

int main() {
    // 创建一个存储整数的向量
    mstl::Vector<int> vec;

    // 测试 push_back
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i * 10);
    }

    // 测试 size 和 capacity
    std::cout << "Size: " << vec.size() << std::endl;       // 应输出 10
    std::cout << "Capacity: " << vec.capacity() << std::endl; // 应输出 16（扩容后的结果）

    // 测试 operator[]
    std::cout << "Element at index 3: " << vec[3] << std::endl; // 应输出 30

    // ================= 新增测试 =================
    std::cout << "--- 测试 insert ---" << std::endl;
    vec.insert(1, 99); // 在秩为1的位置插入99
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 预期输出：0 99 10 20 30 40 50 60 70 80 90

    std::cout << "--- 测试 remove ---" << std::endl;
    int deleted = vec.remove(2); // 删除秩为2的元素
    std::cout << "Deleted value: " << deleted << std::endl; // 预期输出：10
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; // 预期输出：0 99 20 30 40 50 60 70 80 90

    return 0;
}//
// Created by Administrator on 2026/10/8.
//
