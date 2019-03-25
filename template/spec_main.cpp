#include <iostream>
#include <utility>

using namespace std ;

enum class Side {Buy = 0, Sell} ;

template<typename T>
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

int main()
{

    cout << "buy" << calPrice<Side::Buy>() <<endl ;
    cout << "sell" << calPrice<Side::Sell>() <<endl; 
    return 0 ;
}