#include <iostream>
#include "add.h"

int main() {

        std::cout << "Hello World!\n" << std::endl;

        int a, b;

        std::cout << "Bitte Zahl a eingeben:" << std::endl;
        std::cin >> a;
        std::cout << "\nBitte Zahl b eingeben:" << std::endl;
        std::cin >> b;

        std::cout << "\n" << a << " + " << b << " = " << add(a, b) << std::endl;

        return 0;

}
