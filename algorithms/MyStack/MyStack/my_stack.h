//
//  my_stack.h
//  MyStack
//
//  Created by n.kuznetsov on 01/04/2019.
//  Copyright © 2019 n.kuznetsov. All rights reserved.
//
#ifndef my_stack_h
#define my_stack_h

#include <vector>
#include <exception>

using namespace std;

template<class T> class Stack {
public:
    Stack() {
        increment_ = 8;
        capacity_ = increment_;
        size_ = 0;
        data_ = new T[capacity_];
    }
    
    void push(T elem) {
        if (size_ != capacity_) {
            data_[size_] = elem;
        } else {
            capacity_ = size_ + increment_;
            T* new_data = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete [] data_;
            data_ = new_data;
            data_[size_] = elem;
        }
        ++size_;
    }
    
    T pop() {
        if (size_ > 0) {
            T result = data_[size_ - 1];
            --size_;
            return result;
        } else {
            throw runtime_error("Can not return a value from empty stack");
        }
    }
    
    T top() {
        if (size_ > 0) {
            return data_[size_ - 1];
        } else {
            throw runtime_error("Can not return a value from empty stack");
        }
    }
    
    bool isEmpty() {
        return size_ == 0 ? true : false;
    }
    
private:
    T* data_;
    size_t size_;
    size_t capacity_;
    size_t increment_;
};

#endif /* my_stack_h */
