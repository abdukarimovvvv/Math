#include "s21_math.h"

long double s21_floor(double x) {
  // Инициализируем переменную res с значением 0
  long double res = 0;

  // Если x является NaN или бесконечностью, возвращаем x
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    res = x;

    // Иначе, если x >= 0, возвращаем целое число
  } else {
    if (x >= 0) {
      res = (long long int)x;

      // Иначе, если condition >= -0.00000001, возвращаем x
    } else {
      long double condition = x - (long long int)x;
      if (condition >= -0.00000001) {
        res = x;

        // Иначе, возвращаем (long long int)x - 1
      } else {
        res = (long long int)x - 1;
      }
    }
  }

  // Возвращаем результат
  return res;
}