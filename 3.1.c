#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет, что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение аргумента
 * @return значение функции
 */
double getY(const double x);

int main()
{
    double start, end, step;
    
    printf("Введите начальное значение: ");
    start = getValue();
    
    printf("Введите конечное значение: ");
    end = getValue();
    
    printf("Введите шаг: ");
    step = getValue();
    checkStep(step);
    
    double x = start; 

    while (x < end + DBL_EPSILON)
    {
        double y = getY(x);
        printf("%.2lf\t\t%.4lf\n", x, y);
        x += step;
    }

    return 0;
}

double getValue()
{
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка: шаг должен быть положительным!\n");
        abort();
    }
}

double getY(const double x)
{
    double denominator = 3.0 + sin(3.6 * x);
    return x - 1.0 / denominator;
}
