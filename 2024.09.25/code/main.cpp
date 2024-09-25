#include <iostream>
#include <format>



void swap(int* pa, int* pb) {
    if(pa == nullptr || pb == nullptr) {
        return;
    }
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;

}

void printBytes(void* ptr, size_t size) {
    uint8_t* bytes = (uint8_t*)ptr;
    for(size_t i = 0; i < size; ++i) {
       std::cout << std::format("{:08b} ", *bytes);
        ++bytes; 
    }
    std::cout << std::endl;
}


int main() {


    int a = 10;
    double d = 23.121;

    printBytes(&a, sizeof(a));
    printBytes(&d, sizeof(d));




    char c = 'a';

    char* pc = &c;
    int i = 10;
    int j = 12;

    int* pi = nullptr;
    int* pj = &j;


    //int* arr = {1,2,3,4,5};
    

    std::cout << pi <<  " " << pj << std::endl;

    swap(pi, pj);

    std::cout << pi <<  " " << pj << std::endl;


    // long l = 128L;
    // float f = 129.1;

    // std::cout << &i << std::endl;
    // std::cout << &j << std::endl;
    // std::cout << &l << std::endl;
    // std::cout << &f << std::endl;


    return 0; 
}






// 2й полупоток
// size_t StringLenght(char* str) {
//     size_t result = 0;
//     while (*str != '\0') { 
//         str++;
//         result++; 
//     }

//     return result;
// }

// void swap(int* a, int* b) {
//     if(a == nullptr || b == nullptr)
//         return ;


//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }


// void printBytes(void* ptr, size_t size) {
//     uint8_t* bytes = (uint8_t*)ptr;
//     for(size_t i = 0; i < size; ++i) {
//        std::cout << std::format("{:08b} ", *bytes);
//         ++bytes; 
//     }
//     std::cout << std::endl;
// }

// int main(int argc, char** argv) {
//     int i = 10;
//     // int j = 12;
//     // int* pi = nullptr;
//     // int* pj = &j;
//     double d = 12.23;

//     printBytes(&i, sizeof(int));
//     printBytes(&d, sizeof(double t));
    
//     // std::cout << pi << " " << pj << std::endl;  // 10 12

   
//     // swap(pi, pj);


//     // std::cout << pi << " " << pj << std::endl; // 12 10



//     // char* str = "ITMO";

//     // std::cout << sizeof(str) << std::endl;  // 8
 
//     // std::cout << StringLenght(str) << std::endl; // 4

     
//     return 0; 
// }