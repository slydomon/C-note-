#include <iostream>
#include <memory>



template<class T>
class sp
{
public:
    sp() ;
    sp(T* p) ;
    ~sp() ;
    sp(sp<T>& right) ;
    sp<T>& operator= (sp<T>& right) ;
    sp(sp<T>&& right) ;
    sp<T>& operator= (sp<T>&& right) ;
    inline T* get(){return ptr ;} 
    inline int user_count(){return !ref_count ? -1: *ref_count ;}
private:
    T* ptr ;
    int* ref_count ;
} ;

template<class T>
sp<T>::sp()
{
    ptr = nullptr ;
    ref_count = new int(0) ;
}

template<class T>
sp<T>::sp(T* p)
{
    ptr = p ;
    ref_count = new int(1) ;
}

template<class T>
sp<T>::~sp()
{

    if(ref_count) --(*ref_count) ;
    if(ptr && *ref_count == 0) 
        delete ptr ;
    else
        ptr = nullptr ;
}

template<class T>
sp<T>::sp(sp<T>& right)
{
   // --(*ref_count) ;
   // if(*ref_count == 0) delete ptr ;
    ref_count = right.ref_count ;
    ++(*ref_count) ;
    ptr = right.ptr ;
} 

template<class T>
sp<T>& sp<T>::operator= (sp<T>& right)
{

    if(ref_count)--(*ref_count) ;
    if(*ref_count == 0 && ptr) delete ptr ;
    ref_count = right.ref_count ;
    ++(*ref_count) ;
    ptr = right.ptr ;
    return *this ;
}  
template<class T>
sp<T>::sp(sp<T>&& right)
{
    swap(this, right) ;
    right.ptr = nullptr ;
}

template<class T>
sp<T>& sp<T>::operator= (sp<T>&& right)
{
    swap(this, right) ;
    right.ptr = nullptr ;
    return *this ; 
} 


int main()
{
    //see whether share_prt can manage a exsited obj
    int* ptr1 = new int(10) ;
    int* ptr2 = ptr1 ;
    std::shared_ptr<int> spt(ptr1) ;
    std::cout << "shared by" << spt.use_count() << std::endl;
    std::cout << ptr1 << " " << spt.get() << " " << ptr2 << std::endl ; 
    //The reference count begins counting after the manage obj initialize.

    // whether get will increment the reference count .
    std::shared_ptr<int> spt1(new int(8)) ;
    int* ptr3 = spt1.get() ; 
    int* ptr4 = ptr3 ;
    std::cout << "share by" << spt1.use_count() << std::endl ;
    std::cout << ptr3 << " " << ptr4 << " " << spt1.get() << std::endl ;

    //test sp
    sp<int> sp1 ;
    sp<int> sp2(new int(9)) ;
    std::cout << sp2.user_count() << std::endl ;
    //test copy constructer ;
    sp<int>sp3(sp2) ;
    sp1 = sp2 ;
    std::cout << sp2.user_count()  << " " << sp3.user_count() << std::endl ;
    sp<int> sp4 (new int(10)) ;
    sp3 = sp4 ;
    std::cout << sp4.user_count() << " " << sp2.user_count() << std::endl ;

    return 0;
}