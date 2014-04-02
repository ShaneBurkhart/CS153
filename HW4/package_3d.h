#ifndef PACKAGE_3D_H
#define PACKAGE_3D_H

#include <string>
#include "package.h"

class Package3D: public Package {

private:
  float m_length;
  float m_width;
  float m_height;
  float m_weight;

  const float VOLUME_RATE;
  const float WEIGHT_RATE;

public:
  Package3D(string f, string t, int num, float length, float width, float height, float weight)
    :Package(f, t, num)
    ,m_length(length)
    ,m_width(width)
    ,m_height(height)
    ,m_weight(weight)
    ,VOLUME_RATE(.02f)
    ,WEIGHT_RATE(2.71f){}

  float getCharge() const;

};

#endif
