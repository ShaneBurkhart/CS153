#include "../HW2/arraylist.h"

template <typename T>
class ArrayListQueue;

template <typename T>
class ArrayListQueue{
public
  void enqueue(T val);
  void dequeue();
  T& front();

private
  ArrayLIst<T>buffer;

  int m_end = 0;
  int m_front = 0;

}
