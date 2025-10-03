#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
*@brief ищет среднее арифметическое кубов двух чисел
*@param num1 первое число
*@param num2 второе число
*@return возвращает рассчитанное значение
*/
double getCA(const double num1, const double num2);
/**
 * @brief считывает значение,введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
*@brief ищет среднее геометрическое модулей двух чисел
*@param num1 первое число
*@param num2 второе число
*@return возвращает рассчитанное значение
*/
double getCG(const double num1, const double num2);
/**
*@brief Точка входа в программу
*@return возвращает 0, если программа выполнена корректно
*/
int main(void)
{   
    printf("Введите первое число: ");
    double num1=getValue();
    printf("Введите второе число: ");
    double num2=getValue();
    printf("Среднее арифметическое равно: %.2lf\n",getCA(num1, num2));
    printf("Среднее геометрическое равно: %.2lf",getCG(num1, num2));
    return 0;
}
double getCA(const double num1, const double num2)
{
    return (pow(num1, 3)+pow(num2, 3))/2;
}
double getCG(const double num1, const double num2)
{
    return sqrt(fabs(num1)*fabs(num2));
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
