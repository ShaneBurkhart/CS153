#ifndef PACKAGE_4D_H
#define PACKAGE_4D_H

#include <string>
#include "package.h"

class Package4D: public Package {

private:
  float m_length;
  float m_width;
  float m_height;
  float m_fourth;
  float m_weight;

  const float HYPER_RATE;
  const float WEIGHT_RATE;
  const float EXTRA_DIM_RATE;

public:
  Package4D(string f, string t, int num, float length, float width, float height, float fourth, float weight)
    :Package(f, t, num)
    ,m_length(length)
    ,m_width(width)
    ,m_height(height)
    ,m_fourth(fourth)
    ,m_weight(weight)
    ,HYPER_RATE(.01f)
    ,WEIGHT_RATE(3.14f)
    ,EXTRA_DIM_RATE(42.42f){}

  float getCharge() const;

};

#endif
