#ifndef TEST_01_H
#define TEST_01_H

namespace MathUtilitiesExercise {
class MathUtilities {
public:
  // Return the factorial of n (n!)
  // For negative n, n! is defined to be 1.
  virtual long calculate_factorial(long n) = 0;

  // Return true only if n is a prime number
  virtual bool is_prime_number(int n) = 0;
};

class MathUtilitiesImp1 : public MathUtilities {
public:
  virtual long calculate_factorial(long n);

  virtual bool is_prime_number(int n);
};

class MathUtilitiesImp2 : public MathUtilities {
public:
  virtual long calculate_factorial(long n);

  virtual bool is_prime_number(int n);
};
}

#endif  // TEST_01_H
