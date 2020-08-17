#include "util.h"
#include "classSelf.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}