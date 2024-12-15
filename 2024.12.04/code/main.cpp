#include "lib.h"
/*

#include <iostream>


template<class T>
void printMe(const T& value);
*/




#include <vector>
#include <iostream>


//1й поток

// int max(int a, int b) {
//     return a > b ? a : b;
// }


// const std::string& max(const std::string& a, const std::string& b) {
//     return a > b ? a : b;  
// }


template<typename T>
const T& max(const T& a, const T& b) {
    return a > b ? a : b;
}



template<class InputIt, class UnaryFunc>
void for_each(InputIt first, InputIt last, UnaryFunc f) {
    for(;first != last; ++first) { 
        f(*first);
    } 
};



// template<class T>
// void printMe(const T& value) {
//     std::cout << value;
// }



template<typename T1, typename T2>
class CPair {
public:
    CPair() = default;
    CPair(const T1& first, const T2& second)
        : first_(first)
        , second_(second)
    {}

    const T1& first() const {
        return first_;
    }

    const T2& second() const {
        return second_;
    }


    template<typename U1, typename U2>
    CPair& operator=(const CPair<U1, U2>& other) {
        first_ = (T1)other.first();
        second_ = (T2)other.second();
        return *this;
    }


    template<typename U1>
    CPair& operator=(const CPair<U1, std::string>& other) {
        first_ = (T1)other.first();
        second_ =  std::atoi(other.second().c_str());
        return *this;
    }

private:
    T1 first_;
    T2 second_;
};



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const CPair<T1, T2>& value ) {
    stream << "CPair(" << value.first() << ", " << value.second() << ")";
    return stream;
}



class CArrayWithPar {
public:
    explicit CArrayWithPar(size_t size) 
    {}
private:

};


template<typename T, size_t SIZE> 
class CArray {
public:
    T& operator[](size_t index) { 
        return arr[index];
    }
    const T& operator[](size_t index) const { 
        return arr[index];
    }

    bool empty() const { return SIZE == 0; }
    size_t size() const { return SIZE; }
private:
    T arr[SIZE]; 
};


template <class T> 
struct greater {
    bool operator()(const T& a, const T& b) const { 
        return a > b;
    } 
};


template <class T> 
struct less {
    bool operator()(const T& a, const T& b) const { 
        return a < b;
    } 
};


template <class T, class cmp_t=less<T>>
void buble_sort(T* begin, T* end, cmp_t cmp = cmp_t()) {
    size_t count = end - begin ;
    for(size_t i = 0; i < count; ++i) {
        for(size_t j = 0; j < count - i - 1; ++j) {
            if(!cmp(begin[j],begin[j+1]))
             std::swap(begin[j], begin[j+1]);
        } 
    }
}



struct Foo
{
    enum {
        value = 100500
    };
};



template<unsigned N>
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

    int n = 1;
};

int main() {


    std::cout << Factorial<5>::value << std::endl;



    return 0;




    int values[] = {5,4,3,2,1}; 

    buble_sort(values, values + 5);


    for(int i = 0; i < 5; ++i)
        std::cout << values[i];


    return 0;
     

    CArray<int, 10> arr10;
    CArray<int, 11> arr11;




    return 0;
    CPair pair{1,2};   // CPairIntInt
    CPair<int, std::string> pair2{1, "ITMO"};

    CPair<int, double> pair3;   // CPairIntDoulbe

    pair3 = pair2;


    std::vector v = {1,2,3,4,5};

    

    std::cout << pair << std::endl;

    std::cout << pair2 << std::endl;



    return 0;



    
    for_each(values, values+5, printMe<int>);


    // std::string svalues[] = {"1","2","3","4","5"}; 
    
    // for_each(svalues, svalues+5, printMe<std::string>);

    return 0;
    
    std::cout << max<double>(1, 2.2) << std::endl;

    
    std::cout << max(2, 3) << std::endl;

    std::cout << max<std::string>("bbb", "aaa") << std::endl;


    return 0;
}













// 2й поток
// // int max(int a, int b) {
// //     return a > b ? a : b;
// // }


// // const std::string& max(const std::string& a, const std::string& b) {
// //     return a > b ? a : b;
// // }


// // #define MAX(a, b) ( (a > b) ? a : b)


// template<typename T>
// const T& max(const T& a, const T& b) {
//     return a > b ? a : b;
// }


// template<class InputIt, class UnaryFunc>
// void for_each(InputIt first, InputIt last, UnaryFunc f) {
//     for(;first != last; ++first) {
//          f(*first);
//     }
// };






// // template<class InputIt, class UnaryFunc>
// // InputIt = std::string*
// // UnaryFunc = void (*func)(const int&)

