#include <iostream>
#include <vector>
#include  <algorithm>



// | 1 | 2 | 1 | 2 | 3 | 4 | 1 | x    num = 2;
// | 1 | 1 | 3 | 4 | 1 | x         4 | 1 | x    num = 2;
//                               be 
//                       c       


std::vector<int>::iterator my_remove(std::vector<int>::iterator begin, std::vector<int>::iterator end, int num) {
    std::vector<int>::iterator cur_place = begin;
    while (begin != end) {
        if (*begin != num) {
            *cur_place = *begin;
            ++cur_place;
        }
        ++begin;
    }
    return cur_place;
}















template<typename T>
std::vector<T>::iterator my_remove(std::vector<T>::iterator begin, std::vector<T>::iterator end, const T& value) {
  while (begin != end) {
    if (*begin == value) {
      std::vector<T>::iterator new_begin = begin + 1;
      while (new_begin != end && *new_begin != value) {
        *begin = *new_begin;
        ++new_begin;
        ++begin;
      }
    }
    ++begin;
  }
}



// int Remove(std::vector<int>& vec, int left, int end, int val) {
//     int cur = left;
//     while (left != end) {
//         if (vec[left] != val) {
//             std::swap(vec[left], vec[cur]);
//             ++cur;
//         }
//         ++left;
//     }
//     return cur;
// }


template<typename IterType, typename ElemType>
IterType remove(IterType begin, IterType end, ElemType removing_val){
    IterType p1 = begin;
    IterType p2 = begin;
    while (p2 != end){
        if (*p2 == removing_val){
            ++p2;
        }
        else{
            *p1 = *p2;
            ++p1;
            // вообще надо p2 тоже инкрементировать...
        }
    }
    return p1;
}


template<class ForwardIterator, class T>
ForwardIterator MyRemove(ForwardIterator begin, ForwardIterator end, const T& value) {
    ForwardIterator st = begin;
    while (st != end) {
        if (*st != value) {
           // std::swap(*st, *begin);
            *being = *st;
            ++begin;
        }
        ++st;
    }
    return begin;
}


// template<typename IterType, typename ElemType>
// IterType remove(IterType begin, IterType end, ElemType removing_val){
//     IterType p1 = begin;
//     IterType p2 = begin;
//     while (p2 != end){
//         if (*p2 != removing_val){
//             *p1 = *p2;
//             ++p1;
//         }
//         ++p2;
//     }
//     return p1;
// }

// 
// template<typename ForwardIterator, typename T> 
// void my_remove(ForwardIterator begin, ForwardIterator end, const T& value) { 
//   ForwardIterator from = begin; 
//   while (true) { 
//  while ((from != end) && (*from == value)) ++from; 
//  if (from == end) break; 
//  if (begin != from) *begin = *from; 
//     ++begin; 
//  ++from; 
//   } 
// }


int main() {

    // std::vector<int> v1 = {1,2,3,4,5};
    // std::vector<int> v2{5,0};


    // std::copy(v1.begin(), v1.end(), v2.begin();


    // for()


    std::vector<int> vec = {0, 1, 2, 0, 3, 4, 0, 5, 6, 7, 0, 8};
    std::vector<int>::iterator new_end = std::remove(vec.begin(), vec.end(), 0);
    vec.erase(new_end, vec.end());


    for(int i : vec) 
        std::cout << i << " ";

    return 0;
}






















// /*

// @elemantreum

// template<typename RandomAccessIterator, typename T>
// RandomAccessIterator remove(RandomAccessIterator first, RandomAccessIterator last, const T& value) {
//     int count_erased = 0;
//     while (first != last) {
//         if (*first == value) count_erased++;
//         *(first - count_erased) = *first;
//         ++first;
//     }
    
//     return first - count_erased;
// }
// */

// // template<typename Iterator, typename T>
// // Iterator remove(Iterator first, Iterator last, const T& value) {
// //     Iterator end = last - 1;
// //     if(*end == value)
// //         --end;

// //     while(first != last) {

// //         if(*last == value)
// //             std::swap(first, last);
// //         --last;
// //     }    
// //}

// int main(int, char**){
//     std::vector<int> v = {1,0,1,0,1,0};

//     std::vector<int>::const_iterator i =  v.begin();


//     //remove(v.begin(), v.end(), 0);


// }
