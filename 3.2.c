#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurrent(const int i);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/** 
 * @brief проверяет, что число неотрицательное
 * @param value - проверяемое значение
 */
void checkNonNegative(const int value);

int main()
{
    printf("Введите n: ");
    int n = getValue();
    checkNonNegative(n);
    printf("Сумма %d чисел последовательности равна %.4lf\n", n, getSumN(n));

    printf("Введите e: ");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма последовательности с точностью %lf равна %.4lf\n", e, getSumE(e));

    return 0;
}

int getValue()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Ошибка: значение должно быть положительным!\n");
        exit(1);
    }
}

void checkNonNegative(const int value)
{
    if (value < 0)
    {
        printf("Ошибка: значение должно быть неотрицательным!\n");
        exit(1);
    }
}

double getRecurrent(const int i)
{
    return -1.0 / i;
}

double getSumN(const int n)
{
    if (n == 0) return 0;

    double current = 1.0;  
    double result = 0.0;

    for (int i = 1; i <= n; i++)
    {
        current *= getRecurrent(i);
        result += current;
    }
    return result;
}

double getSumE(const double e)
{
    double current = 1.0;  
    double result = 0.0;
    int i = 1;
    
    while (1)
    {
        current *= getRecurrent(i);
        if (fabs(current) < e)
            break;
        result += current;
        i++;
    }
    return result;
}
