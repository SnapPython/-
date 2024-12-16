#include <iostream>
#include <cmath>

double func(double x) {
    if (x == 0) {
        return 1.0;
    }
    return std::sin(x) / x;
}

// 复化辛浦生求积算法函数
double simpsons_rule(double a, double b, int n) {
    double h = (b - a) / n;  // 子区间宽度
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (int i = 1; i < n; i += 2) {
        sum1 += func(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        sum2 += func(a + i * h);
    }

    return h / 3 * (func(a) + func(b) + 4 * sum1 + 2 * sum2);
}

int main() {
    double a = 0.0;
    double b = 1.0;

    int n2 = 2;
    int n4 = 4;
    int n8 = 8;
    int n16 = 16;

    double result2 = simpsons_rule(a, b, n2);
    double result4 = simpsons_rule(a, b, n4);
    double result8 = simpsons_rule(a, b, n8);
    double result16 = simpsons_rule(a, b, n16);

    std::cout << " n=2 使用复化辛浦生公式计算的积分近似值为: " << result2 << std::endl;
    std::cout << " n=4 使用复化辛浦生公式计算的积分近似值为: " << result4 << std::endl;
    std::cout << " n=8 使用复化辛浦生公式计算的积分近似值为: " << result8 << std::endl;
    std::cout << " n=16 使用复化辛浦生公式计算的积分近似值为: " << result16 << std::endl;

    return 0;
}