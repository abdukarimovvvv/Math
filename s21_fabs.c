#include "s21_math.h"

long double s21_fabs(double x) {
  // Возвращаем абсолютное значение x
  return x >= 0 ? x : -x;
}
