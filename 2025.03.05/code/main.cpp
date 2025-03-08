#include <iostream>
#include <memory>


// 2й поток
// // struct Foo {
// //     Foo() {
// //          std::cout << "Foo()\n"; 
// //     }
// //     ~Foo() {
// //         std::cout << "~Foo()\n";
// //     }
// // };

// // void internalFunc() {
// //     Foo f;
// //     throw std::string{"ITMO"};
// //     throw std::runtime_error("Some error");
// //     throw 2;
// // }


// // void internalFunc2() {
// //     std::unique_ptr<Foo> f{new Foo{}};
// //     internalFunc();
    
// // }


// // void externalFunc() {
// //     try {
// //         internalFunc2();
// //     }
// //     catch (const std::runtime_error e) {
// //         std::cout << "runtime_error " << e.what() << std::endl;
// //     }
// //     catch (const std::exception& e) {
// //         std::cout << "exception " << e.what() << std::endl;
// //     }
// //     catch(...) {
// //         std::cout << "Error!!!\n";
// //     }

// // }


// struct Foo {
//     int value;
//     bool something = true;

//     Foo(int v)
//         : value(v)
//     {}

//     Foo(const Foo& other)
//         : value(other.value)
//     {
//         if(rand() % 2)
//             throw std::runtime_error("KEKW");
//     }
// };


// class Boo {
// private:
//     std::unique_ptr<Foo> foo_;
//     int value_ = 0;
// public:
//     Boo(int value = 0)
//         : value_(value) 
//     {
//     }

//     Boo(int value, int foo_value)
//         : foo_(new Foo{foo_value})
//         , value_(value)
//     {}


//     Boo(const Boo& other)
//         : value_(other.value_)
//         , foo_(new Foo{*other.foo_}) 
//     {
//     }


//     Boo& operator=(const Boo& other) {

//         if(this == &other)
//             return *this;

//         value_ = other.value_;
        
//         if(other.foo_)
//             foo_ = std::make_unique<Foo>(other.foo_->value);

//         return *this;
//     }


//     friend std::ostream& operator<< (std::ostream & stream, const Boo& value);
// };


// std::ostream& operator<< (std::ostream & stream, const Boo& value) {
//     if(value.foo_)
//         stream << "Boo("  << value.value_ << ", Foo{" << value.foo_->value << "})"; 
//     else 
//         stream << "Boo("  << value.value_ << ", Foo{nullptr})"; 

//     return stream;
// }


// int main(int, char**){
//     srand(time(NULL));
//     Boo b{1,2};

//     std::cout << b << std::endl;
//     try{ 
//         Boo b2{1};
//         b = b2;

//     } catch(const std::runtime_error& e) {
//         std::cout << e.what() << std::endl;
//     }
    
//     std::cout << b << std::endl;

//     return 0;
// }

// 1й поток

// struct Foo {
//     Foo() {
//          std::cout << "Foo()\n"; 
//     }

//     ~Foo() {
//         std::cout << "~Foo()\n";
//     }
// };

// void internalFunc() {
//     Foo f;

//     throw std::string{"ITMO"};
//     throw 2;
//     throw std::runtime_error("Some error");
// }

// void externalFunc() {
//     std::unique_ptr<Foo> f {new Foo{}};
//     internalFunc();

// }

struct Foo {
    int value;
    bool something = true;


    Foo(int v)
        : value(v)
    {}
    
    Foo(const Foo& other)
        : value(other.value)
    {
        if(rand() % 2)
            throw std::runtime_error("KEKW");
    }
};



class Boo {
private:
    Foo* foo_ = nullptr;
    int value_ = 0;

public:
    Boo(int value = 0)
     : value_(value)
    {}

    Boo(int value, int foo_value)
        : foo_(new Foo{foo_value})
        , value_(value)
    {}

    ~Boo() {
         delete foo_; 
    }

    Boo(const Boo& other) 
        : value_(other.value_)
        , foo_(new Foo{other.foo_->value})
    {
    }


    Boo& operator=(const Boo& other) {
        if(this == &other)
            return *this;

        Boo tmp(other);
        swap(tmp);
        
        return *this;
    }

    void swap(Boo& other) noexcept {
        std::swap(value_, other.value_);
        std::swap(foo_, other.foo_);
    }

    friend std::ostream& operator<< (std::ostream & stream, const Boo& value);
};


std::ostream& operator<< (std::ostream & stream, const Boo& value) {
    if(value.foo_)
        stream << "Boo(" << value.value_ << ", Foo{" << value.foo_->value << "});";
    else
        stream << "Boo(" << value.value_ << ", Foo{nullptr});";

    return stream;
}



int main() {
    srand(time(nullptr));

    Boo b1{1,2};
    std::cout << b1 << std::endl;

    try {
        Boo b2{1, 2};
        b1 = b2;
    } 
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << b1 << std::endl;

    

    // try {
    //     externalFunc();
    // }
    // catch (const std::runtime_error& e) {
    //     std::cout << "runtime error " << e.what() << std::endl;
    // }
    // catch (const std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }
    // catch(int e) {
        
    //         std::cout << e << std::endl;
        
    // }
    // catch(...) {
    //     std::cout << "ERROR!!!AAA" << std::endl;
    // }
    return 0;
}
