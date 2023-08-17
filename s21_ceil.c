#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  // Если x является NaN или Inf, возвращаем x
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    res = x;
  } else {
    // Если x >= 0, рассчитываем верхнюю границу
    if (x >= 0) {
      long double condition = x - (long long int)x;
      // Если остаток меньше некоторой маленькой величины, результат равен x
      if (condition <= 0.00000001) {
        res = x;
      } else {
        res = (long long int)x + 1;
      }
    } else {
      // Если x < 0, результат равен (long long int)x
      res = (long long int)x;
    }
  }
  return res;
}