#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

class sema
{
public:
    sema(const unsigned& re):resource(re){} 
    ~sema(){} 
    void post()
    {    
        std::unique_lock<std::mutex> local_lock(resource_lock) ;
        std::cout << "resource: " << (int)resource << std::endl ;
        ++resource ;
        cv.notify_all() ;
    }
    void wait()
    {
        std::unique_lock<std::mutex> local_lock(resource_lock) ;
        while(resource == 0)
            cv.wait(local_lock, [=]{
                std::cout << "wait" << std::endl;
                return resource > 0 ;}) ; //go if resouce > 0 ;
        //critical section
        std::cout << "resource: " << (int)resource << std::endl ;
        --resource ;

    } 
private:
    std::mutex resource_lock ;
    std::condition_variable cv ;
    unsigned resource = 1 ;
};


