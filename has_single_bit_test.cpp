#include "has_single_bit.h"
#include <benchmark/benchmark.h>
#include <vector>

struct TestData
{
    std::vector<uint16_t> v16;
    std::vector<uint32_t> v32;
    std::vector<uint64_t> v64;
};

TestData testDataRand, testDataZero;
void InitData(uint64_t seed, size_t size);

#if 1
#define TEST_FUNC(data, func, prefix)             \
static void prefix##func(benchmark::State& state) \
{                                                 \
    const auto& v = data;                         \
    int ret = 0;                                  \
    for (auto _ : state)                          \
    {                                             \
        benchmark::DoNotOptimize(v);              \
        for (size_t i = 0; i < v.size(); i += 4)  \
        {                                         \
            bool b0 = func(v[i + 0]);             \
            bool b1 = func(v[i + 1]);             \
            bool b2 = func(v[i + 2]);             \
            bool b3 = func(v[i + 3]);             \
            ret += b0 ^ b1 ^ b2 ^ b3;             \
        }                                         \
    }                                             \
    benchmark::DoNotOptimize(ret);                \
}                                                 \
BENCHMARK(prefix##func)
#else
#define TEST_FUNC(data, func, prefix)             \
static void prefix##func(benchmark::State& state) \
{                                                 \
    const auto& v = data;                         \
    int ret = 0;                                  \
    for (auto _ : state)                          \
    {                                             \
        benchmark::DoNotOptimize(v);              \
        for (size_t i = 0; i < v.size(); i += 1)  \
        {                                         \
            if (func(v[i + 0]))                   \
                ret++;                            \
        }                                         \
    }                                             \
    benchmark::DoNotOptimize(ret);                \
}                                                 \
BENCHMARK(prefix##func)
#endif

#define TEST(type, size) \
TEST_FUNC(testData##type.v##size, has_single_bit_old, type##size##_); \
TEST_FUNC(testData##type.v##size, has_single_bit_std, type##size##_); \
TEST_FUNC(testData##type.v##size, has_single_bit_new, type##size##_)

TEST(Rand, 16);
TEST(Rand, 32);
TEST(Rand, 64);

TEST(Zero, 16);
TEST(Zero, 32);
TEST(Zero, 64);

int main(int argc, char** argv)
{
    char arg0_default[] = "benchmark";
    char* args_default = arg0_default;
    if (!argv)
    {
        argc = 1;
        argv = &args_default;
    }

    InitData(1, 256);

    benchmark::Initialize(&argc, argv);
    if (::benchmark::ReportUnrecognizedArguments(argc, argv))
        return 1;
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}
