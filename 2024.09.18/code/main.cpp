#include <iostream>


/*

    6  = 110

    _ _ _ _ _ _ _ _ 

6   0 0 0 0 0 1 1 0
-5  1 0 0 0 0 1 0 1
    1 1 1 1 1 0 1 0


    1 1 1 1 1 1 1 1
    0 0 0 0 0 0 0 0
*/


enum EMonth {
    JANUARY,
    FEBRARY,
};

void printMonth(EMonth month) {
    if(month == 0) {
        std::cout << "January\n";
    }
}

int main () {
    EMonth month = EMonth::JANUARY;

    printMonth(FEBRARY);

    float f = 1.23;
    float f2 = (float)10 + f;


    // int z;
    // if(f > 0)
    //     z = 1;
    // else 
    //     z = 2;


    // int z = (f > 0) 
    //             ? (f2 > 0) ? 1 : 3
    //             : 2;

    int n = -2;
    int a = 1;
    int b = 2;
    int z = 20;
    if (n > 0)
        if(a > b)
            z = a;
        else
            z = b;

    std::cout << z << std::endl;
}











// 2й полупоток
// enum EMonth {
//     JANUARY,
//     FEBRART,
    
    
// };

// void printMonth(EMonth num) {
//     if(num == JANUARY) {
//         std::cout  << "Janaury\n";
//     }
// }


// int main(int, char**){

//     EMonth month = JANUARY;

//     printMonth(month);

//     float f = 1.23;

//     float f2 = (float)10 + f;


//     std::cout << "Hello, from app!\n";

//     int n = -2;
//     int a = 1;
//     int b = 2;
//     int z = 20;
//     if (n > 0) {
//         if(a > b) {
//             z = a;
//         }
//     } else {
//             z = b;
//      }
    

//     std::cout << z << std::endl;
// }
