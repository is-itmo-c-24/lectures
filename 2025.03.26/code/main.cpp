#include <iostream>
#include <fstream>


// 1й поток


struct Foo {
    int i = 64;
};

struct Boo : public Foo {
    std::string str = "abc";
};

void func(Foo* b) {
    std::cout << b->i << std::endl;
}



template<typename T>
struct Counter {
    static int created;
    Counter() {
        ++created;
    }

    Counter(const Counter&) {
    ++created;
    }
};

template<typename T> int Counter<T>::created = 0;



template<typename T>
class Cloneable {
public:
    T clone() const {
        return T{static_cast<const T&>(*this)};
    }
};


struct  A : public Counter<A>, public Cloneable<A>
{
    /* data */
};


struct  B : public Counter<B>
{
    /* data */
};


template<class ConcreateAnimal>
class Animal {
public:
    std::string who() const {
        return static_cast<const ConcreateAnimal*>(this)->who();
    }
};

template<class T>
void who_am_i(Animal<T>& animal) {
    std::cout << animal.who() << std::endl;
}


class Dog : public Animal<Dog> {
public:
    std::string who() const {
        return "dog";
    }
};

class Cat : public Animal<Cat> {
public:
    std::string who() const {
        return "cat";
    }
};



int main() {
    Cat cat;
    Dog dog;

    who_am_i(cat);
    who_am_i(dog);


    return 0;

    A a;
    a.clone();
    A a1;
    B b;

    std::cout << A::created << std::endl;
    std::cout << B::created << std::endl;











    // std::vector<std::pair<int, int>> v{100500};

    // std::ofstream f{"out.txt"};

    // f << v.size() << std::endl;
    // for(const auto& i : v)
    //     f << i.first << " " << i.second << std::endl;


    // std::ofstream f1{"out.bin"};            
    // size_t size = v.size();
    // f.write(&size, sizeof(size_t));
    // f.write(reinterpret_cast<char*>(&v[0]), sizeof(std::pair<int,int>)* v.size());


    // Boo b;
    // Foo f;


    // //func(&b);
    // func((Foo*)&b);


    // return 0;
    // int i = 1;
    // int* pi = &i;
    // double* pd = (double*)pi;
    // double d = *pd;

    // std::cout << d << std::endl;
    // std::cout << *(double*)&i << std::endl;


    // return 0;

    // std::vector<bool> v(2147483649, 0);

    // size_t cnt = 0;
    // for(int i = 0; i < v.size(); ++i) {
    //     if(v[i] == 0)
    //         ++cnt;
    //     if(cnt % 1000000000 == 0)
    //         std::cout << cnt << std::endl;
    // }

    // std::cout << cnt << std::endl;

    return 0;

    // double d = -12.3456789;
    // std::cout << d << std::endl; // -12.345678
    // float f = d;
    // std::cout << f << std::endl; // -12.345677
    // int i = d;
    // std::cout << i << std::endl; // -12
    // uint32_t ui = d;
    // std::cout << ui << std::endl; // big number
    // char ch = d;
    // std::cout << ch << std::endl; // ub


    // return 0;

    // unsigned u = 1;
    // int s = -10;
    // std::cout << (u + s) << std::endl;
    // std::cout << (s + u) << std::endl;
    // return 0;
}






// 2й поток
// struct Base {
//     int i = 1;
    

//   //  virtual ~Base() = default;
// };

// struct Derived : public Base {
//     int j = 10;
//     void func() {
//         std::cout << "Derived " <<  j + i << std::endl;
//     }
// };


// template<typename T>
// struct Counter {
//     static int created;
//     Counter() {
//         ++created;
//     }

//     Counter(const Counter&) {
//         ++created;
//     }
// };
// template<typename T> int Counter<T>::created = 0;



// template<typename T>
// class Cloneable {
// public:
//     T clone() const {
//         return T{static_cast<const T&>(*this)};
//     }
// };


// struct  A : public Counter<A>, public Cloneable<A>
// {
//     /* data */
//     int i  = 1;
// };


// struct  B : public Counter<B>, public Cloneable<B>
// {
//     /* data */
// };

// template<class ConcreateAnimal>
// class Animal {
// public:
//     std::string who() const {
//         return static_cast<const ConcreateAnimal*>(this)->who();
//     }
// };

// template<class T>
// void who_am_i(Animal<T>& animal) {
//     std::cout << animal.who() << std::endl;
// }

// class Dog : public Animal<Dog> {
// public:
//     std::string who() const {
//         return "dog";
//     }
// };


// class Cat : public Animal<Cat> {
// public:
//     std::string who() const {
//         return "cat";
//     }
// };



// int main(int, char**){

    
//     Dog d;
//     Cat c;

//     who_am_i(d);
//     who_am_i(c);


//     return 0;


//     A a;
//     a.clone();



//     A a2;
//     B b;


//     std::cout << A::created << std::endl;
//     std::cout << B::created << std::endl;

//     return 0;

//     std::vector<std::pair<int,int>> v{100};


//     std::ofstream f{"tmp.txt"};

//     for(const auto& i : v) {
//         f << i.first << " " << i.second << std::endl;
//     }


//     std::ofstream f1{"tmp.bin"};

//     f1.write(reinterpret_cast<char*>(&v[0]), v.size() * sizeof(std::pair<int,int>));





//     // Base d{};
//     // int n = 100;
//     // d.i = 10;
//     // Base* b = new Base();


//     // Derived* d1 = dynamic_cast<Derived*>(b);

//     // if(d1 != nullptr)
//     //     d1->func();

//     return 0;
    










//     const int i = 0;
//     const int* cpi = &i;
//     int* pi = const_cast<int*>(cpi);

//     *pi = 100500;
//     std::cout << i << std::endl;
    

//     const char* str = "Hello world!";
//     char* s = const_cast<char*>(str);
//     s[0] = 'A'; 


//     return 0;
//     // int i = 1;
//     // int* p = &i;
//     // double* pd = (double*)p;
//     // double d = *pd;
//     // std::cout << d << std::endl;
//     // std::cout << *(double*)&i << std::endl;


//     // std::vector<bool> v(2147483649, 0);
//     // size_t cnt = 0;

//     // int i = 0;
//     // for(; i < v.size(); ++i) {
//     //     if(v[i] == 0)
//     //         ++cnt;
//     //     if(cnt % 1000000000 == 0)
//     //         std::cout << cnt << std::endl;
//     // }
    
//     // std::cout << cnt << std::endl;
//     // std::cout << i << std::endl;

//     return 0;
// }
