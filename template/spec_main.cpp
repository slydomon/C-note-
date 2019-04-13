#include <iostream>
#include <utility>

using namespace std ;

enum Side {Buy = 0, Sell} ;

template<typename T>
float calPrice()
{
    cout << "RAW" << endl ;
    return 200.0 ;
}

template<Side>
float calPrice()
{
    cout << "RAW" << endl ;
    return 200.0 ;
}

template<>
float calPrice<Side::Buy>()
{
    cout << "buy 200.00" << endl ;
    return 200.0 ;
}

template<>
float calPrice<Side::Sell>()
{
    cout << "Sell 500.00" << endl ;
    return 500.0 ;
}

/*
void RunLogic(Side side)
{
    const float orderPrice = calPrice<side>(side) ;
    std::cout << orderPrice << std::endl ;
}
*/

template<bool T, int A, int B>
struct min_const
{
    static const int value = min_const<T, A, B>::value ;
};

template<>
struct min_const<true, int, int>
{
    static const int value = 3  ;
};

template<>
struct min_const<false, int , int>
{
   static const int value = 5 ;
};


template <int T>
struct Fibonacci
{
    enum { value = (Fibonacci<T - 1>::value + Fibonacci<T - 2>::value) };
};

// In the template meta-programming, we do not have conditionals, so instead
// we use struct-overloading like mechanism to set constraints, we do this for
// numbers 0, 1 and 2, just like our algorithm in the function above.
template <>
struct Fibonacci<0>
{
    enum { value = 1 };
};

template <>
struct Fibonacci<1>
{
    enum { value = 1 };
};

template <>
struct Fibonacci<2>
{
    enum { value = 1 };
};

int main()
{

    //cout << "buy" << calPrice<Side::Buy>() <<endl ;
    //cout << "sell" << calPrice<Side::Sell>() <<endl; 
    int a = 4 ;
    int b = 5 ;
    cout << min_const< 4 < 5, 4, 5>::value <<endl ;
    return 0 ;
}