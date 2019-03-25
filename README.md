# CPlusPlus-Note

## Template
```Code is generate in compile time ```
```Can only be define within one file(unable to seperate into hpp and cpp)```
```Template specialization: ```
```1.Need to define a prototype for specialization```
```2.If specialized with type, the prototype should be template<class T>...```
```3.If specialized with value the prototype should be template<int val>...```
```4.Using both true and false specialization can avoid branch condition```


## Rules of Five
```1. Constructor: do not throw exception with in constructor```
```2. Distructor: using virtual distructor if it has child class```
```3. Copy constructor: Signature: Base(const Base& right) ```
```4. Copy assignment: Signature: Base& operator= (const Base& right){ return *this ;}  ```
```5. Move constructor: Signature: Base(Base&& right){this->~Base() ; this = right ;}```
```6. Move assignment Signature: Base& operator= (Base&& right){this->~Base() ; this = right ;}```

## Move semantic and r reference
``` 1. Lvalue has memory space to store assigned value while Rvalue doesn't ```
``` 2. Base on 1. , we cannot do "int& a = 10" but with r reference we can "int&& = 10" ```
``` 3. Parameters passed are generally rvalue, and by changing its function signature into r reference, the function can "steal value" from the passed value rather than copy it.```

## Delete vs Delete []

``` Delete free the one object while Delete first determine the size of the memory required to be freed and free such chunk of memory```

## Smart pointer
```1.unique_ptr points to array => unique_ptr<T[]>(new T[size]).```
```2.make_unique<T>(T val) not for allocate memory and assign to unique_ptr.```
```3.unique_ptr needs to use get() to access pointer.```
```4.Whenever doing assignment, the right side should always be rvalue since unique_ptr cannot be assigned with lvalue.```

## Event Driven
``` The execution order is determined by the incoming events triggered by clients, while the execution order of sequential program is predefiend by the programmer.```
``` In such programming paradigm, a publisher should 1.define the event handler and the function signature of it, 2. define event and its signature based on the event heandler, 3.Raise(call) all the event handlers when the OnXXXEvent() function is called. ```

## Multithreading

### multithreading basic(mutex, condition variable, semaphore)

```1.conditional variable need to use unique_lock as parameter```

```2.unique_lock can be unlock within its function scope while guard_lock cannot.```

### multithreading asynchronous

### multithreading transactional memory

## Low Lantency C++

``` 1.Avoid new/delete in hotpot code.```
```2.Using template specialization for flow control (specialize two function, and one for true and one for false)```
```3.Using google dense_hash_map to avoid potential cache miss```
```4.using __attribute((always_inline/noinline)) to force compiler inline/not inline the code```
```5.Using _builtin_prefetch_(data) to prefetch the data required later```
```6.Using attribute((hot/cold))```
```7.Pre-warm your cache```
```8.Using string_view for const string since std::string involve with new/delete```


