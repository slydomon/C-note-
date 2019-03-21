#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vec
{
public:
    Vec(){ ptr = new T[20]; }
    Vec(size_t len){ ptr = new T[size*2] ; size = len ;}
    Vec(size_t len, const T& val)
    {
        ptr = new T[size*2] ;
        size = len ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = val ;
    } 
    ~Vec(){ delete ptr ;} ;
    Vec(const Vec& right)
    {
        delete ptr ;
        ptr = new T[right.capacity] ;
        size = right.size ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = right[i] ;
    }
    &Vec operator= (const Vec& right)
    {
        delete ptr ;
        ptr = new T[right.capacity] ;
        size = right.size ;
        for(int i = 0 ; i < size ; ++i) ptr[i] = right[i] ;
        return this ;
    }
    inline size_t size() const { return size ;} 
    inline size_t capacity() const {return capacity ;}
    inline bool empty() const { return size == 0;} ;
    inline void push_back(const T& val)
    {
        if(capacity > size+1)
        {
            T* tmp = new T[capacity*2] ;
            for(int i = 0 ; i < size ; ++i) tmp[i] = ptr[i] ;
            delete ptr ;
            ptr = tmp ;
        }
        ptr[size+1] = val ;
        ++size ;
    }
    inline bool pop_back()
    {
        if(size == 0)
        {
            cout << "no element" << endl ;
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
            cout << "invalid access element" << endl ;
        else
            return ptr[idx] ;
    }
    inline T* begin() const {return ptr ;} 
    inline T* end() const {return ptr[size+1]} ;
private:
    T* ptr ;
    size_t size = 0 ;
    size_t capacity = 0 ;
} ;

#endif 