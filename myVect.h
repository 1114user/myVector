#pragma once
#include <iostream>


class myVector {
private:
    int* m_data;
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
        m_data = new int[m_size];
        for (int i = 0; i < s; i++) {
            m_data[i] = 0;
        }
    }
    myVector(int s, int num) {
        m_size = s;
        m_capacity = s;
        m_data = new int[m_size];
        for (int i = 0; i < s; i++) {
            m_data[i] = num;
        }
    }
    ~myVector() {
        delete[] m_data;
    };
    void push_back(int num) {
        if (m_size ==  m_capacity) {
            m_capacity = m_capacity == 0? 1:m_capacity*=2;
            int* temp = new int[m_capacity];
            for (int i = 0; i < m_size; i++) {
                temp[i] = m_data[i];
            }
            delete[] m_data;
            m_data = temp;
        }
        m_data[m_size] = num;
        m_size++;
    }
};