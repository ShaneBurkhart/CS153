////////////////////////////////////////////////////////////////////
// THIS IS NOT MEANT TO COMPILE
// ///////////////////////////////////////////////////////////


#include "queue.h"

////////////////////////////////////////////////////////////////////
//  ArrayList Implementation
// ///////////////////////////////////////////////////////////

template <typename T>
void ArrayListQueue<T>::enqueue(const T& val){
  int t = (m_end + 1) % buffer.size();
  if(buffer[t] != NULL && t != m_front){
    m_end = t;
    buffer[m_end] = val;
  }else{
    cout << "The Queue is full!";
  }
}

template <typename T>
void ArrayListQueue<T>::dequeue(){
  int t = (m_front + 1) % buffer.size();
  if(m_end != m_front){
    buffer[m_front] = NULL;
    m_front = t;
  }else{
    cout << "The Queue is empty!";
  }
}

template <typename T>
T& ArrayListQueue<T>::front(){
  if(m_front != m_end)
    return buffer[m_front];
  else{
    cout << "Empty list" << endl;
    return NULL;
  }
}

////////////////////////////////////////////////////////////////////
//  LinkedList Implementation
// ///////////////////////////////////////////////////////////

template <typename T>
void ArrayListQueue<T>::enqueue(const T& val){
  if(m_back == NULL){
    m_back = new LinkedList<T>(val, NULL);
    m_back->m_next = m_back;
  }else{
    m_back->m_next = new LinkedList<T>(val, m_back->m_next);
    m_back = m_back->m_next;
  }
}

template <typename T>
void ArrayListQueue<T>::dequeue(){
  if(m_back != NULL){
    if(m_back == m_back->m_next){
      delete m_back;
      m_back == NULL;
    }else{
      LinkedList<T>* t = m_back->m_next;
      m_back->m_next = m_back->m_next->m_next;
      delete t;
    }
  }else{
    cout << "Queue empty" << endl;
  }
}

template <typename T>
T& ArrayListQueue<T>::front(){
  if(m_back != NULL){
    return m_back->m_next;
  }else{
    cout << "Empty queue" << endl;
    return NULL
  }
}
