### Take-home test
#### Instructions
1. This test is not time-limited, feel free to take as much time as needed
2. On average, this test should take around 2-3 hours if you have previous experience with CMake and Google Test
3. The required result is to develop some unit tests to test the library `libsdet_test.a`
4. It's recommended to use Google Test as it's the framework used in this company but feel free to use any other frameworks
5. `libsdet_test.a` is found in the directory `lib` and the corresponding headers `test_01.h
` & `test_02.h` are found in the directory `include`
6. This package includes Google Test suite prebuilt and installed into the directories `lib` and `include`
```
.
├── include
│   ├── gmock
│   ├── gtest
│   ├── test_01.h
│   └── test_02.h
├── lib
│   ├── cmake
│   ├── libgmock.a
│   ├── libgmock_main.a
│   ├── libgtest.a
│   ├── libgtest_main.a
│   ├── libsdet_test.a
│   └── pkgconfig
└── README.md
```

#### Requirments
1. In `test_01.h`, there are two different implementations for the interface `MathUtilities`, it's required to:
    1. Test the output of the two implementations under different conditions
    2. Find out which implementation is more optimized for performance
2. In `test_02.h`
    1. Test the class `Counter`
    2. Test if `ExtendCounter` is thread-safe


#### Hints
1. The package has been built on `Ubuntu 18.04` using:
    1. CMake version 3.10.2
    2. GCC (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
2. You can start by writing a simple CMakeLists that includes the `include` directory and links the libraries `sdet_test` `gtest` & `gtest_main` into your unit test executable and start developing your test right away
3. There are many flaws in the library implementation, find as many as you can
