#pragma once
#include <iostream>
#include <memory>

class myVector {
private:
    std::unique_ptr<int[]> m_data;
    size_t m_size;
    size_t m_capacity;
public:
    myVector() {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    myVector(int s) {
        m_size = s;
        m_capacity = s;
        m_data = std::make_unique<int[]>(s);
    }
    myVector(int s, int num) {
        m_size = s;
        m_capacity = s;
        m_data = std::make_unique<int[]>(s);
        for (int i = 0; i < s; i++) {
            m_data[i] = num;
        }
    }
    myVector(const myVector& a) {
        m_size = a.m_size;
        m_capacity = a.m_capacity;
        m_data = std::make_unique<int[]>(m_capacity);
        for (int i = 0; i < m_size; i++) {
            m_data[i] = a.m_data[i];
        }
    }
    myVector& operator=(const myVector& a) {
        if (this == &a) {
            return *this;
        }
        m_size = a.m_size;
        m_capacity = a.m_capacity;
        m_data = std::make_unique<int[]>(m_capacity);
        for (int i = 0; i < m_size; i ++) {
            m_data[i] = a.m_data[i];
        }
        return *this;
    }
    ~myVector() {};

    void push_back(int num) {
        if (m_size ==  m_capacity) {
            m_capacity = m_capacity == 0? 1:m_capacity*=2;
            std::unique_ptr<int[]> temp = std::make_unique<int[]>(m_capacity);
            for (int i = 0; i < m_size; i++) {
                temp[i] = m_data[i];
            }
            m_data = std::move(temp);
        }
        m_data[m_size] = num;
        m_size++;
    }
};