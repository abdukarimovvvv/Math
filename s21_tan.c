#include "s21_math.h"

long double s21_tan(double x) {
  // уменьшите угол до диапазона [0, 2 * pi)
  x = s21_fmod(x, 2 * S21_PI);

  // возвращает отношение sin(x) к cos(x)
  return s21_sin(x) / s21_cos(x);
}