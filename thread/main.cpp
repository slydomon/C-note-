//learn join, detach
//learn mutex, conditional variable
//pass function<> into thread to execute ;

//#include<iostream>
#include<thread>
#include<functional>
#include<queue>
#include "sema.cpp"
//#include "asyn.cpp"

using namespace std ;

static int target = 0 ;
std::mutex m ;
std::condition_variable cv ;
bool ready = false ;
sema semaphore(5) ;

void incr_5(int& t)
{

    for(int i = 0 ; i < 5 ; ++i) 
    {
        semaphore.wait() ;
        //cout << "thread id: " << this_thread::get_id() << endl ;
        //semaphore.post() ;
    }
}

int main()
{
    //function<void()> print_foo = [](){cout << "foo" << endl ;} ;
    //function<void()> print_bar = [](){cout << "bar" << endl; } ;
    //function<int(int, int)> addition =[](int a, int b){ cout << a+b << endl ;return a+b ;} ;
    function<void(int&)> incr = incr_5 ;
    thread foo(incr, ref(target)) ;
    thread bar(incr, ref(target)) ;
    thread add(incr, ref(target)) ;

    foo.detach() ;
    bar.join() ;
    add.join() ;
    string f1 = "/Users/kevinyang/CPlusPlus-Note/thread/2.txt" ;
    string f2 = "/Users/kevinyang/CPlusPlus-Note/thread/1.txt" ;
    //asynRead(f1) ;
    //asynRead(f2) ;

    while(true){;} 

    cout << "all threads complete" << endl ;
    return 0 ;
}