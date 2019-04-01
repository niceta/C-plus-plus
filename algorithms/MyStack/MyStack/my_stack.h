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
        data_ = {};
    }
    
    void push(T elem) {
        data_.push_back(elem);
    }
    
    T pop() {
        if (data_.size() > 0) {
            T result = data_[data_.size() - 1];
            data_.pop_back();
            return result;
        } else {
            throw runtime_error("Can not return a value from empty stack");
        }
    }
    
    T top() {
        if (data_.size() > 0) {
            return data_[data_.size() - 1];
        } else {
            throw runtime_error("Can not return a value from empty stack");
        }
    }
    
    bool isEmpty() {
        return data_.size() == 0 ? true : false;
    }
    
private:
    vector<T> data_;
};

#endif /* my_stack_h */
