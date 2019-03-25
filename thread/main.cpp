//learn join, detach
//learn mutex, conditional variable
//pass function<> into thread to execute ;

#include<iostream>
#include<thread>
#include<functional>
#include<queue>

using namespace std ;

static int target = 0 ;
mutex m ;

void incr_5(int& target)
{
    for(int i = 0 ; i < 5 ; ++i) 
    {
        m.lock() ;
        ++target ;
        cout << target << endl ;
        m.unlock() ;
    }
}

int main()
{
    function<void()> print_foo = [](){cout << "foo" << endl ;} ;
    function<void()> print_bar = [](){cout << "bar" << endl; } ;
    function<int(int, int)> addition =[](int a, int b){ cout << a+b << endl ;return a+b ;} ;
    function<void(int&)> incr = incr_5 ;
    thread foo(incr, ref(target)) ;
    thread bar(incr, ref(target)) ;
    thread add(incr, ref(target)) ;

    foo.detach() ;
    bar.join() ;
    add.join() ;


    cout << "all threads complete" << endl ;
    return 0 ;
}