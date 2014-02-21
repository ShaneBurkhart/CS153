/* @file: arraylist.hpp
 * Programmer: Shane Burkhart
 * Class: CS153 Secion: A
 * Implementation of templated class ArrayList
 * Implementation of the List ADT
 * @C - Grand Emperor Lrrr of the planet Omicron Persei-8
 * @C - Galaxy Express Softworks
 *
 * Version 1.0
 */

#include<iostream>
using namespace std;

template <typename T>
// Purpose: Destructor
// Postconditions: current size and maximum size set to 0,
//                 data deallocated and set to NULL
ArrayList<T>::~ArrayList()
{
  if(m_data != NULL)
    delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}


template <typename T>
// Purpose: Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
// Parameters: rhs, ArrayList to be copied
// Returns: *this
// Postconditions: rhs == this
ArrayList<T>& ArrayList<T>::operator= (const ArrayList<T>& rhs)
{
  if(&rhs != this)
  {
    clear();
    for(int i = 0 ; i < rhs.m_size ; i ++)
      insert_back(rhs.m_data[i]);
  }
  return *this;
}


template <typename T>
// Purpose: Copy Constructor
// Parameters: cpy = ArrayList to be copied
// Postconditions: current size, maximum size, and elements same as cpy
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_data = NULL;
  *this = cpy;
}


template <typename T>
// Purpose: Accessor function for the number of elements in the list
// Returns: number of elements in the list
int ArrayList<T>::size() const
{
  return m_size;
}


template <typename T>
// Purpose: Accessor function for the first element of the list
// Returns: the first element in the list
const T& ArrayList<T>::first() const
{
  if(m_size == 0)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .first() array empty" << endl;
    return m_errobj;
  }
  return m_data[0];
}


template <typename T>
// Purpose: return a read-and-write reference to the element at
// the specified position
// Parameters: i is 0-based index into the ArrayList
// Returns: the element at position i in the ArrayList
T& ArrayList<T>::operator[](int i){
  if(m_size == 0)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! [] array empty" << endl;
    return m_errobj;
  }

  if(i < 0 || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! [] index out of range" << endl;
    return m_errobj;
  }

  return m_data[i];
}


template <typename T>
// Purpose: return a read-only reference to the element at
// the specified position
// Parameters: i is 0-based index into the ArrayList
// Returns: the element at position i in the ArrayList
const T& ArrayList<T>::operator[](int i) const
{
  if(m_size == 0)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! [] array empty" << endl;
    return m_errobj;
  }

  if(i < 0 || i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! [] index out of range" << endl;
    return m_errobj;
  }

  return m_data[i];
}


template <typename T>
// Purpose: finds an element in the ArrayList
// Parameters: x is value to be found in the ArrayList
// Returns: the position of the first occurrance of x in the list,
//          or -1  if x is not found.
int ArrayList<T>::find(const T& x)
{
  if(m_data == NULL)
    return -1;
  for(int i = 0 ; i < m_size ; i ++)
    if(m_data[i] == x) return i;
  return -1;
}


template <typename T>
// Purpose: Clears the ArrayList
// Postconditions: current size and maximum size set to 0,
//                 elements are deallocated and data is set to NULL
void ArrayList<T>::clear()
{
  if(m_data != NULL)
    delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}


template <typename T>
// Purpose: puts the value x at the end of an ArrayList
// Parameters: x is value to be added to ArrayList
// Postconditions: current size is incremented by 1
//     If max size is reached, a new array of size max*2 is allocated
//     and data is copied to it.
void ArrayList<T>::insert_back(const T& x)
{
  insert(x, m_size);
}


template <typename T>
// Purpose: puts the value x at the position i in the  ArrayList
// Parameters: x is value to be added to ArrayList
//             i is the position to insert x at
// Postconditions: current size is incremented by 1
//     If max size is reached, a new array of size max*2 is allocated
//     and data is copied to it.
void ArrayList<T>::insert(const T& x, int i)
{
  if(m_data == NULL) // The array has not been allocated so we need to make it.
  {
    m_max = 2; // We make it size 2 so the condition below does not pass
    m_data = new T[m_max];
  }

  if(i < 0 || i > m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .insert() index out of range" << endl;
    return;
  }

  if(m_size + 1 >= m_max) // Need new array
  {
    m_max *= 2;
    T* temp = new T[m_max];
    for(int i = 0 ; i < m_size ; i ++)
      temp[i] = m_data[i];
    delete [] m_data;
    m_data = temp;
  }


  T next = m_data[i];
  T t;
  m_data[i] = x;
  for(int j = i + 1; j < m_size ; j ++)
  {
    t = m_data[j];
    m_data[j] = next;
    next = t;
  }
  if(i < m_size)
    m_data[m_size] = next;
  m_size ++;

}


template <typename T>
// Purpose: Removes the element at index i in the array
// Parameters: i, the index of the element to remove
// Postconditions: if the size of the list is greater than 0
//     size is decremented by one.
//     if the size of the list less than 1/4 the max size, a new array
//     of size max/2 is allocated, and data is copied to it.
void ArrayList<T>::remove(int i)
{
  if(i >= m_size || i < 0) // Is it in bounds
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .remove() index out of range" << endl;
    return;
  }

  if(m_size == 0)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .remove() array empty" << endl;
    return;
  }

  T removed = m_data[i];
  for(int j = i + 1 ; j < m_size ; j ++)
    m_data[j - 1] = m_data[j];
  m_data[m_size - 1] = removed;

  m_size --;

  if(m_size < m_max / 4)
  {
    m_max /= 2;
    T* t = new T[m_max];
    for(int j = 0 ; j < m_size ; j ++)
      t[j] = m_data[j];
    if(m_data != NULL)
      delete [] m_data;
    m_data = t;
  }
}


template <typename T>
// Purpose: swaps two elements of the array
// Parameters: i, k, two positions on the Arraylist
// Postconditions: the elements at positions i and k swap positions
void ArrayList<T>::swap(int i, int k)
{
  if(i >= m_size || k >= m_size) // Cant be out of bounds
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .swap() index out of range" << endl;
    return;
  }

  T temp = m_data[i];
  m_data[i] = m_data[k];
  m_data[k] = temp;
}


template <typename T>
// Purpose: appends two lists
// Parameters: alist, a list to appended to the end of 'this' list
// Postconditions: current size is incremented by size of alist
//     the elements of alist are appended to the elements of 'this'
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(m_data == NULL)
  {
    *this = alist;
  }
  else
  {
    for(int i = 0 ; i < alist.m_size ; i ++)
      insert_back(alist.m_data[i]);
  }
}


template <typename T>
// Purpose: removes duplicates from an Arraylist
// Postconditions: all duplicate elements are removed from the list.
void ArrayList<T>::purge()
{
  if(m_data == NULL)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!! .purge() data is NULL" << endl;
    return;
  }

  for(int i = 0 ; i < m_size ; i ++)
  {
    for(int j = i + 1 ; j < m_size ; j ++)
      if(m_data[i] == m_data[j])
        remove(j);
  }

}

