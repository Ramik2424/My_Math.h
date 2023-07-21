#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 0.0;  // Результат функции
  double man = base;    // Основание
  double level = exp;   // Степень
  int check_main = 0;  // Флаг на отрицательный знак основания
  int check_level = 0;  // Флаг на нечет степени

  if (man < 0) {
    check_main = 1;
  }

  if (s21_fmod(level, 2) != 0) {
    check_level = 1;
  }
  if ((man == 1 && S21_IS_INF(exp)) || (exp == 0)) {
    result = 1;
  } else {
    if (check_main == 1) {
      man = -man;
      result = s21_exp(level * s21_log(man));
      if (check_level == 1) {
        result = -result;
      }
    } else {
      result = s21_exp(level * s21_log(man));
    }
  }

  return result;
}
