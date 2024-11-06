#include <iostream>
#include <numeric>




// 1й полупоток

// struct SPoint {
//     int x;
//     int y;
// };

// struct  SRect {
//     SPoint p1;
//     SPoint p2;
// };

// // 1й полупоток



// namespace TkchenkoStack {
//     struct Node {
//         int value; 
//         Node* prev;
//         size_t size;
//     };
// }


// namespace MediumRareStack {
//     struct Stack {
//         int* data;
//         size_t size;
//     };
// }


// namespace SimpleStack {
//     struct Stack {
//         int data[100500];
//         size_t size;
//     };
// };



// void push(int value)
// void pop() 
// int top()
// bool empty();


// int func();



class CRational { 
public:

    CRational(int numerator, unsigned denominator=1)
        : numerator_(numerator)
        , denominator_(denominator)
    {
        int common = std::gcd(numerator, denominator);
        numerator_ /= common;
        denominator_ /= common;


        std::cout << "CRational()\n";
    }

    CRational(const CRational& other)
        : numerator_(other.numerator_)
        , denominator_(other.denominator_)
    {
        std::cout << "CRational(const CRational& other)\n";
    }


    ~CRational() {

        std::cout << "~CRational()\n";
    }

    CRational& operator=(const CRational& other) { 

        std::cout << "operator=(const CRational& other)\n";

        if(&other == this)
             return *this;
        numerator_= other.numerator_;
        denominator_ = other.denominator_;
        return *this;

     }


    int numerator() const {
        
        return numerator_;
    }

    unsigned denominator() const {
        return denominator_;
    }
private:
   int numerator_;
   unsigned denominator_; 
};


void PrintRational(const CRational& number) { 
    std::cout   << number.numerator()
                << '/'
                << number.denominator()
                << std::endl;
}

void PrintRational(int i) {
    std::cout << i << std::endl;
}


void func() {

}


class GeoPoint {
public:

    GeoPoint(const CRational& lat, const CRational& lon) 
       : lat_(lat)
       , lon_(lon)
    {
        std::cout << "GeoPoint()\n";
    }


    ~GeoPoint() {
        std::cout << "~GeoPoint()\n";
    }
private:
   CRational lat_;
   CRational lon_;
};


class CIntArray {
public:
   CIntArray(size_t size)
       : size_(size)
       , data_ (new int[size])
   {}

    CIntArray(const CIntArray& other) 
        : data_(new int[other.size_])
        , size_(other.size_)
    {
        std::memcpy(data_, other.data_, sizeof(int) * size_);
    }

    CIntArray& operator=(const CIntArray& other) {
        delete[] data_;

        data_ = new int[other.size_];
        size_ = other.size_;
        std::memcpy(data_, other.data_, sizeof(int) * size_);

        return *this;
    }

   ~CIntArray(){
       delete[] data_;
    }

private:
   int* data_;
   size_t size_;
};

int main() {

    CIntArray arr1{10};
    CIntArray arr2{5};

    arr2 = arr2;

    // // CRational r1 = 1;
    // PrintRational(2);

    // // CRational r2{1,2};

    // // GeoPoint p{r1, r2};

    return 0;





    // int i1 = 1;
    // int i2 = 2;
    // int i3 = i1;
    // i3 = i1;


    // CRational r1{1,2};

    // PrintRational(r1);

    return 0;










    // CRational r2(5,10);

    // CRational r3 = r1;    
    // r3 = r1;



    // const CRational& cr = r1;
    // cr.denominator();



//     MediumRareStack::Stack st;


//     st.data = nullptr;
//     st.size = 100500;

// //    i = 10;

//     SPoint pt{1,2};

//     SRect r = {pt, {2,2}};

    return 0;
}



// 2й полупокто
// struct SPoint
// {
//     int x;
//     int y;
// };

// struct SRect {
//     SPoint p1;
//     SPoint p2;
// };



// int f();


// namespace HardStack {

//     struct Node {
//         int value;
//         Node* prev;
//     };



//     push(Node* node) {

//     }

//     pop() {

//     } 
//     int top() {

//     }
//     bool empty() {

//     }

// }


// namespace MediumRareStack {
//     struct Stack {
//         int* data;
//         size_t size;
//     };
// }


// namespace SimpleStack {
//     struct Stack {
//         int data[100500];
//         size_t size;
//     };
// }


// class CRational {
// public:
//     explicit CRational(int numerator=0 , unsigned denuminator=1) // default constructor
//         : numerator_(numerator)
//         , denominator_(denuminator)
//     {
//         unsigned gcd = std::gcd(numerator_, denuminator);
//         numerator_ /= gcd;
//         denominator_ /= gcd;

//         std::cout << "CRational()\n";
//     }

//     CRational(const CRational& other) // copy constructor 
//         : numerator_(other.numerator_)
//         , denominator_(other.denominator_)
//     { 
//         std::cout << "CRational(const CRational& other)\n";
//     }

//     // CRational(CRational&& other) // move constructor 
//     //     : numerator_(std::exchange(other.numerator_, 0))
//     //     , denominator_(std::exchange(other.denominator_, 0))
//     // { }


//     CRational& operator=(const CRational& other) { 
//         std::cout << "operator=(const CRational& other)\n";

//         if(&other == this)
//             return *this;


//         numerator_= other.numerator_;
//         denominator_ = other.denominator_;
//         return *this;
//      }

//     ~CRational() {
//         std::cout << "~CRational()\n";
//     }

//     int numerator() const {
        
//         return numerator_;
//     }


//     unsigned denominator() const {
//        return denominator_;
//     }

// private:
//    int numerator_;
//    unsigned denominator_;
// };


// void PrintRational(const CRational& number) { 
//     std::cout << number.numerator()
//               << '/'
//               << number.denominator()
//               << std::endl;
// }



// class GeoPoint {
// public:
//     GeoPoint() {}

//     GeoPoint(const CRational& lat, const CRational& lon) 
//         : lat_(lat)
//         , lon_(lon)
//     {
//         std::cout << "GeoPoint()\n";
//     }

//     ~GeoPoint() {
//         std::cout << "~GeoPoint()\n";
//     }

// private:
//    CRational lat_;
//    CRational lon_;
// };


// class CIntArray {
// public:
//    CIntArray(size_t size)
//        : size_(size)
//        , data_ (new int[size])
//    {}

//     ~CIntArray(){
//        delete[] data_;
//     }

//     CIntArray(const CIntArray& other)
//         : data_(new int[other.size_])
//         , size_(other.size_)
//     {
//         std::memcpy(data_, other.data_, sizeof(int)*size_);
//     }


//     CIntArray& operator=(const CIntArray& other) {

//         delete[] data_;


//         data_ = new int[other.size_];
//         size_ = other.size_;

//         std::memcpy(data_, other.data_, sizeof(int)*size_);

//         return *this;
//     }

// private:
//    int* data_;
//    size_t size_;
// };


// int main(int, char**){

//     CIntArray arr1{10};
//     CIntArray arr2 = arr1;

//     CIntArray arr3{5};

//     arr3 = arr1;

//     arr3 = arr3;



//     // PrintRational(CRational{2}); 



//     return 0;






//     CRational r1{1,2};
//     CRational r2{1,2};

//     GeoPoint p{r1,r2};

//     return 0; 

//     // //PrintRational(r1);

//     // // int i = 1;
//     // // int j = i;
//     //  CRational r2 = r1;
//     // // r2 = r1;


//     // // const CRational& cr = r1;

//     // // cr.denominator();
    

// }
