#include "package_2d.h"

float Package2D::getCharge() const {
  return m_length * m_width * AREA_RATE;
}
