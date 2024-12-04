#include <iostream>
#include <cmath>
using namespace std;

double a = 1;
double b = 2;
double tolerance = 1e-6;
int max_iteration = 100;

double equation(double x) {
    return pow(x, 3) + 4*pow(x, 2) - 10;
}

// 二分法求解函数
void bisectionMethod(double a, double b, double tolerance) {
    if (equation(a) * equation(b) >= 0) {
        cout << "区间两端点函数值同号" << endl;
        return;
    }

    double c;
    int iteration = 0;
    while ((b - a) > tolerance && iteration <= max_iteration) {
        c = (a + b) / 2;

        if (equation(c) == 0) {
            break;
        } else if (equation(c) * equation(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    cout << "经过 " << iteration << " 次迭代，近似根为: "  << c << endl;
}

int main() {

    bisectionMethod(a, b, tolerance);

    return 0;
}