#include <iostream>


// //1й поток

// template<typename T>
// struct Boo {
//     void foo() {
//         std::cout << "foo()\n";
//     }

//     void func() {};
// };


// template<>
// struct Boo<int> {
//     void foo() {
//         std::cout << "boo()\n";
//     }
// };


// template<typename T>
// struct is_float {
//     static bool value() {
//         return false;
//     }
// };


// template<>
// struct is_float<float> {
//     static bool value() {
//         return true;
//     }
// };


// template<typename T>
// static bool is_float_v = is_float<T>::value();



// template<typename T>
// void swap(T& a, T& b) {

//     std::cout << "swap(T& a, T& b)\n";
//     T tmp = a;
//     a = b;
//     b = tmp;
// }


// struct Ququ {
//     Ququ() = default;
//     Ququ(const Ququ& other) = delete;

//     void swap(Ququ& other) {

//     }
// };

// template<>
// void swap(Ququ& a, Ququ& b) {
//     a.swap(b);
// } 



// void swap(Ququ& a, Ququ& b) {
//     a.swap(b);
// } 


// template<typename T>
// void swap(std::vector<T>& a, std::vector<T>& b) {

//     std::cout << "swap(std::vector<T>& a, std::vector<T>& b)\n";
//     a.swap(b);
// }


// void swap(std::vector<int>& a, std::vector<int>& b) {

//     std::cout << "std::vector<int>& a, std::vector<int>& b\n";
//     a.swap(b);
// }






// template<typename U>
// struct SomeStruct {
//     U func(int x) {
//         return funcImpl<U>(x);
//     }

// private:
//     template<typename T>
//     T funcImpl(int x) {
//         return (U)x;
//     }


//     template<>
//     std::string funcImpl<std::string>(int x) {
//          return std::to_string(x);
//     }

// };


// template<typename T, typename U>
// struct BooExt {
//     void foo() {
//         std::cout << "A\n";
//     }
// };



// template<typename U>
// struct BooExt<int, U> {
//     void foo() {
//         std::cout << "B\n";
//     }
// };


// template<typename U>
// struct BooExt<U, int> {
//     void foo() {
//         std::cout << "C\n";
//     }
// };


// // template<>
// // struct BooExt<float, float> {
// //     static_assert(false);
    
// // };




// template<typename T>
// void func(const T& value) {
//     std::cout << "const template\n";
// }

// template<typename T>
// void func(T& value) {
//     std::cout << "template\n";
// }


// void func(double value) {
//     std::cout << "double\n";
// }



// struct LastLection {

// };




// template<typename T>
// class AutoPtr{
// public:
//     AutoPtr(T* ptr)
//         : ptr_(ptr)
//     {}


//     ~AutoPtr() {
//         delete ptr_;
//     }

//     AutoPtr(AutoPtr& other) 
//         : ptr_(other.ptr_)
//     {
//         other.ptr_ = nullptr;
//     }

//     AutoPtr& operator=(AutoPtr& other) 
//     {

//         if(this == &other)
//             return;

//         delete ptr_;
//         ptr_ = other.ptr_;
//         other.ptr_ = nullptr;

//         return *this;
//     }


// private:
//     T* ptr_;
// };


// void func() {
//     AutoPtr<LastLection> ll {new LastLection{}};
//     AutoPtr<LastLection> ll2 = ll;

//     return ;
// }


// int main() {

//     std::fst=ream
//     func();

//     return 0;

//     std::vector<int> v1(100500, 0);
//     std::vector<int> v2(100600, 1);

    
//     swap(v1, v2);


//     // int i;
//     // func(1);

//     // // BooExt<float, long>{}.foo();
//     // // BooExt<int, long>{}.foo();
//     // // BooExt<float, int>{}.foo();
//     // // BooExt<int, int>{}.foo();


//     return 0;
//     SomeStruct<float> s;
    
//     s.func(1);


//     SomeStruct<std::string> s2;
//     s.func(1);




//     return 0;

