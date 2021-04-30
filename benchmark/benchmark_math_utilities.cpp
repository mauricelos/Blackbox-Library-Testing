#include <limits>

#include <benchmark/benchmark.h>

#include "test_01.h"

static MathUtilitiesExercise::MathUtilitiesImp1 math_util_imp1_{};
static MathUtilitiesExercise::MathUtilitiesImp2 math_util_imp2_{};

static void BenchmarkIsPrimeNumberImp1(benchmark::State& state)
{
    for (auto _ : state)
    {
        math_util_imp1_.is_prime_number(std::numeric_limits<int>::max());
    }
}

static void BenchmarkIsPrimeNumberImp2(benchmark::State& state)
{
    for (auto _ : state)
    {
        math_util_imp2_.is_prime_number(std::numeric_limits<int>::max());
    }
}

static void BenchmarkCalculateFactorialImp1(benchmark::State& state)
{
    for (auto _ : state)
    {
        math_util_imp1_.calculate_factorial(20);
    }
}

static void BenchmarkCalculateFactorialImp2(benchmark::State& state)
{
    for (auto _ : state)
    {
        math_util_imp2_.calculate_factorial(20);
    }
}

BENCHMARK(BenchmarkIsPrimeNumberImp1);
BENCHMARK(BenchmarkIsPrimeNumberImp2);
BENCHMARK(BenchmarkCalculateFactorialImp1);
BENCHMARK(BenchmarkCalculateFactorialImp2);
BENCHMARK_MAIN();
