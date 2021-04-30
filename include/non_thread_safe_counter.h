#ifndef NON_THREAD_SAFE_COUNTER_H
#define NON_THREAD_SAFE_COUNTER_H

namespace CounterExercise
{

class NonThreadSafeCounter
{
  protected:
    int m_counter;

  public:
    NonThreadSafeCounter() = default;

    int increment() { return ++m_counter; }
    int decrement() { return --m_counter; }
    int set_counter(int value) { return m_counter = value; }
};

class NonThreadSafeExtendCounter : public NonThreadSafeCounter
{
  public:
    NonThreadSafeExtendCounter() = default;

    int get_counter() { return m_counter; }
    void add(int value) { m_counter += value; }
    void subtract(int value) { m_counter -= value; }
};

}  // namespace CounterExercise

#endif  // NON_THREAD_SAFE_COUNTER_H