//     int i1;
//     int i2;

//     swap(i1, i2);


//     Ququ q1;
//     Ququ q2;

//     swap(q1, q2);



//     return 0;

//     std::cout << is_float_v<int> << std::endl;
//     std::cout << is_float_v<float> << std::endl;

//     return 0;
//     Boo<int> b1;
//     b1.foo();


//     Boo<bool> b2;
//     b2.func();


//     Boo<long> b3;
//     b3.func();



//     return 0;
// }

















2й поток
struct Foo {
    enum {
        value = 100500
    };
};



template<size_t N>
struct Factorial {
    enum {
        value = N * Factorial<N-1>::value
    };
};


template<>
struct Factorial<0> {
    enum {
        value = 1
    };
};
/*

// N  = 5
struct Factorial {
    enum {
        value = 5 * Factorial<4>::value // 5 * 4 * 3 * 2 * 1 * 1 = 120
    };
};

// N = 4
struct Factorial {
    enum {
        value = 4 * Factorial<3>::value
    };
};


*/


// template<typename T>
// struct Boo {
//     void foo() {
//         std::cout << "foo()\n";
//     }

//     void func() {
//         std::cout << "func()\n";
//     }
// };


// template<>
// struct Boo<int> {
//     void foo() {
//         std::cout << "boo()\n";
//     }
// };



template<typename T>
struct is_float {
    static bool value() { return false; }
};


template<>
struct is_float<float> {
    static bool value() { return true; }
};

template<typename T>
static bool is_float_v = is_float<T>::value();




struct Ququ {
    Ququ() = default;
    Ququ(const Ququ& other) = delete;

    void swap(Ququ& other) {
        // 
    }
};

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}



// template<>
// void swap<Ququ>(Ququ& a, Ququ& b) {
//     a.swap(b);
// }


template<typename T>
void swap(std::vector<T>& a, std::vector<T>& b) {
    a.swap(b);
}


void swap(Ququ& a, Ququ& b) {
    a.swap(b);
}


template<class T, class U>
struct Boo {
    void foo() { std::cout << "A" << std::endl; }
    void func () {};
};

template<class U>
struct Boo<int, U> {
    void foo() { std::cout << "B" << std::endl; }
};


template<>
struct Boo<int, int>  {
    void foo() { std::cout << "C" << std::endl; }
};



struct LastLection {

};


template<typename T>
class AutoPtr final
{
public:
    AutoPtr(T* ptr)
        : ptr_(ptr)
        {}

    ~AutoPtr() {
        
        
        delete ptr_;
    }

    AutoPtr(AutoPtr& other)
        : ptr_(other.ptr_) 
    {
        other.ptr_ = nullptr;
    }
    AutoPtr& operator=(AutoPtr& other) {
        if(this == &other)
            return; 


        delete ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    T& operator*() {
        return *ptr_;
    }

    T* operator->() {
        return ptr_;
    }

private:
    T* ptr_;
};


void func() {
    AutoPtr<LastLection> ll{new LastLection{}};
    AutoPtr<LastLection> ll2{ll};
    
    return ;
}

int main(int, char**){

    func();
    return 0;
    Boo<float, long> b1;
    b1.func(); // A

    Boo<int, long> b2;
    b2.foo(); // B

    Boo<int, int> b3;
    b3.foo(); // C


    Boo<float, int> b4;
    b4.foo(); // A



    return 0;

    Ququ q1;
    Ququ q2;

    swap(q1, q2);


    int i1;
    int i2;

    swap(i1, i2);


    std::vector<int> v1{100600, 0};
    std::vector<int> v2{100650, 1};

    swap(v1, v2);

    v1.swap(v2);


    return 0;
    std::cout << is_float_v<int> << std::endl;
    std::cout << is_float_v<float> << std::endl;

    return 0;
    // Boo<int> b ;
    // b.foo();   // boo


    // Boo<float> b2 ;
    // b2.func();


    // Boo<bool> b3 ;
    // b3.func();

}
