include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief вычисляет значение функции при x < 4
 * @param x значение переменной x
 * @param a значение константы a
 * @return результат вычисления функции
 */
double getFirst(const double x, const double a);
/**
 * @brief вычисляет значение функции при x >= 4
 * @param x значение переменной x
 * @param a значение константы a
 * @return результат вычисления функции
 */
double getSecond(const double x, const double a);
/**
 * @brief вычисляет значение, введенное с клавиатуры с проверкой ввода
 * @return вычисленное значение
 */
double getValue();
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double x = 0, a = 0;
    printf("Введите значение x: ");
    x = getValue();
    printf("Введите значение константы a: ");
    a = getValue();
    printf("x = %.2lf\n", x);
    printf("a = %.2lf\n", a);
    if (x < 4)
    {
        if (x == 0)
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
    return a/x + pow(x, 2);
}

double getSecond(const double x, const double a)
{
    return a * x + pow(x, 3);
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
