#include <iostream>
#include <functional>
#include <type_traits>
#include <string>

class Base
{
    std::string s ;
};


int main()
{
    int a = 10 ;
    int& ref = a ;
    const int c = 20 ;
    Base base() ;
    Base* ptr_base = new Base() ;
    std::cout << std::is_const<decltype(a)>::value << std::endl;
    std::cout << std::is_const<decltype(c)>::value << std::endl;
    std::cout << std::is_reference<decltype(a)>::value << std::endl;
    std::cout << std::is_reference<decltype(ref)>::value << std::endl;
    std::cout << std::is_class<decltype(a)>::value << std::endl;
    std::cout << std::is_class<decltype(base)>::value << std::endl;
    std::cout << std::is_class<decltype(ptr_base)>::value << std::endl;
    return 0 ;

}