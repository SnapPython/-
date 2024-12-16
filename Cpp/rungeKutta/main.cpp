#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x, double y) {
    return x - y + 1;
}

// 四阶龙格-库塔法函数
void rungeKutta(double x0, double y0, double h, double xEnd) {
    double x = x0;
    double y = y0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "x\t\ty\n";
    std::cout << x << "\t\t" << y << "\n";
    while (x < xEnd) {
        // 计算k1
        double k1 = h * f(x, y);
        // 计算k2
        double k2 = h * f(x + h / 2, y + k1 / 2);
        // 计算k3
        double k3 = h * f(x + h / 2, y + k2 / 2);
        // 计算k4
        double k4 = h * f(x + h, y + k3);

        // 更新y值
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        std::cout << x << "\t\t" << y << "\n";
    }
}

int main() {
    double x0 = 0;
    double y0 = 1;
    double h = 0.1;
    double xEnd = 1;
    rungeKutta(x0, y0, h, xEnd);
    return 0;
}
