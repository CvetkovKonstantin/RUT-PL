#include<stdio.h>
double findt(const double Q_kJ, const double I, const double R);
int main()
{
	double R, I, Q_kJ;
	printf("Введите сопротивление R (Oм): ");
	scanf("%lf", &R);
	printf("Введите силу тока I (A): ");
	scanf("%lf", &I);
	printf("Введите количество теплоты Q (кДж): ");
	scanf("%lf", &Q_kJ);
	printf("Время нагрева проволки: %.2f секунд\n", findt(R, I, Q_kJ));
	return 0;
}
double findt(const double Q_kJ, const double I, const double R)
{
	return (Q_kJ * 1000) / (I * I * R);
}
