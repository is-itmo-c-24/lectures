#include <iostream>
#include <unistd.h>


// struct Record {
//   char name[10];
//   char surname[10];
//   long phone;
// };




// Record* FindRecord(long phone, Record* records, int count ) {
//     for(int i=0; i < count; ++i) {
//         if(records[i].phone == phone)
//             return &records[i];
//     }

//     return  nullptr;
// }


// int main(int, char**) {
//     Record phonebook[200];
//     // init phonebook


//     // Record* r =  FindRecord(1111l, phonebook, 200);
//     // if(r != nullptr)
//     //     std::cout << r->name;

//     Record* r = phonebook;

//     std::printf("%p\n", r);
//     r = r + 1;
//     std::printf("%p\n", r);

//     std::printf("%lu\n", sizeof(Record));

//     return 0;
// }




















const float PI = 3.14f;
int SomeGlobalValue = 2024;

void SomeFunc() {

}

int main(int, char**){
   int i = 0;
   const char* str = "Hello world";

   std::printf("Process id: %d\n", getpid());

   std::printf("Data segment: %p\n", &PI);
   std::printf("BSS segment %p\n", &SomeGlobalValue);
   std::printf("Text segment %p\n", str);
   std::printf("Code segment %p\n", &SomeFunc);
   std::printf("Stack segment %p\n",    );

   getchar();

   return 0;
}
