
// #include <iostream>
// #include <stdio.h>
// 1й полупоток
#include "lib.h"
#include "lib.h"

// declaration
int add(int a, int b);




#define MAX(x, y) (x > y ? x : y)

// #ifdef __DEBUG__
//    #define error_log(format, ...) printf("[ERROR] (%s:%d) " format "\n", __FILE__,
// __LINE__, ##__VA_ARGS__)
// #else
//    #define error_log(format, ...)
// #endif



#define __SOME__


#ifdef __SOME__
    #define error_log(error) printf("%s:%d %s\n", __FILE__, __LINE__, error)   
#else
    #define error_log(error)
#endif

int main() {

    error_log("Somthing's going wrong");
    error_log("Somthing's going wrong");
    error_log("Somthing's going wrong");

    

    return 0;

    const char* a = "AAA";
    const char* b = "BBB";
    const char* c = "AAA";
    const char* d = "BBB";

    std::cout << MAX(a, b) << std::endl;
    std::cout << MAX(d, c) << std::endl;
    
    
    return 0;
}


// 2й полупоток
// #include <iostream>

// #include "lib.h"


// //#include <iostream>

// //#include <stdio.h>

// //#define MAX(x, y) (x > y ? x : y)
// // #define PI 3.14

// // // declaration
// // int add(int a, int b);




// // //definition
// // int add(int a, int b) {
// //      return a + b;
// // }

// // #ifdef __DEBUG__
// //    #define error_log(format, ...) printf("[ERROR] (%s:%d) " format "\n", __FILE__,
// // __LINE__, ##__VA_ARGS__)
// // #else
// //    #define error_log(format, ...)
// // #endif


// // #define __DEBUG__ 0

// // #ifdef __DEBUG__
// //  #define error_log(err) printf("[ERROR] %s %d %s", __FILE__, __LINE__,   err);
// // # else
// //   #define error_log(err)
// // #endif


// // #pragma pack(1)
// // struct SomeStruct {
// //     uint64_t i;
// //     uint64_t i3;
// //     uint32_t i2;
// //     char ch; 
// // };



// int main(int, char**){

//     int i = foo();

//     std::cout << i;

//     //std::cout << sizeof(SomeStruct) << std::endl;












//     //error_log("somthing going wrong");

//     // int x = 1;
//     // int y = 2;
    
//     // char a[] = ' MAX(1,2) ';
//     // // char b[] = "BBB";
//     // // std::cout << MAX(a, b) << std::endl;
//     // // std::cout << MAX(b, a) << std::endl;
    
// }




