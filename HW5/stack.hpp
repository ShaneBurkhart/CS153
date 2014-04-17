#include<iostream>
using namespace std;

template< typename T >
void Stack<T>::clear(){
  if(m_data != NULL)
    delete [] m_data;
  m_data = NULL;
  m_max = 0;
  m_top = -1;
}

template< typename T >
void Stack<T>::push(const T& x){
  if(m_top >= m_max - 1){
    m_max = m_max == 0 ? 1 :  m_max * 2;
    T* temp = new T[m_max];

    for(int i = 0 ; i < m_top + 1 ; i ++)
      temp[i] = m_data[i];

    if(m_data != NULL)
      delete [] m_data;

    m_data = temp;
  }
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

