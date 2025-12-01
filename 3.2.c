#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает сумму n членов последовательности
* @param n - число членов последовательности
* @return Рассчитанное значение
*/
double defSumm(const int n);

/**
* @brief Рассчитывает сумму членов последовательности с точностью e
* @param e - точность рассчёта
* @return Рассчитанное значение
*/
double defSummE(const double e);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param k - текущий индекс 
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int k);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
    system("chcp 1251");
    
    printf("Введите целое число n: ");
    int n = (int)defValid();
    if (n < 0)
    {
        printf("Error: n должно быть неотрицательным\n");
        exit(1);
    }
    
    printf("Сумма первых %d членов последовательности = %.10lf\n\n", n, defSumm(n));
    
    printf("Введите число e (точность): ");
    double e = defValid();
    if (e <= 0)
    {
        printf("Error: e должно быть положительным\n");
        exit(1);
    }
    
    printf("Сумма членов последовательности с точностью %.10lf = %.10lf\n", e, defSummE(e));
    
    return 0;
}

double defValid()
{
    double valid = 0;
    if (!scanf("%lf", &valid))
    {
        printf("Error: некорректный ввод\n");
        exit(1);
    }
    return valid;
}

double defSumm(const int n)
{
    if (n == 0) return 0.0;
    
    double current = -1.0;
    double result = current;
    
    for (int k = 1; k < n; k++) 
    {
        current *= getRecurent(k); 
        result += current;
    }
    
    return result;
}

double defSummE(const double e)
{
    double current = -1.0; 
    double result = 0.0;
    
    int k = 1;
    while (fabs(current) >= e)
    {
        result += current;
        current *= getRecurent(k);
        k++;
    }
    
    return result;
}

double getRecurent(const int k)
{
    
    return -1.0 / k;
}
