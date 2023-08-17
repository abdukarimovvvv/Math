#include "s21_math.h"

long double s21_sqrt(double x) {
  // возвращает показатель степени 0,5 * натуральный логарифм x
  return s21_exp(0.5 * s21_log(x));
}
