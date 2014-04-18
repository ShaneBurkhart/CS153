// Programmer: Shane Burkhart
// HW #: 5
//

#ifndef STACK_H
#define STACK_H

#include "abstractstack.h"
#include<iostream>
using namespace std;

template< typename T >
class Stack: public AbstractStack<T>{
private:
  T m_data[100]; // Some large number
  int m_top;

public:
  Stack():AbstractStack<T>(), m_top(-1){
  }

  void clear();
  void push(const T& x);
  void pop();
  const T& top() const throw ( Oops );
  bool isEmpty() const;
};

#include "stack.hpp"

#endif
