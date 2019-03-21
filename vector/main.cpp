#include "vector.cpp"
#include <iostream>

using namespace std ;
int main()
{
    Vec<int> v0() ;
    Vec<int> v1(20, -1) ;
    std::cout << v1.capacity2() << " " << v1.size2() << std::endl ;
    v1.push_back(1) ;
    v1.push_back(1000) ;
    v1.push_back(3) ;
    int size = v1.size2() ;
    cout << size << endl ;
    std::cout << v1[size-3] << v1[size-2] << v1[size-1] << std::endl;
    v1.pop_back() ;
    std::cout << v1.size2() << std::endl ;
    std::cout << v1[2] <<std::endl ;
    return 0 ;
}