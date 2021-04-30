#include <gtest/gtest.h>

#include "test_02.h"

namespace CounterExercise
{
namespace
{

class CounterFixture : public ::testing::Test
{
  protected:
    Counter counter_{};
    ExtendCounter extend_counter_{};

    virtual void SetUp() override
    {
        counter_.set_counter(0);
        extend_counter_.set_counter(0);
    }
};

TEST_F(CounterFixture, SetCounter_CheckCounterRange)
{
    EXPECT_EQ(counter_.set_counter(-1), 0);
    EXPECT_EQ(counter_.set_counter(1000001), 1000000);
    EXPECT_EQ(counter_.set_counter(std::numeric_limits<int>::max()), 1000000);
    EXPECT_EQ(counter_.set_counter(std::numeric_limits<int>::min()), 0);
    EXPECT_EQ(counter_.set_counter(42), 42);
    EXPECT_EQ(counter_.set_counter(999), 999);
}

TEST_F(CounterFixture, Increment_CheckCounterRange)
{
    EXPECT_EQ(counter_.increment(), 1);

    counter_.set_counter(1000000);

    EXPECT_EQ(counter_.increment(), 1000000);
}

TEST_F(CounterFixture, Decrement_CheckCounterRange)
{
    EXPECT_EQ(counter_.decrement(), 0);

    counter_.set_counter(1000000);

    EXPECT_EQ(counter_.decrement(), 999999);
}

TEST_F(CounterFixture, GetCounter_CheckValue)
{
    EXPECT_EQ(extend_counter_.get_counter(), 0);

    extend_counter_.set_counter(1000000);

    EXPECT_EQ(extend_counter_.get_counter(), 1000000);
}

TEST_F(CounterFixture, Add_CheckValue)
{
    extend_counter_.add(-10);
    EXPECT_EQ(extend_counter_.get_counter(), 0);

    extend_counter_.add(10);
    EXPECT_EQ(extend_counter_.get_counter(), 10);

    extend_counter_.add(10);
    EXPECT_EQ(extend_counter_.get_counter(), 20);

    extend_counter_.add(-10);
    EXPECT_EQ(extend_counter_.get_counter(), 10);

    extend_counter_.add(1000000);
    EXPECT_EQ(extend_counter_.get_counter(), 1000000);
}

TEST_F(CounterFixture, Subtract_CheckValue)
{
    extend_counter_.subtract(10);
    EXPECT_EQ(extend_counter_.get_counter(), 0);

    extend_counter_.subtract(-10);
    EXPECT_EQ(extend_counter_.get_counter(), 10);

    extend_counter_.set_counter(1000000);
    extend_counter_.subtract(10);
    EXPECT_EQ(extend_counter_.get_counter(), 999990);
}

}  // namespace
}  // namespace CounterExercise