#include <string>
#include <iostream>
#include "package.h"

string Package::getFrom() const {
  return m_from;
}

string Package::getTo() const {
  return m_to;
}

ostream& operator<< (ostream& out, const Package& p){
  out << "#" << p.m_package_number << " From " << p.m_from << " to " << p.m_to << endl;
  out << "$" << p.getCharge() << endl;
  return out;
}
