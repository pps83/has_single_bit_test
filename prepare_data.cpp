#include <vector>
#include <random>

struct TestData
{
    std::vector<uint16_t> v16;
    std::vector<uint32_t> v32;
    std::vector<uint64_t> v64;
};

extern TestData testDataRand, testDataZero, testDataOne;

// splitmix64 code https://prng.di.unimi.it/splitmix64.c
static uint64_t splitmix64_random_r(uint64_t& rnd)
{
    uint64_t z = (rnd += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}
// end of splitmix64

void InitData(uint64_t seed, size_t size)
{
    size = (size + 15) & (~15); // multiple of 16
    if (seed == 0)
    {
        std::random_device rnd;
        seed = ((1ULL * rnd()) << 32) ^ rnd();
    }
    seed |= 1;
    seed = splitmix64_random_r(seed);
    seed = splitmix64_random_r(seed);

    for (size_t i = 0; i < size; ++i)
    {
        testDataRand.v16.push_back((uint16_t)splitmix64_random_r(seed));
        testDataRand.v32.push_back((uint32_t)splitmix64_random_r(seed));
        testDataRand.v64.push_back((uint64_t)splitmix64_random_r(seed));

        testDataZero.v16.push_back(0);
        testDataZero.v32.push_back(0);
        testDataZero.v64.push_back(0);

        testDataOne.v16.push_back((uint16_t)(1 << (splitmix64_random_r(seed) % 16)));
        testDataOne.v32.push_back((uint32_t)(1 << (splitmix64_random_r(seed) % 32)));
        testDataOne.v64.push_back((uint64_t)(1ULL << (splitmix64_random_r(seed) % 64)));
    }
}
