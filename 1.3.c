#include<stdio.h>
/**
* @brief рассчитывает время нагрева проволки
* @param Q_kJ количество теплоты в кДж
* @param I сила тока в амперах
* @param R сопротивление проволки в омах
* @return возвращает рассчитанное значение
*/
double findt(const double Q_kJ, const double I, const double R);
/**
* @brief точка входа в программу
* @return возвращает 0 если программа выполненна корректно
*/
int main()
{
	double R;
	double I;
	double Q_kJ;
	printf("Введите сопротивление R (Oм): ");
	scanf("%lf", &R);
	printf("Введите силу тока I (A): ");
	scanf("%lf", &I);
	printf("Введите количество теплоты Q (кДж): ");
	scanf("%lf", &Q_kJ);
	printf("Время нагрева проволки: %.2lf секунд\n", findt(Q_kJ, I, R));
	return 0;
}
double findt(const double Q_kJ, const double I, const double R)
{
	return (Q_kJ * 1000) / (I * I * R);
}
