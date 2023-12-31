#include "s21_math.h"

// Функция вычисления значения asin через ряд Тейлора
long double asin_calc(double x) {
  long double result = x, asin = x, n = 1;

  // Цикл пока абсолютное значение asin не меньше S21_EPS
  while (s21_fabs(asin) > S21_EPS) {
    asin *= x * x * (2 * n - 1) * (2 * n - 1) * (2 * n);
    asin /= (2 * n + 1) * 4 * n * n;
    n++;
    result += asin;
  }
  return result;
}

// Функция вычисления значения asin
long double s21_asin(double x) {
  long double result = x;

  // Особые случаи для x > 1, x < -1 и NaN
  if (x > 1.0 || x < -1.0 || x != x)
    result = S21_NAN;
  else if (x == 1.0)
    result = S21_PI / 2;
  else if (x == -1.0)
    result = -S21_PI / 2;
  else
    result = asin_calc(x);

  return result;
}