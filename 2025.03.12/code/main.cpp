#include <iostream>
#include <stdlib.h>
#include <assert.h>

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


int incr(int i) {
    return i + 1;
}

struct Incr
{
    int operator()(int i) const {
        return i + 1;
    }
};


template<typename T>
class NaiveFunction ;


template<typename R, typename Arg>
class NaiveFunction<R(Arg)> {

    struct ICallable {
        virtual R invoke(Arg) = 0;
        virtual ~ICallable() = default;
    };


    template<typename TFunc>
    struct Callable : public ICallable {
        Callable(TFunc func)
            : func_(func)
        {}

        R invoke(Arg arg) override {
            return func_(arg);
        }


        TFunc func_;
    };
    

public:

    template<typename TFunc>
    NaiveFunction(TFunc func)
        : func(new Callable<TFunc>(func))
    {}

    R operator()(Arg arg) {
        assert(func != nullptr);
        return func->invoke(arg);
    }

private:
    std::unique_ptr<ICallable> func;
};


int main() {

    
    NaiveFunction<int(int)> f = incr;
    NaiveFunction<int(int)> f2 = Incr{};
    NaiveFunction<int(int)> f3 = [](int i){return i + 1;};


    std::cout << f(1) << std::endl;
    std::cout << f2(1) << std::endl;
    std::cout << f3(1) << std::endl;



    return 0;
    //SimpleOverloader<Boo, Foo> obj(Boo{}, Foo{});
    auto obj = MakeOverload(
        [](int i) { return i + i;},
        [](const std::string& str) { return str+ str;}
    );

    std::cout << obj(1)  << std::endl;
    std::cout << obj("aaaaa")  << std::endl;
}





// // struct Foo {
// //     int field = 0;

// //     int func(int i) {
// //         auto f = [this](int value) {
// //             this->field = 10;
// //             return field + value;
// //         };

// //         return f(i);    
// //     }
// // };


// // int main() {
// //     Foo f;

// //     std::cout << f.func(1) << std::endl;

// //     return 0;
// //     // int x = 1;
// //     // int y = 2;


// //     // std::cout << std::format("{} {}\n", x, y);
// //     // auto f = [x, &y](int v) mutable {
// //     //     std::cout << std::format("Lambda {} {}\n", x, y);
// //     //     x += 1;
// //     //     return v + x + y;
// //     // };
    
// //     // f(1);
// //     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
// //     // x = 10;
// //     // f(1);
// //     // f(1);
// //     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
// //     // //std::cout << std::format("{} {} {}\n", x, y, f(10));
    






// // }


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









// int incr(int i) {
//     return i + 1;
// } 


// struct Incr
// {
//     int operator()(int i) const {
//         return i + 1;
//     }
// };


// template<typename T>
// class MyFunction;


// template<typename R, typename Arg>
// class MyFunction<R(Arg)> {
    
//     struct ICallable  {
//         virtual R invoke(Arg arg) = 0;
//         virtual ~ICallable() = default;
//     };
    

//     template<typename TFunc>
//     struct Callable : public ICallable {
//         Callable(TFunc func)
//             : f(func)
//         {}

//         R invoke(Arg arg) override {
//             return f(arg);
//         }

//         TFunc f;
//     };

// public:
//     MyFunction() = default;

  

//     template<typename TFunc>
//     MyFunction(TFunc func)
//         : callable_(new Callable<TFunc>(func))
//     {}

//     R operator()(Arg arg) {
//         assert(callable_ != nullptr);
//         return callable_->invoke(arg);
//     }
// private:
//     std::unique_ptr<ICallable> callable_;
// };



// int main()
// { 

//     // int(*f)(int);
//     // using TFunc = int(int);
//     // TFunc* f;

//     // f = incr;

//     // std::cout << f(1);

    

//     MyFunction<int(int)> f = incr;
//     MyFunction<int(int)> f2 = [](int i) { return i + 1;};
//     MyFunction<int(int)> f3 = Incr{};

//     std::cout << f(1);
//     std::cout << f2(1);
//     std::cout << f3(1);




//     // int arr[] = {5,4,3,2,1};


//     // qsort(arr, 5, sizeof(int), int_comp);

//     // qsort(
//     //     arr, 5, sizeof(int), 
//     //     [](const void* a, const void* b){
//     //         return *(const int*)a - *(const int*)b; 
//     //     }
//     // );


//     // for(int i : arr)
//     //     std::cout << i << " ";


//     // std::cout << std::endl;
//     // return 0;

//     // //SimpleOverloader<Boo, Foo> tmp(Boo{}, Foo{});
//     // auto tmp = MakeOverloaded(
//     //         [](int i){return i + 1;},
//     //         [](const std::string& str) { return str + str;}
//     // );


//     // std::cout << tmp("aaaaa") << std::endl;
//     // std::cout << tmp(1) << std::endl;
    
// }
















