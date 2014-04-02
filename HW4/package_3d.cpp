#include "package_3d.h"

float Package3D::getCharge() const {
  return m_length * m_width * m_height * VOLUME_RATE + m_weight * WEIGHT_RATE;
}
