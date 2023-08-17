#include "s21_math.h"

long double s21_fmod(double x, double y) {
  // Инициализируем переменную res
  long double res;

  // Если y равен 0, то res является NaN
  if (y == 0) res = S21_NAN;

  // Иначе, вычисляем res
  else
    res = x - ((x / y) < 0 ? s21_ceil(x / y) : s21_floor(x / y)) * y;

  // Возвращаем результат
  return res;
}