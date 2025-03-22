#include <iostream>
#include <stdlib.h>


//1й поток

struct Boo {
    int operator()(int i) const {
        return i + 1;
    }
};


struct Foo {
    std::string operator()(const std::string& str) const {
        return str + str;
    }
};



template<typename T, typename U>
struct SimpleOverloader : public T, U {
    SimpleOverloader(T t, U u)
     : T(t), U(u)
    {}


    using T::operator();
    using U::operator();
};


template<typename T, typename U>
SimpleOverloader<T,U> MakeOverload(T t, U u) {
    return SimpleOverloader<T, U>(t, u);
}



struct SomeObj {
    std::string str_;

    SomeObj() {
        std::cout << "SomeObj()\n";
    }

    SomeObj(const std::string& str) 
        : str_(str)
    {
        std::cout << "SomeObj(const std::string& str)\n";
    }

    SomeObj(int i) 
        : str_(std::to_string(i))
    {
        std::cout << "SomeObj(int i)\n";
    }

    SomeObj(const SomeObj& other) {
        std::cout << "SomeObj(connt SomeObj& othre)" << std::endl;
    }

    SomeObj& operator=(const SomeObj& other) {
        std::cout << " operator=(const SomeObj& other)" << std::endl;

        return *this;
    }
};


std::string createA() {
    return "aaa";
}


int createB() {
    return 2;
}


int main() {

    bool condition = time(nullptr) % 2;
    SomeObj o = condition ? createA() : createB();

    SomeObj o = [condition]() -> SomeObj {
        if(condition)
            return createA();
        else   
            return createB();
    }();

    std::cout << o.str_;

    // //SimpleOverloader<Boo, Foo> obj(Boo{}, Foo{});
    // auto obj = MakeOverload(
    //     [](int i) { return i + i;},
    //     [](const std::string& str) { return str+ str;}
    // );

    // std::cout << obj(1)  << std::endl;
    // std::cout << obj("aaaaa")  << std::endl;
}





// struct Foo {
//     int field = 0;

//     int func(int i) {
//         auto f = [this](int value) {
//             this->field = 10;
//             return field + value;
//         };

//         return f(i);    
//     }
// };


// int main() {
//     Foo f;

//     std::cout << f.func(1) << std::endl;

//     return 0;
//     // int x = 1;
//     // int y = 2;


//     // std::cout << std::format("{} {}\n", x, y);
//     // auto f = [x, &y](int v) mutable {
//     //     std::cout << std::format("Lambda {} {}\n", x, y);
//     //     x += 1;
//     //     return v + x + y;
//     // };
    
//     // f(1);
//     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
//     // x = 10;
//     // f(1);
//     // f(1);
//     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
//     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
    






// }


// 2й поток
// struct Boo {
//     int operator()(int i) const {
//         return i + 1;
//     }
// };


// struct Boo2 {
//     int operator()(int i) const {
//         return i + 1;
//     }
// };

// struct Foo {
//     std::string operator()(const std::string& str) const {
//         return str + str;
//     }
// };



// template<typename T, typename U>
// struct SimpleOverloader : public T, U {
//     SimpleOverloader(T t, U u) : T(t), U(u)
//     {}

//     using T::operator();
//     using U::operator();
// };



// template<typename T, typename U>
// SimpleOverloader<T,U> MakeOverloaded(const T& t, const U& u) {
//     return SimpleOverloader<T, U>(t, u);
// }


// int int_comp(const void* a, const void* b) {
//     return *(const int*)a - *(const int*)b;
// }










// int main()
// { 


//     int arr[] = {5,4,3,2,1};


//     qsort(arr, 5, sizeof(int), int_comp);

//     qsort(
//         arr, 5, sizeof(int), 
//         [](const void* a, const void* b){
//             return *(const int*)a - *(const int*)b; 
//         }
//     );


//     for(int i : arr)
//         std::cout << i << " ";


//     std::cout << std::endl;
//     return 0;

//     //SimpleOverloader<Boo, Foo> tmp(Boo{}, Foo{});
//     auto tmp = MakeOverloaded(
//             [](int i){return i + 1;},
//             [](const std::string& str) { return str + str;}
//     );


//     std::cout << tmp("aaaaa") << std::endl;
//     std::cout << tmp(1) << std::endl;
    
// }
















