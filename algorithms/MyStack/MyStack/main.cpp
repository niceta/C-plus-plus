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
    s.push(5);
    s.push(3);
    int top = s.top();
    int pop = s.pop();
    std::cout << "Hello, World!\n";
    return 0;
}
