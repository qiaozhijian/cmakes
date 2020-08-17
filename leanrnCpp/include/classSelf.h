//
// Created by qzj on 2020/8/17.
//

#ifndef LEARNCPP_CLASSSELF_H
#define LEARNCPP_CLASSSELF_H

#include "iostream"

class Base{
    virtual void method()
    {
        std::cout  << "from base\t";
    }

public:
    virtual ~Base() {method();}
    void baseMethod()
    {
        std::cout  << "from baseMethod\t";
        method();
    }

};

class A:public Base {
    void method(){std::cout  << "from A\t";}

public:
    ~A()
    {
        std::cout  << "from ~A\t";
        method();
    }
};

#endif //LEARNCPP_CLASSSELF_H
