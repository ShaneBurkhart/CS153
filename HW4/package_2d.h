#ifndef PACKAGE_2D_H
#define PACKAGE_2D_H

#include <string>
#include "package.h"

class Package2D: public Package {

private:
  float m_length;
  float m_width;

  const float AREA_RATE;

public:
  Package2D(string f, string t, int num, float length, float width)
    :Package(f, t, num)
    ,m_length(length)
    ,m_width(width)
    ,AREA_RATE(.05f){}

  float getCharge() const;

};

#endif
