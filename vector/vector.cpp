#include <iostream>

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
            T* tmp = new T[capacity] ;
            for(int i = 0 ; i < size ; ++i) tmp[i] = ptr[i] ;
            if(ptr) delete[] ptr ;
            ptr = tmp ;
            tmp = nullptr ; //prevent delete.
        }
        ptr[size] = val ;
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
            return ptr[size+1] ;
        }
        else
            return ptr[idx] ;
    }
    inline T* begin() const {return ptr ;} 
    inline T* end() const {return ptr[size+1] ;} ;
private:
    T* ptr ;
    size_t size  ;
    size_t capacity ;
} ;

template<class T>
Vec<T>::Vec()
{ 
    ptr = new T[20]; 
    capacity = 20 ;
    size = 0 ;
}

template<class T>
Vec<T>::Vec(size_t len)
{
     ptr = new T[len] ; 
     size = 0 ;
     capacity = len ;
}

template<class T>
Vec<T>::Vec(size_t len, const T& val)
    {
        ptr = new T[len*2] ;
        size = len ;
        capacity = len*2 ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = val ;
    } 

template<class T>
Vec<T>::~Vec()
{ 
    delete[] ptr ; /***/
} 

    /***/
template<class T>
Vec<T>::Vec(const Vec<T>& right) 
    {
        delete[] ptr ; /***/
        ptr = new T[right.capacity] ;
        size = right.size ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = right[i] ;
    }

    /***/
template<class T>
Vec<T>& Vec<T>::operator =(const Vec<T>& right) 
    {
        if(this == &right) return *this ; /***/
        delete[] ptr ; /***/
        ptr = new T[right.capacity] ;
        size = right.size ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = right[i] ;
        return *this ; /***/
    }
