#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief проверяет, что все стороны треугольника положительные
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника  
 * @param c третья сторона треугольника
 * @return 1 если все стороны положительные, иначе 0
 */
int areSidesPositive(const double a, const double b, const double c);

/**
 * @brief проверяет, могут ли числа быть сторонами треугольника
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника
 * @param c третья сторона треугольника
 * @return 1 если могут быть сторонами треугольника, иначе 0
 */
int canFormTriangle(const double a, const double b, const double c);

/**
 * @brief проверяет, является ли треугольник прямоугольным
 * @param a первая сторона треугольника
 * @param b вторая сторона треугольника
 * @param c третья сторона треугольника
 * @return номер гипотенузы (1 - a, 2 - b, 3 - c, 0 - не прямоугольный)
 */
int findHypotenuse(const double a, const double b, const double c);

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
    
    if (!areSidesPositive(a, b, c))
    {
        printf("Ошибка: все стороны должны быть положительными!\n");
        return 0;
    }
    
    if (!canFormTriangle(a, b, c))
    {
        printf("Ошибка: эти числа не могут быть сторонами треугольника!\n");
        return 0;
    }
    
    int hypotenuse_type = findHypotenuse(a, b, c);
    if (hypotenuse_type == 1)
    {
        printf("Треугольник прямоугольный. Гипотенуза: a = %.2lf\n", a);
    }
    else if (hypotenuse_type == 2)
    {
        printf("Треугольник прямоугольный. Гипотенуза: b = %.2lf\n", b);
    }
    else if (hypotenuse_type == 3)
    {
        printf("Треугольник прямоугольный. Гипотенуза: c = %.2lf\n", c);
    }
    else
    {
        printf("Треугольник не является прямоугольным.\n");
    }
    
    return 0;
}

int areSidesPositive(const double a, const double b, const double c)
{
    return (a > 0) && (b > 0) && (c > 0);
}

int canFormTriangle(const double a, const double b, const double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int findHypotenuse(const double a, const double b, const double c)
{
  
    double max_side = a;
    int max_index = 1;
    
    if (b > max_side)
    {
        max_side = b;
        max_index = 2;
    }
    if (c > max_side)
    {
        max_side = c;
        max_index = 3;
    }
    

    double sum_squares;
    double max_square;
    
    switch (max_index)
    {
        case 1:
            sum_squares = b * b + c * c;
            max_square = a * a;
            break;
        case 2:
            sum_squares = a * a + c * c;
            max_square = b * b;
            break;
        case 3:
            sum_squares = a * a + b * b;
            max_square = c * c;
            break;
        default:
            return 0;
    }
    
 
    if (fabs(max_square - sum_squares) <= DBL_EPSILON * fmax(max_square, sum_squares))
    {
        return max_index;
    }
    
    return 0;
}

double getValue()
{
    double value = 0;
    if (scanf("%lf", &value) != 1 || !isfinite(value))
    {
        printf("Ошибка ввода: введено недопустимое число!\n");
        abort();
    }
    return value;
}
