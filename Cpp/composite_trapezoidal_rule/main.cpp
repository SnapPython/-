#include <iostream>
#include <cmath>
double f(double x) {
    if (x == 0) {
        return 1.0;
    }
    return std::sin(x) / x;
}

double composite_trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a = 0;
    double b = 1;
    int n2 = 2;
    int n4 = 4;
    int n8 = 8;
    int n16 = 16;

    double result2 = composite_trapezoidal_rule(a, b, n2);
    double result4 = composite_trapezoidal_rule(a, b, n4);
    double result8 = composite_trapezoidal_rule(a, b, n8);
    double result16 = composite_trapezoidal_rule(a, b, n16);

    std::cout << " n=2 使用复化梯形公式计算的积分近似值为: " << result2 << std::endl;
    std::cout << " n=4 使用复化梯形公式计算的积分近似值为: " << result4 << std::endl;
    std::cout << " n=8 使用复化梯形公式计算的积分近似值为: " << result8 << std::endl;
    std::cout << " n=16 使用复化梯形公式计算的积分近似值为: " << result16 << std::endl;


    return 0;
}