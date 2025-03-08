#include <iostream>

#include <unordered_set>
#include <set>
#include <vector>

#include <list>
#include <forward_list>



// 1й поток 
struct  Foo
{
    
};

bool operator<(const Foo&, const Foo&) {
    return false;
}


struct FooComp {
    bool operator()(const Foo&, const Foo&) const {
        return false;
    }
};





template<size_t Size>
struct Memory {
    char* allocate(size_t bytes) {
        char* result  = data_ + current_;
        current_ += bytes;

        return result;
    }

    char data_[Size];
    size_t current_;
};



template<typename T>
class StackAllocator {
public:
    typedef size_t size_type ;
    typedef ptrdiff_t difference_type ;
    typedef T* pointer ;
    typedef const T* const_pointer ;
    typedef T& reference ;
    typedef const T& const_reference ;
    typedef T value_type ;


    template<typename U>
    struct rebind
    {
        using other = StackAllocator<U>;
    };



    StackAllocator() = default;
    

    template<typename U>
    StackAllocator(const StackAllocator<U>& other) 
    {}

    pointer allocate(size_type size) {
        std::cout << "Dealocate " << size << " currernt " << current_ <<  std::endl;
        if(current_ + size * sizeof(T) > 100 * sizeof(T) ) 
            return nullptr; // 
        
        pointer result = (pointer)(&data_[current_]);
        current_ += size*sizeof(T);

        return result;
        
    }


    void deallocate(pointer p, size_type n) {
        std::cout << "Dealocate " << p << " " << n << std::endl;
    }

private:
    std::array<T, 100> data_;
    size_t current_;
    
};


template<typename T, typename Container = std::vector<T>>
class MyStack {
    static_assert(std::is_same_v<T, typename Container::value_type>);
public:
    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        data_.pop_back();
    }

    bool empty() const {
        return data_.empty();
    }

    T& top() const {
        return data_.back();
    }

private:
    Container data_;

};




template<typename Container>
class MyBackInsertIterator {
public:
    MyBackInsertIterator(Container& container)
        : container_(&container)
    {}


    MyBackInsertIterator& operator++() {
        return *this;
    }


    MyBackInsertIterator operator++(int) {
        return *this;
    }

    MyBackInsertIterator& operator*() {
        return *this;
    }

    MyBackInsertIterator& operator=(Container::value_type& value) {
        container_->push_back(value);
        return *this;
    }

private:

    Container* container_;

};




struct tag_1 {};
struct tag_2 {};
struct tag_3 : public tag_2 {};



struct TypeA {};
struct TypeB {};
struct TypeC {};



template<typename T>
struct my_traits {
    typedef tag_1 tag;
};


template<>
struct my_traits<TypeB> {
    typedef tag_2 tag;
};

template<>
struct my_traits<TypeC> {
    typedef tag_3 tag;
};


template<typename T>
void func_dispatch(const T& value, const tag_1&) {
    std::cout << "tag1\n" ;
}


template<typename T>
void func_dispatch(const T& value, const tag_2&) {
    std::cout << "tag2\n" ;
}



template<typename T>
void evaluate(const T& value) {
    func_dispatch(value, typename my_traits<T>::tag());
}


int main() {

    evaluate(TypeA{});
    evaluate(TypeB{});
    evaluate(TypeC{});
    evaluate(Foo{});
    evaluate(1);

    return 0;

    std::array<int, 5> arr = {1,2,3,4,5};

    std::vector<int> v;
    std::copy(arr.begin(), arr.end(), MyBackInsertIterator(v));
    


    for(int i : v)
        std::cout << i << " ";

    std::cout << std::endl;


    return 0;

    MyStack<int> st;

    st.push(1);

    

    // StackAllocator<int> al();
    // StackAllocator<int>::rebind<bool>::other alb{al};



    // std::list<int, StackAllocator<int>> l {};

    
    // std::vector<Foo, StackAllocator<Foo>> v;

    // for(int i = 0; i < 64; ++i)
    //     l.push_back(i);

    

    return 0;
}



// 2й поток
// struct Foo {
    
