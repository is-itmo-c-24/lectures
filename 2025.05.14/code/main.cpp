#include <iostream>
#include <thread>

#include <algorithm>
#include <chrono>
#include <numeric>

void sequential(std::vector<int>& values) {
    size_t count = 1000'000'000ull;
    //std::vector<int> values(count);

    std::generate(values.begin(), values.end(), []() { return rand() % 2;});
}


void parallel(std::vector<int>& values) {
    size_t count = 1000'000'000ull;

    size_t threadCount = 4;
    size_t perThreadCount = count / threadCount;

    std::vector<std::thread> threads;

    for(int i = 0; i < threadCount; ++i) {
        auto begin = values.begin() + i * perThreadCount;
        auto end = values.begin() + (i + 1) * perThreadCount;

        threads.emplace_back([&, begin, end]() {
            std::generate(begin, end, []() {return rand() % 2;});
        });
    }

    for(auto& tr : threads)
        tr.join();
}


void sequential_acc(const std::vector<int>& data) {
    int result = 0;
    for(int i = 0; i < data.size(); ++i)
        result += data[i];
    std::cout << result << std::endl;
}


std::mutex mutex;

void parallel_acc(const std::vector<int>& data, size_t threadCount) {
    int result = 0;
    size_t perThreadCount = data.size() / threadCount;

    std::vector<std::thread> threads;



    for(int t = 0; t < threadCount; ++t) {
        threads.emplace_back([&](int thread){
            int local_result = 0;
            for(int i = thread * perThreadCount; i < (thread + 1) * perThreadCount; ++i) {
                mutex.lock();
                result += data[i]; // result = result + data[i]
                mutex.unlock();
            }


            // mutex.lock();
            // result += local_result;
            // mutex.unlock();
            },

            t );
        }
    for(auto& tr : threads)
        tr.join();


    std::cout << result << std::endl;
}


template<typename TFunc, typename... TArgs>
void execute(TFunc&& func, TArgs&&... data) {
    const auto start = std::chrono::high_resolution_clock ::now();

    func(std::forward<TArgs>(data)...);

    const auto end = std::chrono::high_resolution_clock ::now();

    const std::chrono::duration<double> diff = end - start;
    std::cout << "durration = " << diff << std::endl;
}

int main(int argc, char** argv) {
    size_t count = 1000'000'000ull;
    std::vector<int> values(count);

    // std::cout << "sequential generae";
    // execute(sequential, values);


    std::cout << "parallel generate ";
    execute(parallel, values);

    std::cout << "sequential acc ";
    execute(sequential_acc, values);


    std::cout << "parallel acc ";
    execute(parallel_acc, values, 4);

    return 0;
    using namespace std::chrono_literals;

    for(int i = 0; i < 8; ++i) {
        std::thread tr{[]{
            int i = 0;
            std::print("Hello from {0}. i has address {1} \n", std::this_thread::get_id(), (void*)std::addressof(i));
            std::this_thread::sleep_for(1s);
        }};
        tr.detach();
    }
    //std::this_thread::sleep_for(3s);
    return 0;
}




// 1й поток
// void sequential(std::vector<int>& values) {
//     size_t count = 1000'000'000ull;
//     //std::vector<int> values(count);
//     std::generate(values.begin(), values.end(), []() { return rand() % 2;});
// }

// void parallel(std::vector<int>& values) {
//     size_t count = 1000'000'000ull;
//     size_t threadCount = 4;
//     size_t perThreadCount = count / threadCount;

//     //std::vector<int> values(count);//
//     std::vector<std::thread> threads;

//     for(int i = 0; i < threadCount; ++i) {
//         auto begin = values.begin() + i * perThreadCount;
//         auto end = values.begin() + (i + 1) * perThreadCount;
//         threads.emplace_back(
//             [&](){
//                 std::generate(begin, end, []() {return rand() % 2;});
//             }
//         );
//     }

//     for(auto& tr : threads)
//         tr.join();
// }



// template<typename TFunc, typename... TArgs>
// void execute(TFunc&& func, TArgs&&... args) {
//     const auto start = std::chrono::high_resolution_clock ::now();

//     func(std::forward<TArgs>(args)...);

//     const auto end = std::chrono::high_resolution_clock ::now();
//     const std::chrono::duration<double> diff = end - start;
//     std::cout << "durration = " << diff << std::endl;
// }


// void sequential_acc(const std::vector<int>& data) {
//     int result = 0;
//     for(int i = 0; i < data.size(); ++i)
//         result += data[i];

//     std::cout << result << std::endl;
// }

// std::mutex mutex;

// void parallel_acc(const std::vector<int>& data, size_t threadCount) {
//     int result = 0;
//     size_t perThreadCount = data.size() / threadCount;
//     std::vector<std::thread> threads;

//     std::vector<int> results(threadCount);
//     for(int t = 0; t < threadCount; ++t) {
//         threads.emplace_back([&](int thread){
//             int local_result = 0;
//             for(int i = thread * perThreadCount; i < (thread + 1) * perThreadCount; ++i)
//                 local_result += data[i]; /// result = result + data[i];

//             mutex.lock();
//             result += local_result;
//             mutex.unlock();

//         },t);
//     }
//     for(auto& tr : threads)
//         tr.join();


//     std::cout << result << std::endl;
// }

// int main(int, char**){
//     size_t count = 1000'000'000ull;
//     std::vector<int> values(count);

//     //std::cout << "sequential\n";
//     //execute(sequential, values);
//     ///std::cout << "parallel\n";
//     execute(parallel, values);

//     execute(sequential_acc, values);
//     execute(parallel_acc, values, 1);



//     // for(int i = 0; i < 4; ++i) {
//     //     std::thread tr{[](){
//     //         //int i = 0;
//     //         std::print("Hello from {0}\n", std::this_thread::get_id());
//     //         //std::cout << &i << std::endl;
//     //     }};
//     //     tr.detach();
//     //     //tr.join();

//     // }





//     //std:getchar();

// }
