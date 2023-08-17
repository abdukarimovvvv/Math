#include "s21_math.h"

//функция вычисления экспоненты
long double s21_exp(double x) {
  // если x - не число, вернуть NAN
  if (S21_IS_NAN(x)) return S21_NAN;
  // если x - бесконечность, вернуть INF или 0
  if (S21_IS_INF(x)) return x < 0 ? 0 : S21_INF;
  // флаг для определения знака x
  int sign = x < 0;
  // если x отрицателен, инвертируем знак
  if (sign) x *= -1;
  // результат функции
  long double result = 1;
  // временная переменная для расчета следующего члена ряда
  long double temp = x;
  // флаг для учета количества итераций
  unsigned flag = 1;
  // расчет экспоненты через ряд Тейлора
  while (s21_fabs(temp) >= S21_EPS) {
    result += temp;
    temp = (temp * x) / ++flag;
  }
  // если x был отрицателен, вычисляем обратное значение
  return sign ? (1 / result) : result;
}