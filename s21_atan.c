#include "s21_math.h"

// Вспомогательная функция для вычисления арктангенса с использованием ряда
// Тейлора
long double atan_calc(double x) {
  long double result = x, atan = x, n = 1;
  // Продолжайте вычисление до тех пор, пока значение atan не станет меньше
  // указанного допуска
  while (s21_fabs(atan) > S21_EPS) {
    atan = -1 * atan * x * x * (2 * n - 1) / (2 * n + 1);
    n += 1;
    result += atan;
  }
  return result;
}

// Возвращает арктангенс x
long double s21_atan(double x) {
  long double result = 0;
  if (x < 1.0 && x > -1.0) {
    // Используйте вспомогательную функцию для значений в диапазоне от -1 до 1
    result = atan_calc(x);
  } else if (x == 1.0) {
    result = S21_PI / 4;
  } else if (x == -1.0) {
    result = -S21_PI / 4;
  } else if (x == 0) {
    result = 0;
  } else if (x > 1.0) {
    // Используйте вспомогательную функцию для 1 / x и вычтите из PI / 2 для
    // значений, превышающих 1
    result = S21_PI / 2 - atan_calc(1 / x);
  } else if (x < -1.0) {
    // Используйте вспомогательную функцию для 1 / x и вычтите из -PI / 2 для
    // значений меньше -1
    result = -S21_PI / 2 - atan_calc(1 / x);
  } else if (S21_IS_NAN(x)) {
    result = S21_NAN;
  }
  return result;
}