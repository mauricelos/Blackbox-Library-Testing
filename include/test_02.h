#ifndef TEST_02_H
#define TEST_02_H

namespace CounterExercise {
class Counter {
protected:
  int m_counter;

public:
  // Counter class that operates in the range from 0 to 1000000
  Counter();

  // Increment the counter and returns the current value
  int increment();

  // Decrement the counter and returns the current value
  int decrement();

  // Set the counter value in the operational range
  int set_counter(int value);
};

class ExtendCounter : public Counter {
public:
  ExtendCounter();

  // Get the counter value
  int get_counter();

  // Add a value to the current counter value
  void add(int value);

  // Subtract a value from the current counter value
  void subtract(int value);
};
}

#endif  // TEST_02_H
