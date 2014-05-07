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
  T* m_data; // Some large number
  int m_top;
  int m_max;

public:
  Stack():AbstractStack<T>(), m_max(0), m_top(-1){
    m_data = NULL;
  }

  Stack(const Stack<T>& cpy){
    m_data = NULL;
    m_max = 0;
    m_top = -1;
    *this = cpy;
  }

  ~Stack(){
    clear();
  }

  Stack<T>& operator=(const Stack<T>& rhs){
    if(&rhs != this){
      clear();
      for(int i = 0 ; i < rhs.m_top + 1 ; i ++)
        push(rhs.m_data[i]);
    }
    return *this;
  }

  void clear();
  void push(const T& x);
  void pop();
  const T& top() const throw ( Oops );
  bool isEmpty() const;
};

#include "stack.hpp"

#endif
