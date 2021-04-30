#include <memory>
#include <thread>

#include <gtest/gtest.h>

#include "non_thread_safe_counter.h"
#include "test_02.h"

namespace CounterExercise
{
namespace
{

TEST(NonThreadSafeExtendCounter, TestThreadSafety_WithThreadSanitizerChecker)
{
    const int expected_counter{1};
    testing::internal::CaptureStderr();
    std::shared_ptr<NonThreadSafeExtendCounter> extend_counter_ptr{std::make_shared<NonThreadSafeExtendCounter>()};

    std::thread thread_increment(&NonThreadSafeExtendCounter::increment, extend_counter_ptr);
    std::thread thread_decrement(&NonThreadSafeExtendCounter::decrement, extend_counter_ptr);
    std::thread thread_set_counter(&NonThreadSafeExtendCounter::set_counter, extend_counter_ptr, 1);
    std::thread thread_get_counter(&NonThreadSafeExtendCounter::get_counter, extend_counter_ptr);
    std::thread thread_add(&NonThreadSafeExtendCounter::add, extend_counter_ptr, 1);
    std::thread thread_subtract(&NonThreadSafeExtendCounter::subtract, extend_counter_ptr, 1);

    thread_increment.join();
    thread_decrement.join();
    thread_set_counter.join();
    thread_get_counter.join();
    thread_add.join();
    thread_subtract.join();

    std::string output{testing::internal::GetCapturedStderr()};

    EXPECT_EQ(extend_counter_ptr->get_counter(), expected_counter);
    EXPECT_TRUE(output.find("WARNING: ThreadSanitizer:") != std::string::npos);
}

TEST(ThreadSafeExtendCounter, TestThreadSafety_WithThreadSanitizerChecker)
{
    const int expected_counter{1};
    testing::internal::CaptureStderr();
    std::shared_ptr<ExtendCounter> extend_counter_ptr{std::make_shared<ExtendCounter>()};

    std::thread thread_increment(&ExtendCounter::increment, extend_counter_ptr);
    std::thread thread_decrement(&ExtendCounter::decrement, extend_counter_ptr);
    std::thread thread_set_counter(&ExtendCounter::set_counter, extend_counter_ptr, 1);
    std::thread thread_get_counter(&ExtendCounter::get_counter, extend_counter_ptr);
    std::thread thread_add(&ExtendCounter::add, extend_counter_ptr, 1);
    std::thread thread_subtract(&ExtendCounter::subtract, extend_counter_ptr, 1);

    thread_increment.join();
    thread_decrement.join();
    thread_set_counter.join();
    thread_get_counter.join();
    thread_add.join();
    thread_subtract.join();

    std::string output{testing::internal::GetCapturedStderr()};

    EXPECT_EQ(extend_counter_ptr->get_counter(), expected_counter);
    EXPECT_FALSE(output.find("WARNING: ThreadSanitizer:") != std::string::npos);
}

}  // namespace
}  // namespace CounterExercise