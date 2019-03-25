#include <iostream>
#include <memory>


template<class T>
class Vec
{
public:
    Vec();
    Vec(size_t len);
    Vec(size_t len, const T& val) ;
    ~Vec();

    /***/
    Vec(const Vec<T>& right) ;
    Vec(Vec<T>&& right) ;


    /***/
    Vec<T>& operator =(const Vec<T>& right) ;
    /***/
    Vec<T>& operator =(Vec<T>&& right) ;

    inline size_t size2() const { return size ;} 
    inline size_t capacity2() const {return capacity ;}
    inline bool empty() const { return size == 0;} ;
    inline void push_back(const T& val)
    {
        //T* tmp = nullptr ;
        if(capacity <= size)
        {
            if(capacity == 0) capacity = 20 ;
            else capacity *= 2 ;
            std::unique_ptr<T[]> tmp = std::unique_ptr<T[]>(new T[capacity]) ;
            for(int i = 0 ; i < size ; ++i) tmp.get()[i] = ptr.get()[i] ;
            //if(ptr) delete[] ptr ;
            ptr = std::move(tmp) ;
            tmp = nullptr ; //prevent delete.
        }
        ptr.get()[size] = val ;
        ++size ;

    }
    inline bool pop_back()
    {
        if(size == 0)
        {
            std::cout << "no element" << std::endl ;
            return false ;
        }
        else
        {
            --size ; 
            return true ;
        }
    } ;
    inline T& operator[] (const size_t& idx)
    {
        if(idx >= size) 
        {
            std::cout << "invalid access element" << std::endl ;
            return ptr.get()[size+1] ;
        }
        else
            return ptr.get()[idx] ;
    }
    inline T* begin() const {return ptr.get() ;} 
    inline T* end() const {return ptr.get()[size+1] ;} ;
private:
    //T* ptr ;
    std::unique_ptr<T[]> ptr ;
    size_t size  ;
    size_t capacity ;
} ;

template<class T>
Vec<T>::Vec()
{ 
    ptr = std::unique_ptr<T[]>(new T[20]); 
    capacity = 20 ;
    size = 0 ;
}

template<class T>
Vec<T>::Vec(size_t len)
{
     ptr = std::unique_ptr<T[]>(new T[len]) ; 
     size = 0 ;
     capacity = len ;
}

template<class T>
Vec<T>::Vec(size_t len, const T& val)
    {
        ptr = std::unique_ptr<T[]>(new T[len*2]) ;
        size = len ;
        capacity = len*2 ;
        for(int i = 0 ; i < size ; ++i) ptr.get()[i] = val ;
    } 

template<class T>
Vec<T>::~Vec()
{ 
    //delete[] ptr ; /***/
} 

    /***/
template<class T>
Vec<T>::Vec(const Vec<T>& right) 
    {
        ptr = std::unique_ptr<T[]>(new T[right.capacity]);
        size = right.size ;
        capacity = right.capacity ;
        for(int i = 0 ; i < size ; ++i) ptr.get()[i] = right.ptr.get()[i] ;
    }

    /***/
template<class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& right) 
    {
        //if(this == &right) return *this ; /***/
        //if(ptr) delete[] ptr ; /***/
        ptr = std::unique_ptr<T[]>(new T[right.capacity]) ;
        size = right.size ;
        for(int i = 0 ; i < size ; ++i) ptr.get()[i] = right.ptr.get()[i] ;
        return *this ; /***/
    }

template<class T>
Vec<T>::Vec(Vec<T>&& right)
{
    swap(this->ptr, right->prt) ;
    //right->ptr = nullptr ;
    swap(this->capacity, right->capacity) ;
    swap(this->size, right->size) ;
}

template<class T>
Vec<T>& Vec<T>::operator=(Vec<T>&& right)
{
    swap(this->ptr, right->prt) ;
    //right->ptr = nullptr ;
    swap(this->capacity, right->capacity) ;
    swap(this->size, right->size) ;
}

