#include <iostream>
#include <thread>
#include <fstream>
#include <future>

using namespace std ;

void Read(const string& dir)
{
    ofstream out ;
    out.open(dir) ;
    for(int i = 0 ; i < 10000000 ; ++i)
        out << "this is acyn write" << i << endl ;
    out.close() ;
}

void asynRead(future<void>& fut, const string& dir)
{
    fut = async(launch::async, Read, dir) ;
}

void print()
{
    for(int i = 0 ; i < 10 ; ++i)
        cout << "this is acyn write" << i << endl ;
}

void asynPrint(future<void>& fut)
{
    fut = async(launch::async, print) ;
    cout << "end" ;
}



int main()
{
    string f1 = "/Users/kevinyang/CPlusPlus-Note/thread/2.txt" ;
    string f2 = "/Users/kevinyang/CPlusPlus-Note/thread/1.txt" ;
    future<void> fut1 ;
    future<void> fut2 ;
    asynRead(fut1, f1) ; //pass futre as reference so that it won't be distructed and block in the function
    asynPrint(fut2) ;

    //future<void> fut1 = async(launch::async, print) ;
    //future<void> fut2 = async(launch::async, Read, f1) ;
    cout << "main" ;
    while(true){;} 

    cout << "all threads complete" << endl ;
    return 0 ;
}