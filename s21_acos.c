#include "s21_math.h"

long double s21_acos(double x) {
  /* Если x выходит за допустимые границы, возвращаем NaN */
  if (x > 1.0 || x < -1.0) return S21_NAN;

  /* Если x равен 1, то acos(x) = 0 */
  if (x == 1.0) return 0.0;

  /* Если x равен -1, то acos(x) = pi */
  if (x == -1.0) return S21_PI;

  /* Иначе используем теорему acos(x) = pi/2 - asin(x) */
  return S21_PI / 2 - s21_asin(x);
}