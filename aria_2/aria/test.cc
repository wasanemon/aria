// #include "gflags/gflags.h"
#include "../include/zipf.hh"
#include "../include/random.hh"


#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>
#include <string>
#include <algorithm>
#include <utility> 
#include <barrier>
#include <array>
#include <map>
#include <cstdint>

#define PAGE_SIZE 4096
#define THREAD_NUM 64
#define TUPLE_NUM 1000000
#define MAX_OPE 500
#define SLEEP_POS 9
#define RW_RATE 5
#define EX_TIME 3
#define PRE_NUM 100000
#define SLEEP_TIME 100
#define SLEEP_TIME_INIT 2900 * 1000
#define SKEW_PAR 0.5
#define BACKOFF_TIME 0
#define LONG_WRITE_RATE 10
#define MAX_OPE_FOR_LONG 5000
#define RW_RATE_LONG 50

// DEFINE_uint64(tuple_num, 1000000, "Total number of records");








int main()
{
    Xoroshiro128Plus rnd;
    FastZipf zipf(&rnd, SKEW_PAR, TUPLE_NUM);

    std::array<uint64_t, 10> list_{}; // 乱数を格納する配列

    for (size_t i = 0; i < TUPLE_NUM; ++i) {
        uint64_t random_gen_key = zipf(); // Zipf分布に基づく乱数を生成
        list_[random_gen_key/100000] += 1;
    }
    for(int i = 0;i < 10;i++){
        cout << list_[i] << std::endl;
    }

    // 頻度の計算


    return 0;
}