// void for_each(int* first, int* last, void (*f)(const int&) ) {
//     for(;first != last; ++first) {
//          f(*first);   // func(std::string)
//     }
// };


// template<typename T1, typename T2>
// class CPair {
// public:
//     CPair() = default;
//     CPair(const T1& first, const T2& second)
//         : first_{first}
//         , second_{second}
//     {}

//     const T1& first() const {
//         return first_;
//     }

//     const T2& second() const {
//         return second_;
//     }


//     template<typename U1, typename U2>
//     CPair& operator=(const CPair<U1, U2>& other) {
//         first_ = (T1)other.first();
//         second_ = (T2)other.second();

//         return *this;
//     } 

// private:
//     T1 first_;
//     T2 second_;

// };


// /*


// class CPairIntInt {
// public:
//     CPair() = default;
//     CPair(const int& first, const int& second)
//         : first_{first}
//         , second_{second}
//     {}

//     const int& first() const {
//         return first_;
//     }

//     const int& second() const {
//         return second_;
//     }


//     template<typename U1, typename U2>
//     CPair& operator=(const CPair<U1, U2>& other) {
//         first_ = (T1)other.first();
//         second_ = (T2)other.second();

//         return *this;
//     } 

// private:
//     int first_;
//     int second_;

// };




// class CPairIntDoulbe {
// public:
//     CPair() = default;
//     CPair(const int& first, const double& second)
//         : first_{first}
//         , second_{second}
//     {}

//     const int& first() const {
//         return first_;
//     }

//     const double& second() const {
//         return second_;
//     }


//     template<typename U1, typename U2>
//     CPair& operator=(const CPair<U1, U2>& other) {
//         first_ = (T1)other.first();
//         second_ = (T2)other.second();

//         return *this;
//     } 


    
//     CPair& operator=(const CPair<int, int>& other) {
//         first_ = (int)other.first();
//         second_ = (double)other.second();

//         return *this;
//     } 

// private:
//     int first_;
//     double second_;

// };


// */


// template <typename T1, typename T2>
// std::ostream& operator<<(std::ostream& stream, const CPair<T1,T2>& pair) {
//     stream << "CPair(" << pair.first() << "," << pair.second() << ")";
//     return stream ; 
// };



// template <class T> struct greater {
//     bool operator()(const T& a, const T& b) const { 
//         return a > b;
//     }
// };


// template <class T> 
// struct less {
//     bool operator()(const T& a, const T& b) const { 
//         return a < b;
//     }
// };



// template <class T, class cmp_t=less<T>>
// void buble_sort(T* begin, T* end, cmp_t cmp = cmp_t()) {
//     size_t count = end - begin ;
//     for(size_t i = 0; i < count; ++i) {
//         for(size_t j = 0; j < count - i - 1; ++j) {
//             if(!cmp(begin[j],begin[j+1])) std::swap(begin[j], begin[j+1]);
//         }
//     }
// }

// struct Foo {
//     enum {
//          value = 1
//     };
// };


// template<unsigned N>
// struct Factorial {
//     enum {
//         value = N * Factorial<N-1>::value
//     };

//     int value 
// };



// template<>
// struct Factorial<0> {
//     enum {
//         value = 1
//     };
// };

// /*

// N = 5
// struct Factorial {
//     enum {
//         value = 5 * Factorial<4>::value
//     };
// };


// N = 4
// struct Factorial {
//     enum {
//         value = 4 * Factorial<3>::value
//     };

//     in
// };

// */


// int main(int, char**) {




//     std::cout << Factorial<5>::value << std::endl;









//     return 0;


//     int values[] = {1, 2, 3, 4, 5};

//     buble_sort(values, values + 5);

//     for(int i = 0; i < 5; ++i)
//         std::cout << values[i];



//     return 0;
//      CPair pair{1, 2};  // CPairIntInt
//      CPair pair2{1, std::string{"ITMO"}};
//      CPair<int, double> pair3; // CPairIntDoulbe

//     std::vector v = {1,2,3,4,5};

//      pair3 = pair;


//      std::cout << pair << std::endl;
//      std::cout << pair2 << std::endl;












//     return 0;

//     ///int values[] = {1, 2, 3, 4, 5};
    
    
//     for_each(values, values+5, printMe<int>);


//     return 0;

//     std::cout << max<int>(3, 4) << std::endl;

//     std::cout << max<int>(1, 2) << std::endl;



//     std::cout << max<std::string>("bbb", "aaa") << std::endl;

//     //std::cout << max<Foo>(Foo{}, Foo{}) << std::endl;
    

// }
