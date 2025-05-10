#include <iostream>
#include <variant>


//1й поток


template<typename T>
std::vector<std::string> to_strings(const std::vector<T>& data) {
    std::vector<std::string> result;
    for(const auto& v : data)
        result.push_back(std::to_string(v));

    return result;
}

template<typename T>
std::vector<std::string> to_strings(const T& value) {
    std::vector<std::string> result = {std::to_string(value)};
    return result;
}

template<typename T, typename U>
std::vector<std::string> to_strings(const T& value,const U& value2) {
    return {std::to_string(value), std::to_string(value2)};
}


template<typename ...TArgs>
auto divide(TArgs... args) {
    return (1 / ... / args );
}


template<typename... TArgs>
std::vector<std::string> to_strings(const TArgs&... args) {
    return std::vector<std::string>{to_string(args)...};
}

template<typename... TValue>
struct NaiveTuple;

template<size_t I, typename... TArgs>
struct tuple_element;


template<size_t I, typename Head, typename... Tail>
struct tuple_element<I, Head, Tail...> {
    using value_type = typename tuple_element<I-1, Tail...>::value_type;

    static value_type get(const NaiveTuple<Head,Tail...>& t) {
        return tuple_element<I-1, Tail...>::get(t);
    }

};


template<typename Head, typename... Tail>
struct tuple_element<0, Head, Tail...> {
    using value_type = Head;

    static value_type get(const NaiveTuple<Head,Tail...>& t) {
        return t.value;
    }

};

template<typename Head, typename... Tail>
struct NaiveTuple<Head, Tail...> : public NaiveTuple<Tail...>{

    using Base = NaiveTuple<Tail...>;

    NaiveTuple(const Head& head, const Tail&... tail_values)
        : value(head)
        , NaiveTuple<Tail...>(tail_values...)
    {}

    Head value;

    Base& tail() {
        return static_cast<Base&>(*this);
    }

    template<size_t I>
    typename tuple_element<I, Head,Tail...>::value_type get() {
        return tuple_element<I, Head,Tail...>::get(*this);
    }

};


template<>
struct NaiveTuple<>
{
};


template<size_t I, typename... TArgs>
typename tuple_element<I,TArgs...>::value_type get(const NaiveTuple<TArgs...>& t) {
    return tuple_element<I,TArgs...>::get(t);
}


void func(int i, float f, bool b) {
    std::cout << i << " " << f << " " << b << std::endl;
}


template<typename TFunc, typename TArg, size_t N, size_t Current, size_t... indexes>
void invoker_by_tuple_impl(TFunc func, TArg& t) {

    if constexpr(sizeof...(indexes) == N) {
        func(get<indexes>(t)...);
    } else{
        invoker_by_tuple_impl<TFunc, TArg, N, Current + 1, indexes..., Current>(func, t);
    }

}


template<typename TFunc, typename... TArgs>
void invoker_by_tuple(TFunc func, const NaiveTuple<TArgs...>& t) {
    invoker_by_tuple_impl<TFunc, const NaiveTuple<TArgs...>, sizeof...(TArgs), 0>(func, t);
}





int main() {

    NaiveTuple<int, float, bool> t = {1, 2.3, false};

    invoker_by_tuple(func, t);

    //std::cout << t.value << " " << t.tail().value << " " << t.tail().tail().value << std::endl;

    return 0;

    std::cout << divide(8,4,2) << std::endl;

    return 0;
    auto v = to_strings(1,false);

    for(const auto& i : v)
        std::cout << i << " ";

    std::cout << std::endl;

    return 0;
}















// 2й поток
// // template<typename T>
// // std::vector<std::string> to_strings(const std::vector<T>& data) {
// //     std::vector<std::string> result;

// //     for(const auto& v : data)
// //         result.push_back(std::to_string(v));

// //     return result;
// // }


// // template<typename T, typename U>
// // std::vector<std::string> to_strings(T&& t, U&& u) {
// //     std::vector<std::string> result = {std::to_string(std::forward<T>(t)), std::to_string(std::forward<U>(u))};

// //     return result;
// // }


// std::vector<std::string> to_strings() {
//     return {} ;

// }

