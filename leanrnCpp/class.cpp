//
// Created by qzj on 2020/8/31.
//

#include "util.h"
#include "classSelf.h"


#include <iostream>
#include <thread>

using namespace std;
int main() {

    for(int i;i<4;)
        cout<<++i<<endl;

    std::cout << "Hello, World!" << std::endl;

    Base* base = new A;
    base->baseMethod();
    delete base;
    A* a = new A;
    a->virtaulTest();
    a->override();
    return 0;
}