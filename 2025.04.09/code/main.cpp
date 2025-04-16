#include <iostream>


template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

struct Foo {

    Foo() = default;
    Foo(const Foo&) = default;


    Foo& operator=(Foo other) {
        swap(other);

        return *this;
    }

    // Foo& operator=(const Foo& other) {
    //     if(this == &other)
    //         return *this;

    //     Foo tmp = other;
    //     swap(tmp);

    //     return *this;
    // }

    void swap(Foo& other) noexcept {
        //.....
    }


    // Foo& operator=(Foo&& other) {
    //     swap(other);
    //     return *this;
    // }
};



void foo(Foo& ) {
    std::cout << "void foo(Foo& )\n";
}

void foo(const Foo& ) {
    std::cout << "void foo(const Foo& )\n";
}

void foo(Foo&& ) {
    std::cout << "void foo(Foo&& )\n";
}


template<typename T>
void function(T  && value) {

}

void function(Foo& value) {

}

void function(Foo&&  value) {

}


template<typename T>
void foo(T&& value) {
}

// template< typename T >
// T&& forward(std::remove_reference_t<Foo&&>& t ) noexcept {
//     return static_cast<T&&>( t );
// }


// template <typename T>
// std::remove_reference_t<T>&& move(T&& t) _NOEXCEPT {
//   typedef std::remove_reference_t<_Tp> _Up;
//   return static_cast<_Up&&>(__t);
// }

struct Boo {
};


// void boo(Boo&) {
//     std::cout << "void boo(Boo&)" << std::endl;
// }

void boo(const Boo&) {
    std::cout << "void boo(const Boo&)" << std::endl;
}

// void boo(Boo&&) {
//     std::cout << "void boo(Boo&&)" << std::endl;
// }

void boo(const Boo&&) {
    std::cout << "void boo(const Boo&&)" << std::endl;
}

template<typename T>
void boo(T&&) {
    std::cout << "template boo(T&&)" << std::endl;
}

struct Foo2 {
    Foo2() {
        std::cout << "Foo()\n";
    }
    Foo2(const Foo2&) {
        std::cout << "Foo(const Foo&)\n";
    }
    Foo2(Foo2&&) {
        std::cout << "Foo(Foo&&)\n";
    }
};

Foo2 rvo() {
    return Foo2();
}

Foo2 nrvo() {
    Foo2 result;

    return result;
}

Foo2 createFoo(int i) {
    Foo2 odd;
    Foo2 even;

    return i % 2 == 0 ? odd : even;
}

int main() {

    Foo2 f2 = createFoo(2);

    return 0;
    Boo b;

    boo(b);
    boo(std::move(b));
    boo(Boo{});

    return 0;

    // using intlv = int&;
    // using intrv = int&&;
    // int i = 1;
    // intlv lv = i;
    // intrv rv = 1;

    // int& & llv = lv;
    // int& && rlv = lv;
    // int&& & lrv = rv;
    // int&& && rrv = 1;


    Foo f;
    foo(f);     // T = Foo&
    foo(Foo{}); // T = Foo&&

    //f = Foo{};
    // Foo f;
    // const Foo cf;
    // Foo&& rvf = Foo{};



    // foo(f);  //  Foo&
    // foo(cf); // const Foo&
    // foo(Foo{}); // Foo&&

    // foo(rvf); // Foo&
}

// 2й поток
// struct Foo{


//     Foo(Foo&&) {
//         std::cout << "Foo(Foo&&)\n";
//     }


//     Foo() {
//         std::cout << "Foo()\n";
//     }

//     Foo(const Foo&) {
//         std::cout << "Foo(const Foo&)\n";
//     }

//     Foo& operator=(Foo other) {
//         swap(other);
//         return *this;
//     }


//     void swap(Foo& tmp) noexcept {
//         // ....
//     }

// };

// void foo(Foo& ) {
//     std::cout << "void foo(Foo& )\n";
// }

// // void foo(const Foo& ) {
// //     std::cout << "void foo(const Foo& )\n";
// // }

// // void foo(Foo&& ) {
// //     std::cout << "void foo(Foo&& )\n";
// // }


// template<typename T>
// void swap(T& a, T& b) {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }


// template<typename T>
// void function(T& value) {

// }


// struct Boo {

// };


// // void boo(Boo&) {
// //     std::cout << "Boo&\n";
// // }

// // void boo(const Boo&) {
// //     std::cout << "const Boo&\n";
// // }

// // void boo(Boo&&) {
// //     std::cout << "Boo&&\n";
// // }

// void boo(const Boo&&) {
//     std::cout << "const Boo&&\n";
// }

// template<typename T>
// void boo(T&&) {
//     std::cout << "template\n";
// }



// Foo rvo() {
//     return Foo();
// }

// Foo nrvo() {
//     Foo result;
//     return result;
// }

// Foo createFoo(int i) {
//     Foo odd;
//     Foo even;


//     return i % 2 == 0 ? odd : even;
// }

// template <class T>
// typename std::remove_reference<T>::type&&
// move(T&& t) noexcept {
//     typedef typename remove_reference<_Tp>::type U;
//     return static_cast<U&&>(t);
// }

// template< typename T >
// T&& forward(std::remove_reference_t<T>& t ) noexcept {
//     return static_cast<T&&>( t );
// }


// int main(int, char**){


//     Foo f = createFoo(2);


//     std::exchange



//     // Boo b;
//     // boo(b);
//     // boo(Boo{});
//     // // Foo f;

//     // function(f);
//     // function(Foo{});

//     //Foo f;
//     //Foo f2;


//     //f = Foo{};
//     // const Foo cf;
//     // Foo&& rvf = Foo{};




//     //std::cout << &Foo{};

//     //foo(f);
//     //foo(cf);
//     //foo(Foo{});
//     //foo(rvf); // !!!
// }
