#include <iostream>


//1й поток 


// int twice(int value) {
//     return 2 * value;
// }

// int triple(int value) {
//     return 3 * value;
// }



class CMulty {
public:
    explicit CMulty(int multy)
        : multy_(multy)
    {}

    int operator()(int value) const {
        return multy_ * value;
    }

private:
    int multy_;
};




class Foo {
public:
    Foo(int good, int morning)
        : good_(good)
        , morning_(morning)
    {}

    int good() const {
        return good_;
    }

    int morning() const {
        return morning_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Foo& value);

private:
    int good_;
    int morning_;
};

std::ostream& operator<<(std::ostream& out, const Foo& value) {
    out << value.good_ << " " << value.morning_;

    return out;
}


class FooPtr {
public:
    FooPtr(int good, int morning)
        : foo_(new Foo{good, morning})
    {}

    FooPtr(const FooPtr&) = delete;

    FooPtr& operator=(const FooPtr&) = delete;

    ~FooPtr() {
        delete foo_;
    }

    Foo* operator->()  {
        return foo_;
    }

    Foo& operator*() {
        return *foo_;
    }

private:
    Foo* foo_;
};

void func() {
    //Foo* ptr = new Foo{1,2};
    FooPtr ptr{1,2};

    if(rand() % 2 == 0) {
        //delete ptr;
        return;
    }

    if(rand() % 3 == 0) {
        // delete ptr;
        return;
    }   

    //delete ptr;

}

int main() {

    for(uint64_t i = 0; i < 10 * 1000 * 1000 * 1000LL; ++i) {
        func();
    }
    

    return 0;

    CMulty twice{2};
    CMulty triple{3};

    std::cout << "     " << twice(2) << std::endl;

    return 0;
}


















// 2й поток
// class CMulty {
// public:
//     explicit CMulty(int multy)
//         : multy_(multy)
//     {}

//     int operator()(int value) const {
//         return multy_ * value;
//     }

// private:
//     int multy_;
// };



// class Foo {
// public:
//     Foo(int good, int morning)
//         : good_(good)
//         , morning_(morning)
//     {}

//     friend std::ostream& operator<<(std::ostream& out, const Foo& value);

//     int good() const {
//         return good_;
//     }


//     int morning() const {
//         return morning_;
//     }
// private:
//     int good_;
//     int morning_;
// };

// std::ostream& operator<<(std::ostream& out, const Foo& value) {
//     out << value.good_ << " " << value.morning_;

//     return out;
// }



// class FooPtr {
// public:
//     explicit FooPtr(int good, int morning)
//         : ptr_(new Foo{good, morning})
//     {}

//     FooPtr(const FooPtr&) = delete;

//     FooPtr& operator=(const FooPtr&) = delete;

//     ~FooPtr() {
//         delete ptr_;
//     }


//     Foo* operator->() {
//         return ptr_;
//     }


//     Foo& operator*() {
//         return *ptr_;
//     }

// private:
//     Foo* ptr_;
// };

// void func() {
//     FooPtr pfoo{1,2};
//     //Foo* pfoo = new Foo{1,2};

//     pfoo->good();

//     *pfoo;

//     if(rand() % 2 == 0) {
//        // delete pfoo;
//         return;
//     }


//     if(rand() % 3 == 0) {
//         //elete pfoo;
//         return;
//     }

//    //delete pfoo;
// }

// int main(int, char**){

//     std::cout << sizeof(Foo) << std::endl;


//     //for(uint64_t i = 0; i < 10 * 1000 * 1000 * 1000LL; ++i)
//         func();
//     //std::cout << foo << std::endl;
//     // CMulty twice{2};
//     // CMulty triple{3};

//     // std::cout << twice(2) << std::endl;

    
// }
