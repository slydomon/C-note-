#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<functional>

using namespace std;

//function type must be const T&
//cannot infer type from function return type.


template<typename T>
double add(T t)
{
    return t ;
}

template<typename H, typename ...REST>
double add(H head, REST ...rest)
{
    return head + add(rest...) ;
}


//proper base case;
//no type param after variadic
//need to assign with function
/*
template<typename H, bool b>
class filter{} ;

template<typename H>
class filter<H, 1>
{
public:
    filter(){} ;
    H operator()(H head){res.push_back(head) ; return res ;}
private:
    vector<H> res ;
} ;
*/
//functor:
//initialize the functor (with certain value since functor itself can be a higher order function)
//overload ()operator with the real function behavior.
/*
template<typename H>
class filter<H, 0> 
{
public:
    filter(){} ;
    H operator()(H head){return res ;}
private:
    vector<H> res ;
};
*/

template<typename H, typename R>
vector<R> map(function<R(H)> func)
{
    return ;
}

template<typename H, typename ...REST, typename R>
vector<R> map(function<R(H)> func, H head, REST ...rest)
{
    return {func(head), func(rest)...} ;
}


template<typename H, typename R>
R reduce(function<R(H, R)>func)
{
    return R();
}

template<typename H, typename ...REST, typename R>
R reduce(function<R(H, R)>func, H head, REST ...rest)
{
    return func(head, reduce(func, rest...)) ;
}




template<typename T>
function<vector<T>(T, vector<T>)> buildFilter(function<bool(T)> func)
{
    //[=] allow lamda to use variable outside lamda function.
    return [=](T a, vector<T> b){if(func(a)) b.push_back(a) ; return b ;};
}

template<typename T>
vector<T> filter(function<bool(T)> filterFunc)
{
    return vector<T>();
}

template<typename T, typename ...REST>
vector<T> filter(function<bool(T)> filterFunc, T head, REST ...rest)
{
    //function<vector<T>(T, vector<T>)> f = buildFilter(filterFunc) ;
    return (buildFilter(filterFunc))(head, filter(filterFunc, rest...)) ;
}

//corresponding func for performance comparison
vector<int> map(vector<int> input)
{
    for (auto&& v : input)
    {
        v -= 0.1 ;
    }
    return input ;
}

//utility
template<typename T>
void print(const vector<T>& in)
{
    for(int i = 0 ; i < in.size() ; ++i)
        cout << in[i] << " " ;
    cout << endl ;
}

//pass int function:
string add_ (int a  , string b) { return b + to_string(a) ;}
double minus_(int a){ return double(a) - 0.1 ;}
bool isGreaterThan3(int a){ return a > 3 ;}

int main()
{
    function<string(int, string)> f = add_ ;
    int a = 4 ;
    cout << reduce(f,1,a,0,4,5) << endl ;
    function<double(int)> f2 = minus_ ;
    vector<double> v = map(f2, 1,2,3,4,5) ;
    print(v) ;
    function<bool(int)> g3 = isGreaterThan3 ;
    function<vector<int>(int, vector<int>)> f3v = buildFilter(g3) ;
    vector<int> v2 = reduce(f3v, 1,2,3,4,5,6) ;
    vector<int> v3 = filter(g3, 1,2,3,4,5,6) ;
    print(v2 ) ;
    print(v3) ;
    return 0 ;
}