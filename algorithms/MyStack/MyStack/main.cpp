//
//  main.cpp
//  MyStack
//
//  Created by n.kuznetsov on 01/04/2019.
//  Copyright © 2019 n.kuznetsov. All rights reserved.
//

#include <iostream>
#include "my_stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Stack<int> s;
    std::cout << s.isEmpty() << endl;
    
    try {
        int top = s.top();
        int pop = s.pop();
    } catch (...) {
        std::cout << "some sheet has been happened" << std::endl;
    }

    
    for (int i = 0; i < 9; ++i) {
        s.push(i);
    }
    
    for (int i = 0; i < 9; ++i) {
        std::cout << s.pop() << std::endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
