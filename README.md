# CPlusPlus-Note

## Class
```1. Private static member can only be initialize outside the class scope with "classnmae::data_member = xxx"```
```2. Using initialize list to initialize data member that "must have default value." ```
```3. Using virtual destructor whenever using inhertance. Reason: if we have virtual distructor the class will dynamically call the right destructor when it comes to polymorphism```

## Template
```Code is generate in compile time ```

```Can only be define within one file(unable to seperate into hpp and cpp)```

### Template specialization:

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

### Unique pointer
```1.unique_ptr points to array => unique_ptr<T[]>(new T[size]).```

```2.make_unique<T>(T val) not for allocate memory and assign to unique_ptr.```

```3.unique_ptr needs to use get() to access pointer.```

```4.Whenever doing assignment, the right side should always be rvalue since unique_ptr cannot be assigned with lvalue.```

```5.unique_ptr own the object it points whereas raw points don't. Thus, when using std container with raw pointer it is the programmer's responsibility to free the object rather than the container's(or destructor of the container's) responsibility to do so. On the other hand, when using unique_ptr, std container will recursively call the destructor of the object it owns, in this case, the unique_ptr. Since unique_ptr has the ownership of the object it points, it will destructs the object when its destructor is called by std containers```

```6.Good usage for std containers with unique_ptr: When the object in std container is larger and programmer apply std algorithm such as sort to the containers, it is time-consuming to move the objects around. In this case, using unique_ptr saves time from moving large objects around since size of unique_ptr is relatively small. ```

### Share pointer
```1.The reference count begins counting after the manage obj initialize. Thus, if the object is referenced severeal times before the share pointer initialize, the share pointer will not notice those references.```
```2.Get() does not increment the reference count. Thus, if we call get() and assign the return pointer to another pointer, the manager object will not notice and increment the reference count.```

## Event Driven
``` The execution order is determined by the incoming events triggered by clients, while the execution order of sequential program is predefiend by the programmer.```

``` In such programming paradigm, a publisher should 1.define the event handler and the function signature of it, 2. define event and its signature based on the event heandler, 3.Raise(call) all the event handlers when the OnXXXEvent() function is called. ```

## Multithreading

### multithreading basic(mutex, condition variable, semaphore)

```1.conditional variable need to use unique_lock as parameter```

```2.unique_lock can be unlock within its function scope while guard_lock cannot.```

### multithreading asynchronous
```1.Future waits its job to be finished before it distructs and thus it blocks the thread of its scope. When using future in function, makes sure the future does not call its disturctor within the function call or the thread calling the function will be blocked.```

### multithreading transactional memory

## Low Lantency C++

```1.Avoid new/delete in hotpot code.```
```2.Using template specialization for control flow (specialize two function, and one for true and one for false)```
```3.Using google dense_hash_map to avoid potential cache miss```
```4.using __attribute((always_inline/noinline)) to force compiler inline/not inline the code```
```5.Using _builtin_prefetch_(data) to prefetch the data required later```
```6.Using attribute((hot/cold))```
```7.Pre-warm your cache```
```8.Using string_view for const string since std::string involve with new/delete```


