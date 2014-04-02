#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <iostream>
#include "abstractpackage.h"

using namespace std;


class Package: public AbstractPackage {

private:
  int m_package_number;

public:
  Package(string f, string t, int num)
    :AbstractPackage(f, t)
    ,m_package_number(num){}

  string getFrom() const;

  string getTo() const;

  ~Package(){

  }

  friend ostream& operator<< (ostream& out, const Package& p);

};

#endif

