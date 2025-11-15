#include <stdio.h>
#include <math.h>

double arctg_series(double x, double epsilon) {
   
    if (fabs(x) > 1.0) {
        double sign = (x > 0) ? 1.0 : -1.0;
        return sign * (3.14159265358979323846 / 2.0) - arctg_series(1.0 / x, epsilon);
    }
    
    double sum = x;
    double term = x;
    int n = 1;
    int max_iterations = 1000;
    
    while (fabs(term) > epsilon && n < max_iterations) {
        term = -term * x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
        sum += term;
        n++;
    }
    
    return sum;
}

int main() {
    const double a = -2.0;
    const double b = -0.1;
    const double h = 0.1;
    const double epsilon = 4e-5;
    
    printf("Табулирование функции arctg(x) и суммы функционального ряда\n");
    printf("Интервал: [%.1f, %.1f], шаг: %.1f, точность: %.0e\n\n", a, b, h, epsilon);
    printf("%-10s %-15s %-15s\n", "x", "arctg(x)", "S(ряд)");
    printf("----------------------------------------\n");
    

    double values[] = {-2.0, -1.9, -1.8, -1.7, -1.6, -1.5, -1.4, -1.3, -1.2, -1.1,
                      -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1};
    
    int count = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < count; i++) {
        double x = values[i];
        double exact_value = atan(x);
        double series_value = arctg_series(x, epsilon);
        
        printf("%-10.2f %-15.6f %-15.6f\n", x, exact_value, series_value);
    }
    
    return 0;
}
