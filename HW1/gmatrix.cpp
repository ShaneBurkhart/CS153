//////////////////////////////////////////////////////////////////
// Name: Shane Burkhart
// Class: CS155
// Section:
// Assignment:
// File: gmatrix.cpp

#include "gmatrix.h"
#include <iostream>
using namespace std;

GMatrix::GMatrix(int c, int r, int s, int d)
{
  m_cols = c;
  m_rows = r;
  m_data = new int*[m_cols];
  for(int x = 0 ; x < m_cols ; x ++)
  {
    m_data[x] = new int[m_rows];
    for(int y = 0 ; y < m_rows ; y ++)
      m_data[x][y] = s + d * (x + y);
  }
}


GMatrix::~GMatrix()
{
  for(int x = 0 ; x < m_cols ; x ++)
    delete [] m_data[x];
  delete [] m_data;
}

const GMatrix& GMatrix::operator=(const GMatrix& rhs)
{
  if(this != &rhs)
  {
    if((m_cols != 0 || m_rows != 0) && (m_cols != rhs.m_cols || m_rows != rhs.m_rows))
    {
      for(int x = 0 ; x < m_cols ; x ++)
        delete [] m_data[x];
      delete [] m_data;
    }

    m_cols = rhs.m_cols;
    m_rows = rhs.m_rows;

    // Copy and initialize new array
    m_data = new int*[m_cols];
    for(int x = 0 ; x < m_cols ; x ++)
    {
      m_data[x] = new int[m_rows];
      for(int y = 0 ; y < m_rows ; y ++)
        m_data[x][y] = rhs.m_data[x][y];
    }
  }
  return *this;
}

GMatrix::GMatrix(const GMatrix& rhs){
  m_cols = 0;
  m_rows = 0;
  *this = rhs;
}

std::ostream& operator<< (std::ostream& out, const GMatrix& gm)
{
  for(int x = 0 ; x < gm.m_cols ; x ++)
  {
    for(int y = 0 ; y < gm.m_rows ; y ++)
      out << gm.m_data[x][y] << "\t";
    out << endl;
  }
  return out;
}
