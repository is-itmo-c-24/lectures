#include <iostream>
#include <numeric>

// 2й полупоток
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

//     friend std::ostream& operator<<(std::ostream& stream, const CRational& r);
    
    
   
// private:
//    int numerator_;
//    unsigned denominator_;
//    int tmp_;
// };


 

// std::ostream& operator<<(std::ostream& stream, const CRational& r) {
//     stream << r.numerator() << "/" << r.denominator() << r.tmp_;

//     return stream;
// }


// class CMultiply {
// public:
//     CMultiply(int multi)
//         : multi_(multi)
//     {}

//     int operator()(int i) {
//         ++counter_;
//         return i * multi_;
//     }

// private:
//     int multi_;
//     int counter_ = 0;
// };

// int main(int, char**){
//     CMultiply twice{6};


//     std::cout << twice(10) << std::endl;


//     return 0;
//     CRational r1{1,2};
//     CRational r2;

   
//     //CRational r3 = r1 + r2;
// }


// 1й полупоток

class CRational {
public:
    explicit CRational(int numerator=0 , unsigned denuminator=1) // default constructor
        : numerator_(numerator)
        , denominator_(denuminator)
    {
        unsigned gcd = std::gcd(numerator_, denuminator);
        numerator_ /= gcd;
        denominator_ /= gcd;

        std::cout << "CRational()\n";
    }

    CRational(const CRational& other) // copy constructor 
        : numerator_(other.numerator_)
        , denominator_(other.denominator_)
    { 
        std::cout << "CRational(const CRational& other)\n";
    }

    // CRational(CRational&& other) // move constructor 
    //     : numerator_(std::exchange(other.numerator_, 0))
    //     , denominator_(std::exchange(other.denominator_, 0))
    // { }


    CRational& operator=(const CRational& other) { 
        std::cout << "operator=(const CRational& other)\n";

        if(&other == this)
            return *this;


        numerator_= other.numerator_;
        denominator_ = other.denominator_;
        return *this;
     }

    ~CRational() {
        std::cout << "~CRational()\n";
    }

   
    int numerator() const {
        
        return numerator_;
    }


    unsigned denominator() const {
       return denominator_;
    }
   
    // prefix operator
    CRational& operator++() {
         numerator_ += denominator_; 
         return *this;
    }
    // postfix operator
    CRational operator++(int) { 
        CRational tmp(*this);
        operator++();
        return tmp;
    }

    explicit operator float() const {
         return  numerator_/(float)denominator_;
    }   

    friend std::ostream& operator<<(std::ostream& stream, const CRational& r);

private:
   int numerator_;
   unsigned denominator_;
   int tmp_;
};


std::ostream& operator<<(std::ostream& stream, const CRational& r) {
    stream << r.numerator() << "/" << r.denominator() << r.tmp_;

    return stream;
}



void func(const CRational& r) {
   std::cout << r << std::endl;
}


CRational make_rational() {
    return CRational{1,3};
}

int main () {

    CRational i {1,2};
    CRational j {2};

    //CRational t = i + j + i * j;  

    std::cout << i << std::endl;
        
    float f = (float)i;

    std::cout << f << std::endl;
    

    return 0;
}