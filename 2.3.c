#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief проверяет, является ли треугольник прямоугольным с гипотенузой a
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника  
 * @param c третья сторона треугольника
 * @return 1 если прямоугольный треугольник с гипотенузой a, иначе 0
 */
int gipotinusaA(const double a, const double b, const double c);
/**
 * @brief проверяет, является ли треугольник прямоугольным с гипотенузой b
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника
 * @param c третья сторона треугольника
 * @return 1 если прямоугольный треугольник с гипотенузой b, иначе 0
 */
int gipotinusaB(const double a, const double b, const double c);
/**
 * @brief проверяет, является ли треугольник прямоугольным с гипотенузой c
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника
 * @param c третья сторона треугольника
 * @return 1 если прямоугольный треугольник с гипотенузой c, иначе 0
 */
int gipotinusaC(const double a, const double b, const double c);
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
    double a = 0, b = 0, c = 0;
    printf("Введите сторону a: ");
    a = getValue();
    printf("Введите сторону b: ");
    b = getValue();
    printf("Введите сторону c: ");
    c = getValue();
    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);
    printf("c = %.2lf\n", c);
    if (a <= 0)
    {
        printf("Ошибка: все стороны должны быть положительными!\n");
        return 0;
    }
    else if (b <= 0)
    {
        printf("Ошибка: все стороны должны быть положительными!\n");
        return 0;
    }
    else if (c <= 0)
    {
        printf("Ошибка: все стороны должны быть положительными!\n");
        return 0;
    }
    if (a + b <= c)
    {
        printf("Ошибка: эти числа не могут быть сторонами треугольника!\n");
        return 0;
    }
    else if (a + c <= b)
    {
        printf("Ошибка: эти числа не могут быть сторонами треугольника!\n");
        return 0;
    }
    else if (b + c <= a)
    {
        printf("Ошибка: эти числа не могут быть сторонами треугольника!\n");
        return 0;
    }
    if (gipotinusaA(a, b, c))
    {
        printf("Треугольник прямоугольный. Гипотенуза: a = %.2lf\n", a);
    }
    else if (gipotinusaB(a, b, c))
    {
        printf("Треугольник прямоугольный. Гипотенуза: b = %.2lf\n", b);
    }
    else if (gipotinusaC(a, b, c))
    {
        printf("Треугольник прямоугольный. Гипотенуза: c = %.2lf\n", c);
    }
    else
    {
        printf("Треугольник не является прямоугольным.\n");
    }
    return 0;
    }
int gipotinusaA(const double a, const double b, const double c)
{
    return (a * a == b * b + c * c);
}
int gipotinusaB(const double a, const double b, const double c)
{
    return (b * b == a * a + c * c);
}
int gipotinusaC(const double a, const double b, const double c)
{
    return (c * c == a * a + b * b);
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    return value;
}
