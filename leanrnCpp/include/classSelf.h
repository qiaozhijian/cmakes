//
// Created by qzj on 2020/8/17.
//

#ifndef LEARNCPP_CLASSSELF_H
#define LEARNCPP_CLASSSELF_H

#include "iostream"

class Base{

    virtual void method()
    {
        std::cout  << "from base\r\n";
    }

public:
    Base(){
        std::cout  << "create Base\r\n";
    }
    virtual ~Base() {method();}
    void baseMethod()
    {
        std::cout  << "from baseMethod\r\n";
        method();
    }
    void override()
    {
        std::cout  << "from override base\r\n";
    }

    virtual void virtaulTest()
    {
        std::cout  << "from virtaulTest Base\r\n";
    }
};

class A:public Base {
    void method() override{std::cout  << "from A\r\n";}
public:
    A(){
        std::cout  << "create A\r\n";
    }
    ~A()
    {
        std::cout  << "from ~A\r\n";
        method();
    }
    void override()
    {
        std::cout  << "from override A\r\n";
    }

    //void virtaulTest()
    //{
    //    std::cout  << "from virtaulTest A\r\n";
    //}
};

#endif //LEARNCPP_CLASSSELF_H
