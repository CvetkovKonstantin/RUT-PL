#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief Проверяет принадлежность аргумента функции области определения
 * @param x Аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief Вычисляет значение функции по заданной формуле
 * @param x Аргумент функции
 * @return Значение функции в точке x
 */
double getY(const double x);

int main()
{
    printf("Введите начальное значение: ");
    double start = getValue();
    printf("Введите конечное значение: ");
    double end = getValue();
    printf("Введите шаг: ");
    double step = getValue();
    checkStep(step);
    double x = start;
    while (x < end + DBL_EPSILON)
    {
        if (defineOOF(x))
        {
            double y = getY(x);
            printf("x = %.2lf, y = %.4lf\n", x, y);
        }
        else
        {
            printf("x = %.2lf, не принадлежит ООФ\n", x);
        }
        x += step;
    }
    return 0;
}

double getValue()
{
    double value;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным!\n");
        abort();
    }
}

bool defineOOF(const double x)
{
    double denominator = 3.0 + sin(3.6 * x);
    if (fabs(denominator) <= DBL_EPSILON) {
        return false;
    }
    double under_sqrt = x - 1.0 / denominator;
    return under_sqrt >= -DBL_EPSILON;
}

double getY(const double x)
{
    double denominator = 3.0 + sin(3.6 * x);
    double under_sqrt = x - 1.0 / denominator; 
    return sqrt(under_sqrt);
}
