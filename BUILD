cc_library(
    name = "sdet_test_lib",
    srcs = ["lib/libsdet_test.a"],
    hdrs = [
        "include/non_thread_safe_counter.h",
        "include/test_01.h",
        "include/test_02.h",
    ],
    includes = ["include"],
)

cc_binary(
    name = "benchmark_math_utilities",
    srcs = ["benchmark/benchmark_math_utilities.cpp"],
    deps = [
        ":sdet_test_lib",
        "@benchmark",
    ],
)

cc_test(
    name = "sdet_tests",
    srcs = [
        "test/counter_fixture.cpp",
        "test/math_utilities_fixture.cpp",
    ],
    copts = ["-fsanitize=undefined"],
    linkopts = ["-fsanitize=undefined"],
    deps = [
        ":sdet_test_lib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "thread_safety_extend_counter_test",
    srcs = [
        "test/thread_safety_extend_counter_fixture.cpp",
    ],
    copts = ["-fsanitize=thread"],
    linkopts = [
        "-pthread",
        "-fsanitize=thread",
    ],
    deps = [
        ":sdet_test_lib",
        "@googletest//:gtest_main",
    ],
)
