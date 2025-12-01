#include<stdio.h>
#include<math.h>  
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает сумму n членов ряда arctg(x)
* @param n - число членов последовательности
* @param x - аргумент функции
* @return Рассчитанное значение
*/
double defSumm(const int n, const double x);

/**
* @brief Рассчитывает сумму ряда arctg(x) с заданной точностью e
* @param e - точность рассчёта
* @param x - аргумент функции
* @return Рассчитанное значение
*/
double defSummE(const double e, const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @param x - аргумент функции
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void CheckValue(const double input);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите значение x: ");
	double x = defValid();

	printf("Введите целое число n: ");
	int n = (int) defValid();
	CheckValue(n);

	printf("Сумма первых %d членов ряда arctg(%.2f) = %.10lf\n", n, x, defSumm(n, x));
	
	printf("\nВведите точность e: ");
	double e = defValid();
	CheckValue(e);

	printf("Сумма ряда arctg(%.2f) с точностью %.2e = %.10lf\n", x, e, defSummE(e, x));
	
	printf("\nПроверка: arctg(%.2f) = %.10lf\n", x, atan(x));

	return 0;
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error\n");
		exit(1);
	}

	return valid;
}

void CheckValue(const double input)
{
	if (!(input > 0))
	{
		printf("Error\n");
		exit(1);
	}
}

double defSumm(const int n, const double x)
{
	double current = x;  
	double result = current;
	for (int i = 1; i < n; i++)  
	{
		current *= getRecurent(i, x);
		result += current;
	}
	return result;
}

double defSummE(const double e, const double x)
{
	double current = x; 
	double result = 0;
	for (int i = 1; fabs(current) > e; i++) 
	{
		result += current;
		current *= getRecurent(i, x);
	}
	return result;
}

double getRecurent(const int i, const double x)
{

	return -x * x * (2.0 * i - 1.0) / (2.0 * i + 1.0);
}
