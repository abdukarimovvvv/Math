#include "s21_math.h"

long double s21_cos(double x) {
  // Приведение угла x к диапазону [0, 2π)
  x = s21_fmod(x, 2 * S21_PI);
  // Инициализация результата и временной переменной
  long double result = 0;
  long double temp = 1;
  // Счетчик цикла
  unsigned flag = 0;
  // Расчет суммы ряда Тейлора
  while (flag < 1000) {
    result += temp;
    flag += 2;
    temp *= -(x * x) / ((flag - 1) * flag);
  }
  return result;
}