#include "s21_math.h"

long double s21_taylor_log(double x) {
  // Инициализировать результат и первый элемент как x
  long double result = x, member = x;
  // Продолжайте вычислять результат до тех пор, пока значение элемента
  // превышает заданную точность
  for (int flag = 2; s21_fabs(member) > S21_EPS; flag++) {
    // Вычислить следующего участника
    member *= -((flag - 1) * (x / flag));
    // Добавьте его к результату
    result += member;
  }
  // Возвращает конечный результат
  return result;
}

long double s21_log(double x) {
  // Инициализировать результат
  long double result;
  // Если x отрицательно, NaN или равно нулю, верните NaN
  if (x <= 0.0 || S21_IS_NAN(x)) {
    result = S21_NAN;
  }
  // Если x бесконечно, верните infinite
  else if (S21_IS_INF(x)) {
    result = S21_INF;
  }
  // Если x положительно, вычислите логарифм
  else {
    // Точность инициализации
    int accuracy = 0;
    // Делите x на 2, пока оно не станет меньше 2
    while ((int)x >= 2) {
      accuracy++;
      x /= 2;
    }
    // Вычислить логарифм (x), используя точность и логарифм Тейлора
    result = accuracy * S21_LN2 + s21_taylor_log(x - 1);
  }
  // Возвращает конечный результат
  return result;
}