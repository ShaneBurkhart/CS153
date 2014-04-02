/* @file: linkedlist.hpp
 * Programmer: Shane Burkhart
 * Class: CS153 Secion: A
 * Homework: 3
 * Implementation of templated class LinkedList
 * Implementation of the List ADT
 * @C - Grand Emperor Lrrr of the planet Omicron Persei-8
 * @C - Galaxy Express Softworks
 *
 * Version 1.0
 */

#include<iostream>
using namespace std;


template <typename T>
// Purpose: performs a deep copy of the data from rhs into this linked list
// Parameters: rhs is linked list to be copied
// Returns: *this
// Postconditions: this list contains same data values (in the same order)
//     as are in rhs; any memory previously used by this list has been
//     deallocated.
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  if(m_next != NULL)
    clear();
  const LinkedList<T>* t = &rhs;
  LinkedList<T>* last = this;
  while(t != NULL)
  {
    last->m_data = t->m_data;
    if(t->m_next != NULL)
    {
      last->m_next = new LinkedList<T>();
      last = last->m_next;
    }
    t = t->m_next;
  }

  return *this;
}

template <typename T>
// Purpose: copy constructor
// Parameters: rhs is the LinkedList that is to be copied
// Postconditions: this list contains same data values (in same order)
//      as in rhs.
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
  m_next = NULL;
  *this = rhs;
}


// --------
// ---- Basic Accessor Operations ---
// --------

template <typename T>
// Purpose: accessor function for the current # data values in the list
// Returns: current size of the list
int LinkedList<T>::size() const
{
  int c = 0;
  LinkedList<T>* p = m_next;
  while(p != NULL)
  {
    c ++;
    p = p->m_next;
  }
  return c;
}

template <typename T>
// Purpose: determines whether the list is empty
// Returns: 'true' if list is empty; 'false' otherwise
bool LinkedList<T>::isEmpty() const
{
  return m_next == NULL;
}

template <typename T>
// Purpose: Get a pointer to the first element node
// Returns: pointer to the first node in the list;
//     returns NULL if the list is empty
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(isEmpty())
  {
    cout << "PANIC in LinkedList.getFirstPtr() - empty list" << endl;
    return NULL;
  }
  return this;
}

template <typename T>
// Purpose: accessor function for last element node
// Returns: pointer to the last element's node in the list;
//     returns NULL if list is empty
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  if(isEmpty())
  {
    cout << "PANIC in LinkedList.getLastPtr() - empty list" << endl;
    return NULL;
  }
  LinkedList<T>* r = m_next;
  LinkedList<T>* p = this;
  while(r->m_next != NULL)
  {
    p = r;
    r = r->m_next;
  }
  return p;
}

template <typename T>
// Purpose: accessor function for a node in the list
// Returns: pointer to the node at the i'th position in the list;
//     returns NULL if no such element exists.
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  if(isEmpty())
  {
    cout << "PANIC in LinkedList.getAtPtr() - empty list" << endl;
    return NULL;
  }
  LinkedList<T>* r = m_next;
  LinkedList<T>* p = this;
  while(r->m_next != NULL && i > 0)
  {
    p = r;
    r = r->m_next;
    i --;
  }
  if(i)
  {
    cout << "PANIC in LinkedList.getAtPtr() - invalid index" << endl;
    return NULL;
  }
  return p;
}



// --------
// ---- Basic Mutator Operations ---
// --------

template <typename T>
// Purpose: effectively "empties" the list
// Postconditions: all dynamically allocated memory for nodes deallocated
void LinkedList<T>::clear()
{
  LinkedList<T>* f = m_next;
  LinkedList<T>* t;
  while(f != NULL)
  {
    t = f->m_next;
    delete f;
    f = t;
  }
  m_next = NULL;
}

template <typename T>
// Purpose: puts the data x in the front of the list
// Parameters: x is data value to inserted
// Postconditions: x is the first element of the list
void LinkedList<T>::insert_front(const T& x)
{
  m_next = new LinkedList<T>(m_data, m_next);
  m_data = x;
}

template <typename T>
// Purpose: puts the data value x at the position pointed by pos
// Parameters: x is data value to inserted
//     pos pointer to the position to insert x at.
// Preconditions: pos is a pointer in this list.
// Postconditions: x is inserted at the position pointed by pos
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  pos->m_next = new LinkedList<T>(pos->m_data, pos->m_next);
  pos->m_data = x;
}

template <typename T>
// Purpose: removed the element in the position pointed by pos
// Parameters: pos pointer to the position to remove.
// Preconditions: pos is a pointer in this list.
// Postconditions: position pointed by pos is removed from the list
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  if(pos->m_next == NULL) return; // Already deleted

  LinkedList<T>* temp = pos->m_next->m_next;
  pos->m_data = pos->m_next->m_data;
  pos->m_next->m_next = NULL; // so we don't recursively clear the rest
  delete pos->m_next;
  pos->m_next = temp;
}


// --------
// ---- Complex Operations ---
// --------

template <typename T>
// Purpose: determines whether this list is identical to rhs list in
// terms of data values and their order in the list
// Parameters: rhs is list to be compared to this list
// Returns: true if lists are identical; otherwise, false
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  const LinkedList<T>* t = this;
  const LinkedList<T>* p = &rhs;
  while(t != NULL && p != NULL)
  {
    // Make sure you aren't in sentinel
    if(t->m_next != NULL && p->m_next != NULL && t->m_data != p->m_data)
      return false;
    t = t->m_next;
    p = p->m_next;
  }
  if(t != p) return false; // Check if both are NULL
  return true;
}

template <typename T>
// Purpose: determines whether x is in the list
// Parameters: x is data value to be found
// Returns: a pointer to the position of x in the list;
//     otherwise, NULL
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList<T>* p = this;
  while(p->m_next != NULL)
  {
    if(p->m_data == x) return p;
    p = p->m_next;
  }
  return NULL;
}

template <typename T>
// Purpose: reverses the elements from the list
// Postconditions: the list is now in reverse order
void LinkedList<T>::reverse()
{
  if(isEmpty() || m_next->m_next == NULL) return; // Empty or one item return

  LinkedList<T>* run = m_next; // Hold the next data
  m_next = new LinkedList<T>(); // Create new sentinel.
  while(run->m_next != NULL)
  {
    LinkedList<T>* next_node = run->m_next; // Save node

    T next_value = run->m_data; // Get value to store in head
    run->m_next = m_next; // Make the node the one being insterted. Recycling object
    run->m_data = m_data; // Make the node the one being insterted. Recycling object
    m_next = run; // Add node after head.
    m_data = next_value; // Put value in head.

    run = next_node; // Increment to saved node.
  }
  delete run; // Delete old sentinel
}

template <typename T>
// Purpose: appends two lists
// Parameters: xlist, a list to append to the end of 'this' list
// Postconditions: elements of alist are appended to 'this' list
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  LinkedList<T>* last = getLastPtr();
  if(last == NULL)
    last = this;
  else
    last = last->m_next;
  const LinkedList<T>* t = &xlist;
  while(t->m_next != NULL)
  {
    last->m_data = t->m_data;
    last->m_next = new LinkedList<T>();
    last = last->m_next;
    t = t->m_next;
  }
}

