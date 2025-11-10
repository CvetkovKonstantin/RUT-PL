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
 * @brief проверяет, принадлежит ли значение аргумента функции её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение аргумента
 * @return значение функции
 */
double getY(const double x);

int main()
{
    double start = 0.0;      
    double end = 0.85;       
    double step = 0.05; 
    
    double x = start; 

    while (x < end + DBL_EPSILON)
    {
        if (defineOOF(x))
        {
            double y = getY(x);
            printf("%.2lf\t\t%.4lf\n", x, y);
        }
        else
        {
            printf("%.2lf\t\tне принадлежит ООФ\n", x);
        }
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
    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным!\n");
        abort();
    }
}

bool defineOOF(const double x)
{
    double denominator = 3.0 + sin(3.6 * x);

    if (fabs(denominator) <= DBL_EPSILON)
    {
        return false;
    }

    return true;
}

double getY(const double x)
{
    double denominator = 3.0 + sin(3.6 * x);
    return x - 1.0 / denominator;
}
