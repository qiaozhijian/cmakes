#include "util.h"
#include "classSelf.h"


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//主线程usleep不影响分线程
class Model {
public:

    void SetNotErase();
    void SetErase();
    void Release();

private:
    std::mutex mMutexErase;
    bool mbNotErase;
    bool mbToBeErased;

};
class ThreadClass
{
public:
    ThreadClass(){
        var = 0.f;
        if(pInt)
        {
            cout<<"pInt exist"<<endl;
        }
        else
            cout<<"no pInt"<<endl;
    }
    std::mutex mMutex;
    float var;
    void th_function()
    {
        while(1)
        {
            unique_lock<mutex> lock(mMutex);
            usleep(5e3);
            setVar();
            std::cout << "hello thread." << std::endl;
        }
    }
    void setVar()
    {
        unique_lock<mutex> lock(mMutex);
        var = 10.f;
    }

    Model* pInt;
};


int main(int argc, char *argv[])
{
    ThreadClass* thClass = new ThreadClass();
    std::thread* t = new thread(&ThreadClass::th_function, thClass);
    //std::cout << "start sleep" << std::endl;
    //usleep(5e6);
    //std::cout << "finish sleep" << std::endl;
    t->join();
    std::cout << "finish" << std::endl;

    return 0;
}