// template<typename T, typename... TArgs>
// std::vector<std::string> to_strings(const T& value, const TArgs&... args) {
//     std::vector<std::string> result;
//     result.push_back(std::to_string(value));

//     std::vector<std::string> other = to_strings(args...);
//     result.insert(result.end(), other.begin(), other.end());
//     return result;
// }

// // template<typename ...TArgs>
// // auto divide(TArgs... args) {
// //     return (args / ... );
// // }

// // template<typename ...TArgs>
// // auto divide(TArgs... args) {
// //     return ( ... / args );
// // }

// template<typename ...TArgs>
// auto divide(TArgs... args) {
//     return (args / ... / 1.1 );
// }



// void func(int a,int b)
// {
//     std::cout << a * b << std::endl;
// }


// template<typename... TArgs>
// std::vector<std::string> to_strings(const TArgs&... args) {
//     return {to_string(args)...};
// }

// template<typename T, typename... Args>
// std::vector<T> make_vector(Args&&... args) {
//     std::vector<T> v;
//     (func(args, 2),...);
//     return v;
// }


// template<typename... T>
// struct NaiveTuple;


// template<>
// struct NaiveTuple<>  {

// };


// template<typename Head, typename... Tail>
// struct NaiveTuple <Head, Tail...> : public NaiveTuple<Tail...> {

//     using Base = NaiveTuple<Tail...>;

//     NaiveTuple(const Head& head, const Tail&... tails)
//         : value(head)
//         , NaiveTuple<Tail...>(tails...)
//     {}

//     Head value;
//     Base& base = static_cast<Base&>(*this);
// };


// template<size_t N, typename... TArfs>
// struct Getter ;


// template<size_t N, typename Head, typename... Tail>
// struct Getter<N, Head, Tail...> {
//     using value_type = Getter<N-1, Tail...>::value_type;
//     value_type operator()(const NaiveTuple<Head, Tail...>& t) const {
//         return Getter<N-1, Tail...>{}(t);
//     }
// };


// template<typename Head, typename... Tail>
// struct Getter<0, Head, Tail...> {
//     using value_type = Head;


//     value_type operator()(const NaiveTuple<Head, Tail...>& t) const {
//         return t.value;
//     }
// };



// template<size_t I, typename... TArgs>
// auto get(const NaiveTuple<TArgs...>& t) {
//     return Getter<I, TArgs...>{}(t);
// }

// template<typename... TArgs>
// NaiveTuple<TArgs...> make_tuple(TArgs... args){
//     return NaiveTuple<TArgs...>(args...);
// }




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


// template<typename ... Ts>
// struct Overload : Ts ... {
//     using Ts::operator() ...;
// };

// template<typename... Ts> Overload(Ts...) -> Overload<Ts...>;


// template<typename Derived>
// class FutureA {
// public:
//     void DoA () {
//         static_cast<Derived&>(*this).Do();
//     }
// };

// template<typename Derived>
// class FutureB {
// };

// template<typename Derived>
// class FutureC {



// };


// template<template<typename> typename... ConcreteFutures>
// class Foo : public ConcreteFutures<Foo<ConcreteFutures...>>... {
// public:
//     void Do() {

//     }
// };



// using FooBC = Foo<FutureB, FutureC>;


// //
// int main(int, char**){

//     FooBC f;
//     return 0;
//     std::variant<int, long, std::string> v = 1l;



//     auto overload = Overload {
//         [](char) { std::cout << "char"; },
//         [](int) { std::cout << "int"; },
//         [](long) { std::cout << "long"; },
//         [](const std::string&) { std::cout << "std::string"; }
//     };

//     std::visit(overload, v);


//     return 0;

//     auto tmp = MakeOverloaded(
//              [](int i){return i + 1;},
//              [](const std::string& str) { return str + str;}
//     );

//     tmp(1);
//     tmp("sss");

//     //make_vector<int>(1,2,3);

//     auto t = make_tuple(1, 2.3, false);

//     //Getter<2, int, float, bool> getter;

//     //std::cout << getter(t) << std::endl;

//     std::cout << get<0>(t) <<  " " << get<1>(t) << " " << get<2>(t);

//     return 0;


//     auto strings = to_strings(1, 4.5f, false, 2, 3.1);

//     for(const auto& s : strings)
//         std::cout << s << " ";

// }
