#include "CAGE/Math.hpp"
#include <cmath>

float cage::Math::dist2d(float x1, float y1, float x2, float y2)
{
  float x = x1 - x2;
  float y = y1 - y2;

  return std::sqrt((x * x) - (y * y));
}
