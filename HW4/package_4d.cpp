#include "package_4d.h"

float Package4D::getCharge() const {
  return m_length * m_width * m_height * m_fourth * HYPER_RATE + m_weight * WEIGHT_RATE + EXTRA_DIM_RATE;
}

