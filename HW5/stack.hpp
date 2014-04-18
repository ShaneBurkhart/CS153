// Programmer: Shane Burkhart
// HW #: 5
//

#include<iostream>
using namespace std;

template< typename T >
void Stack<T>::clear(){
  m_top = 0;
}

template< typename T >
void Stack<T>::push(const T& x){
  if(m_top >= 100) throw Oops("The stack is full!");
  m_top += 1;
  m_data[m_top] = x;
}

template< typename T >
void Stack<T>::pop(){
  if(m_top < 0) throw Oops("The stack is empty!  You cannot pop.");
  m_top --;
}

template< typename T >
const T& Stack<T>::top() const throw ( Oops ){
  if(m_top < 0) throw Oops("The stack is empty! There is no top.");
  return m_data[m_top];
}

template< typename T >
bool Stack<T>::isEmpty() const{
  return m_top < 0;
}

