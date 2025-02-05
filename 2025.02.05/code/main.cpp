#include <iostream>
#include <memory>
#include <stdio.h>





// 1й поток


struct Foo {
    void foo() {
        std::cout << "foo()\n";
    }
};




template<typename T, typename Deleter>
class AutoPtr  {
public:
    AutoPtr(T* ptr) 
        : ptr_(ptr)  //int* p = new int{5};
    {
        
    }

    ~AutoPtr() {
        Deleter deleter;
        deleter(ptr_);
    }


    AutoPtr(AutoPtr& other) = delete;
    // {
    //     ptr_ = other.ptr_;
    //     other.ptr_ = nullptr;
    // }


    AutoPtr&  operator=(AutoPtr& other)  = delete ;
    // {
    //     if(&other == this)
    //         return *this; 
    
    //     ptr_ = other.ptr_;
    //     other.ptr_ = nullptr;

    //     return *this;
    // }
 

    T& operator*() const {
        return *ptr_;
    }


    T* operator->() const  {
        return ptr_;
    }



private:
    T* ptr_;
};

void func() {

    FILE* f = fopen("in.txt", "r");
    fclose(f);

   



    // int* p = new int{5}; // AutoPtr
    // AutoPtr ap {5};

    
    // std::cout << *p << std::endl;
    // std::cout << *ap << std::endl;

    // *p = 10;
    // *ap = 10;

    // std::cout << *p << std::endl;
    // std::cout << *ap << std::endl;


    // delete p;


    // Foo* fp = new Foo();
    // AutoPtr fptr{Foo{}};
    // fp->foo();
    // fptr->foo();


    // AutoPtr fptr2 = fptr;
    // fptr2 = fptr2;

    // std::swap(fptr, fptr2);
    // delete fp;
}


struct  A; // forward declaration 


struct  B
{
    B() {
        std::cout << "B()\n";
    }
    ~B() {
        std::cout << "~B()\n";
    }

    std::shared_ptr<A> ptr;
};



struct  A
{
    A() {
        std::cout << "A()\n";
    }

    ~A() {
        std::cout << "~A()\n";
    }

    std::weak_ptr<B> ptr;
};





void func2() {
    std::shared_ptr<A> a{new A{}};
    std::shared_ptr<B> b{new B{}};
    b->ptr = a;
    a->ptr = b;
    


    std::cout << a.use_count() << " " << a->ptr.use_count() << std::endl;
    std::cout << b.use_count() << " " << b->ptr.use_count() << std::endl;

}


int main() {
   
    int x = 5;
    int& i = x;
    i = 10;
    //func2();
    return 0;
}





// 2й поток
// struct Foo {
//     void foo() const {
//         std::cout << "foo()\n";
//     }
// };




// template<typename T>
// class AutoPtr {
// public:
//     AutoPtr(T* ptr)
//         : value_(ptr)
//     {}

//     ~AutoPtr() {
//         if(value_)
           
//             delete value_;
//     }

//     AutoPtr(const AutoPtr& other) = delete;
//     // {
//     //     value_ = other.value_;
//     //     other.value_ = nullptr;
//     // }

//     AutoPtr& operator=(AutoPtr& other) = delete;
//     //     if(&other == this)
//     //         return *this;

//     //     value_ = other.value_;
//     //     other.value_ = nullptr;
        
//     //     return *this;
//     // }

//     T& operator*() const {
//         return *value_;
//     }

//     T* operator->() const {
//         return value_;
//     }

// private:
//     T* value_;
// };


// void func() {

//     std::unique_ptr<int> ptr;


//     FILE* file = fopen("in.txt", "r");
//     //fclose(file);
    
//     AutoPtr fPtr(file);



//     // AutoPtr ptr{new int(5)};
//     // std::cout << *ptr << std::endl; // 5
//     // *ptr = 10;
//     // std::cout << *ptr << std::endl; // 10

//     // AutoPtr ptr2 = ptr; 
//     // ptr2 = ptr;




// // //    int* ptri = new int(5);
// //     AutoPtr ptr(5);
    
// //  //   std::cout << *ptri << std::endl; // 5
// //     std::cout << *ptr << std::endl; // 5

// // //    *ptri = 10;
// //     *ptr = 10;

// //     std::cout << *ptri << std::endl; // 10
// //     std::cout << *ptr << std::endl; // 10




// //     delete ptri;


//     // return ;
//     // AutoPtr pfoo{Foo{}};


//     // Foo* pf = new Foo();

//     // pf->foo();

//     // pfoo->foo();

//     // delete pf;

//     return;
// }


// struct A;

// struct B {
//     B() { std::cout << "B\n";}
//     ~B() { std::cout << "~B\n";}
//     std::shared_ptr<A> ptr;
// };

// struct A {
//     A() { std::cout << "A\n";}
//     ~A() { std::cout << "~A\n";}
//     std::weak_ptr<B> ptr;
// };

// void func2(){
//     std::shared_ptr<A> a {new A()};
//     std::shared_ptr<B> b {new B()};
//     //a->ptr = b;
//     b->ptr = a;

//     std::cout << a.use_count() << " " << a->ptr.use_count() << std::endl;
//     std::cout << b.use_count() << " " << b->ptr.use_count() << std::endl;
    
//     // nothing will be deleted
// }

// int main(int, char**){
//     func2();
// }
