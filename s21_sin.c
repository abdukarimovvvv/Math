#include "s21_math.h"

long double s21_sin(double x) {
  // уменьшите угол до диапазона [0, 2 * pi)
  x = s21_fmod(x, 2 * S21_PI);

  // инициализировать результат и временную переменную, используемую в цикле
  long double result = 0;
  long double temp = x;

  // переменная счетчика для цикла
  unsigned flag = 1;

  // цикл на 1000 итераций, суммирующий члены в ряду Тейлора
  while (flag < 1000) {
    result += temp;
    flag += 2;
    temp *= -(x * x) / ((flag - 1) * flag);
  }

  // возвращает конечный результат
  return result;
}