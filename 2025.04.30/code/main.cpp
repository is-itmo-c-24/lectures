#include <iostream>



//1й поток
// template<typename T>
// void print(T value) {
//     std::cout << "Value = " << value << std::endl;
// }


// template<>
// void print(int* value) {
//     std::cout << "Int value* = " << value << std::endl;
// }


// template<typename T>
// void print(T* value) {
//     std::cout << "Value* = " << *value << std::endl;
// }




template<typename U, typename V>
struct is_same {
    static constexpr bool value  = false;
};

template<typename T>
struct is_same<T, T> {
    static constexpr bool value  = true;
};



bool same(int x, int y) {
    return x == y;
}


template<typename T>
T&& identity(T&& value) {
    return std::forward<T>(value);
}

template<auto Value>
struct v_identity {
    static constexpr auto value = Value;
};


template<auto Value>
constexpr auto indetity_v = v_identity<Value>::value;


template<typename T>
struct remove_const : std::type_identity<T> {
};

template<typename T>
struct remove_const<const T> : std::type_identity<T> {
};

template<typename T>
struct remove_volatile : std::type_identity<T> {
};

template<typename T>
struct remove_volatile<volatile T> : std::type_identity<T> {
};


template<typename T>
using remove_cv_t = remove_volatile<typename remove_const<T>::type>::type;





template<typename T>
struct is_pointer_impl : std::false_type {};

template<typename T>
struct is_pointer_impl<T*> : std::true_type {};



template<typename T>
using is_pointer = is_pointer_impl<remove_cv_t<T>>;




template<typename T>
constexpr bool is_pointer_v = is_pointer<T>::value;


// void print(...) {
//     std::cout << "No implementation\n";
// }

// void print(int i) {
//     std::cout << "int value " << i << std::endl;
// }



template<typename T>
void foo(int T::*) {
    std::cout << "void foo(int T::*)\n";
}

template<typename T>
void foo(...) {
    std::cout << "void foo(...)\n";
}


struct Boo {

};

struct Foo {
    /* data */
};


template<typename T>
void func(T&& value, std::enable_if_t<!std::disjunction_v<std::is_same<T, Boo>, std::is_same<T, Foo>>, void*> = nullptr) {

}


template<typename T>
void print(const T& value, std::enable_if_t<std::is_pointer_v<T>, void*> = nullptr) {
    std::cout << *value << std::endl;
}


template<typename T>
void print(const T& value, std::enable_if_t<!std::is_pointer_v<T>, void*> = nullptr) {
    std::cout << value << std::endl;
}


template<typename T, typename... TArgs>
struct  FilterTypes
{
    using Result = T, TArgs...;
};


int main() {

    int i = 1;

    func(Boo{});

    //void print(const int& value, std::enable_if_t<!std::is_pointer_v<int>, void*> = nullptr) \

    //void print(const int& value, std::enable_if_t<true, void*> = nullptr)
    //void print(const int& value, void* = nullptr)

    print(i);



    print(&i);





    using IntMemberPtr = int Boo::*;
    foo<Boo>(nullptr);
    foo<int>(nullptr);

    // print(1);
    // print("Hello world");
    // print(1,1);


    static_assert(is_pointer_v<int*>);
    static_assert(!is_pointer_v<int>);
    static_assert(is_pointer_v<void*>);

    static_assert(is_pointer_v<const int*>);
    static_assert(is_pointer_v<int* const>);
    static_assert(is_pointer_v<int* volatile>);
    static_assert(is_pointer_v<int* volatile const>);

    int x = identity(239);
    int y = indetity_v<239>;


    static_assert(is_same<int, int32_t>::value);

}











//2й поток
// template<typename T>
// void print(T value) {
//     std::cout << "Value = " << value << std::endl;
// }



// template<>
// void print(int* value) {
//     std::cout << "Int value* = " << value << std::endl;
// }

// template<typename T>
// void print(T* value) {
//     std::cout << "Value* = " << *value << std::endl;
// }


// template<typename U, typename V>
// struct is_same {
//     static constexpr bool value = false;
// };


// template<typename T>
// struct is_same<T,T> {
//     static constexpr bool value = true;
// };








// template<typename T>
// T&& identity(T&& value) {
//     return std::forward<T>(value);
// }

// template<auto Value>
// struct value_identity {
//     static constexpr auto value = Value;
// };


// template<typename T>
// struct type_identity {
//     using type = T;
// };


// template<auto Value>
// constexpr auto value_identity_v = value_identity<Value>::value;

// template<typename U, typename V>
// constexpr bool is_same_v = is_same<U, V>::value;

// template<typename T>
// using type_identity_t = type_identity<T>::type;



// template<typename T>
// struct remove_const {
//     using type = T;
// };

// template<typename T>
// struct remove_const<const T> {
//     using type = T;
// };



// template<typename T>
// struct remove_volatile {
//     using type = T;
// };

// template<typename T>
// struct remove_volatile<volatile T> {
//     using type = T;
// };


// template<typename T>
// using remove_cv = remove_volatile<typename remove_const<T>::type>::type;






// template<typename T>
// struct is_pointer_inner : std::false_type{};

// template<typename T>
// struct is_pointer_inner<T*> : std::true_type{};


// template<typename T>
// struct is_pointer : is_pointer_inner<remove_cv<T>>{};




// template<typename T>
// constexpr bool is_pointer_v = is_pointer<T>::value;



// void print(...) {
//     std::cout << "No implementation\n";
// }


// void print(int i) {
//     std::cout << "int value " << i << std::endl;
// }

// struct Boo {
// };



// template<typename T>
// void foo(int T::*) {
//     std::cout << "foo(int T::*)\n";
// }


// template<typename T>
// void foo(...) {
//     std::cout << "foo(...)\n";
// }

// int main() {

//     using IntBooMemberPtr = int Boo::*;
//     //using IntBooMemberPtr = int int::*; // compile-time error


//     foo<Boo>(nullptr);
//     foo<int>(nullptr);


//     return 0;


//     print(1);
//     print("Hello world");
//     print(1,1);


//     static_assert(std::is_same_v<remove_const<int>::type,int>);
//     static_assert(std::is_same_v<remove_const<const int>::type,int>);


//     static_assert(!is_pointer_v<int>);
//     static_assert(is_pointer_v<int*>);
//     static_assert(is_pointer_v<int* const>);
//     static_assert(is_pointer_v<int* volatile>);
//     static_assert(is_pointer_v<int* const volatile>);


//     static_assert(
//         is_same_v<Boo, type_identity_t<Boo>>
//     );

//     int x = identity(239);
//     int y = value_identity_v<239>;

//     static_assert(is_same<Boo, Boo>::value);
//     static_assert(!is_same<int, float>::value);
//     static_assert(!is_same<int, int&>::value);

// }
