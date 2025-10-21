#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> 

/**
 * @brief Вычисляет значение функции при x < 4
 * @param x значение переменной x
 * @param a значение константы a
 * @return результат вычисления функции
 */
double getFirst(const double x, const double a);

/**
 * @brief Вычисляет значение функции при x >= 4
 * @param x значение переменной x
 * @param a значение константы a
 * @return результат вычисления функции
 */
double getSecond(const double x, const double a);

/**
 * @brief Ввод значения с клавиатуры с проверкой корректности
 * @return введённое значение
 */
double getValue(void);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double x = 0.0, a = 0.0;

    printf("Введите значение x: ");
    x = getValue();

    printf("Введите значение константы a: ");
    a = getValue();

    printf("x = %.2lf\n", x);
    printf("a = %.2lf\n", a);

    if (x < 4.0)
    {
        if (fabs(x) < DBL_EPSILON)
        {
            printf("Ошибка: деление на ноль невозможно!\n");
        }
        else
        {
            double result = getFirst(x, a);
            printf("Результат: %.2lf\n", result);
        }
    }
    else
    {
        double result = getSecond(x, a);
        printf("Результат: %.2lf\n", result);
    }

    return 0;
}

double getFirst(const double x, const double a)
{
    return a / x + pow(x, 2);
}

double getSecond(const double x, const double a)
{
    return a * x + pow(x, 3);
}

double getValue(void)
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}
