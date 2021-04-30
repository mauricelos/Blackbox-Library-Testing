#include <limits>
#include <memory>

#include <gtest/gtest.h>

#include "test_01.h"

namespace MathUtilitiesExercise
{

std::ostream& operator<<(std::ostream& os, std::shared_ptr<MathUtilities> math_util_ptr)
{
    auto& math_util_type = typeid(*math_util_ptr.get());
    std::string type_string{};

    if (math_util_type == typeid(MathUtilitiesImp1))
    {
        type_string = "MathUtilitiesImp1";
    }
    else if (math_util_type == typeid(MathUtilitiesImp2))
    {
        type_string = "MathUtilitiesImp2";
    }
    else
    {
        type_string = "MathUtilities";
    }

    return os << type_string;
}

namespace
{

class ParameterizedMathUtilitiesFixtureCalculateFactorial
    : public ::testing::Test,
      public ::testing::WithParamInterface<std::tuple<std::shared_ptr<MathUtilities>, std::pair<long, long>>>
{
};
class ParameterizedMathUtilitiesFixtureCalculateFactorialSpecialCases
    : public ::testing::Test,
      public ::testing::WithParamInterface<std::shared_ptr<MathUtilities>>
{
};
class ParameterizedMathUtilitiesFixturePrimes
    : public ::testing::Test,
      public ::testing::WithParamInterface<std::tuple<std::shared_ptr<MathUtilities>, int>>
{
};
class ParameterizedMathUtilitiesFixtureNoPrimes
    : public ::testing::Test,
      public ::testing::WithParamInterface<std::tuple<std::shared_ptr<MathUtilities>, int>>
{
};

// clang-format off
const std::vector<std::pair<long, long>> factorial_pairs_{
    {1, 1}, {2, 2}, {3, 6}, {4, 24}, {5, 120}, {6, 720}, {7, 5040}, {8, 40320}, {9, 362880}, {10, 3628800},
    {11, 39916800}, {12, 479001600}, {13, 6227020800}, {14, 87178291200}, {15, 1307674368000},
    {16, 20922789888000}, {17, 355687428096000}, {18, 6402373705728000}, {19, 121645100408832000},
    {20, 2432902008176640000}, {-1, 1}, {-2, 1}, {-3, 1}, {-4, 1}, {-5, 1}, {-6, 1}, {-7, 1}, {-8, 1}, 
    {-9, 1}, {-10, 1}, {-11, 1}, {-12, 1}, {-13, 1}, {-14, 1}, {-15, 1}, {-16, 1}, {-17, 1}, {-18, 1},
    {-19, 1}, {-20, 1}, {-21, 1}, {std::numeric_limits<long>::min(), 1}};

const std::vector<int> prime_numbers_{
    std::numeric_limits<int>::min() + 1, -11, -7, -3, -2, 2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
    41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 281, 409, 999331, 27644437, 433494437, 1073676287,
    std::numeric_limits<int>::max()};

const std::vector<int> not_prime_numbers_{
    std::numeric_limits<int>::min(), -12, -8, -4, -1, 0,  1,  4,  6,  8,  12, 14, 18, 20, 27, 30, 32, 36,  40, 44,
    48, 54, 60, 62, 68, 72, 74, 80, 84, 90, 99, 282, 411, 999333, 27644439, 433494439, 1073676288, 
    std::numeric_limits<int>::max() - 1};
// clang-format on

TEST_P(ParameterizedMathUtilitiesFixtureCalculateFactorial, CalculateFactorial_ForNormalValues)
{
    EXPECT_EQ(std::get<0>(GetParam())->calculate_factorial(std::get<1>(GetParam()).first),
              std::get<1>(GetParam()).second);
}

INSTANTIATE_TEST_CASE_P(CalculateFactorial,
                        ParameterizedMathUtilitiesFixtureCalculateFactorial,
                        ::testing::Combine(::testing::Values(std::make_shared<MathUtilitiesImp1>(),
                                                             std::make_shared<MathUtilitiesImp2>()),
                                           ::testing::ValuesIn(factorial_pairs_)));

TEST_P(ParameterizedMathUtilitiesFixtureCalculateFactorialSpecialCases, DISABLED_CalculateFactorial_ForMaxLongValue)
{
    const long input_value_max{std::numeric_limits<long>::max()};
    const long expected_value_max{0};

    // Breaks the entire test, stack overflow and segmentation fault
    EXPECT_EQ(GetParam()->calculate_factorial(input_value_max), expected_value_max);
}

TEST_P(ParameterizedMathUtilitiesFixtureCalculateFactorialSpecialCases, CalculateFactorial_ForOverflowValue)
{
    testing::internal::CaptureStderr();
    long input_value{500};
    long expected_value{0};

    EXPECT_EQ(GetParam()->calculate_factorial(input_value), expected_value);

    std::string output{testing::internal::GetCapturedStderr()};

    EXPECT_FALSE(output.find("runtime error: signed integer overflow:") != std::string::npos);
}

INSTANTIATE_TEST_CASE_P(CalculateFactorial,
                        ParameterizedMathUtilitiesFixtureCalculateFactorialSpecialCases,
                        ::testing::Values(std::make_shared<MathUtilitiesImp1>(),
                                          std::make_shared<MathUtilitiesImp2>()));

TEST_P(ParameterizedMathUtilitiesFixturePrimes, IsPrimeNumber_ForValidPrimeNumbers)
{
    EXPECT_TRUE(std::get<0>(GetParam())->is_prime_number(std::get<1>(GetParam())));
}

INSTANTIATE_TEST_CASE_P(IsPrimeNumber,
                        ParameterizedMathUtilitiesFixturePrimes,
                        ::testing::Combine(::testing::Values(std::make_shared<MathUtilitiesImp1>(),
                                                             std::make_shared<MathUtilitiesImp2>()),
                                           ::testing::ValuesIn(prime_numbers_)));

TEST_P(ParameterizedMathUtilitiesFixtureNoPrimes, IsPrimeNumber_ForInvalidPrimeNumbers)
{
    EXPECT_FALSE(std::get<0>(GetParam())->is_prime_number(std::get<1>(GetParam())));
}

INSTANTIATE_TEST_CASE_P(IsPrimeNumber,
                        ParameterizedMathUtilitiesFixtureNoPrimes,
                        ::testing::Combine(::testing::Values(std::make_shared<MathUtilitiesImp1>(),
                                                             std::make_shared<MathUtilitiesImp2>()),
                                           ::testing::ValuesIn(not_prime_numbers_)));

}  // namespace
}  // namespace MathUtilitiesExercise