// };

// bool operator<(const Foo&, const Foo&) {
//     return false; 
// }


// struct FooComp {
//     bool operator()(const Foo&, const Foo&) const {
//         return false; 
//     }
// };


// template<typename T, size_t N>
// struct StackAllocator {
//     typedef size_t size_type ;
//     typedef ptrdiff_t difference_type ;
//     typedef T* pointer ;
//     typedef const T* const_pointer ;
//     typedef T& reference ;
//     typedef const T& const_reference ;
//     typedef T value_type ;


//     template<typename U>
//     struct rebind
//     {
//         using other = StackAllocator<U, N>;
//     };
    
//     StackAllocator() = default;

//     template<typename U, size_t M>
//     StackAllocator(const StackAllocator<U, M>& other) {}

//     pointer allocate(size_type size) {
        
//         pointer result = pointer(data_ + current_);

//         std::cout << "Allocate size = " << size << " pointer = " << result << std::endl;

//         current_ += size * sizeof(T);
//         return result;
//     }
//     void deallocate(pointer p, size_type n) {
//         std::cout << "Deallocate size = " << n << " pointer = " << p << std::endl;
//     }
// private:
//     char data_[N*sizeof(T)];
//     size_t current_ = 0;
// };




// template<typename T, typename Container = std::vector<T>>
// class MyStack {
// public:
//     void push(const  T& value) {
//         data_.push_back(value);
//     }

//     void pop() {
//         data_.pop_back();
//     }   


//     bool empty() const {
//         return data_.empty();
//     }


//     T& top() const {
//         return data_.back();
//     }

// private:
//     Container data_;
// };



// template<typename Container>
// class BackInsertIterator {
// public:

//     BackInsertIterator(Container& container) 
//         : container_(&container)
//     {
//     }

//     BackInsertIterator& operator++() {
//         return *this;
//     }


//     BackInsertIterator operator++(int) {
//         return *this;
//     }


//     BackInsertIterator& operator*() {
//         return *this;
//     }


//     BackInsertIterator& operator=(const Container::value_type& value) {
//         container_->push_back(value);

//         return *this;
//     }



// private:
//     Container* container_;
// };


// struct tag_1 {};
// struct tag_2 {};
// struct tag_3 : public tag_2 {};



// struct TypeA {};
// struct TypeB {};
// struct TypeC {};


// template<typename T>
// struct my_traits {
//     typedef tag_1 tag;
// };

// template<>
// struct my_traits<TypeB> {
//     typedef tag_2 tag;
// };

// template<>
// struct my_traits<TypeC> {
//     typedef tag_3 tag;
// };


// template<typename T>
// void func_dispatch(const T& value, const tag_1&) {
//     std::cout << "tag1\n" ; 
// }


// template<typename T>
// void func_dispatch(const T& value, const tag_2&) {
//     std::cout << "tag2\n" ;
// }



// template<typename T>
// void evaluate(const T& value) {
//     func_dispatch(value, typename my_traits<T>::tag());
// }







// int main(int, char**){


//     evaluate(TypeA{});
//     evaluate(TypeB{});
//     evaluate(TypeC{});
//     evaluate(Foo{});

//     return 0;
    
//     std::array<int, 5> arr= {1,2,3,4,5};

//     std::vector<int> v;
//     //std::copy(arr.begin(), arr.end(), std::back_inserter(v));

//     std::copy(arr.begin(), arr.end(), BackInsertIterator(v));

    

//     for(int i : v)
//         std::cout << i << " ";

//     std::cout << std::endl;
    

//     return 0;
// //     MyStack<int> st;

// //     st.push(1);

// //     //std::array<Foo, 10> ar;
// //     StackAllocator<int, 100> al;

// //     StackAllocator<int, 100>::rebind<bool>::other alb{al};
    

// //     std::list<int, StackAllocator<int, 100>> v {};

// //     for(int i = 0; i < 63; ++i)
// //         v.push_back(i);

// //     for(int i : v)
// //         std::cout << i << " ";

// //     std::cout << std::endl;
// }
