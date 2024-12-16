#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// 计算拉格朗日基本多项式li(x)的值
double lagrange_basis(int i, double x, const vector<double>& x_data) {
    double result = 1.0;
    for (size_t j = 0; j < x_data.size(); ++j) {
        if (j!= i) {
            result *= (x - x_data[j]) / (x_data[i] - x_data[j]);
        }
    }
    return result;
}

// 拉格朗日插值函数
double lagrange_interpolation(double x, const vector<double>& x_data, const vector<double>& y_data) {
    double sum = 0.0;
    for (size_t i = 0; i < x_data.size(); ++i) {
        sum += y_data[i] * lagrange_basis(i, x, x_data);
    }
    return sum;
}

int main() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    if (!QueryPerformanceFrequency(&frequency)) {
        cerr << "获取计数器频率失败" << endl;
        return 1;
    }
    if (!QueryPerformanceCounter(&start)) {
        cerr << "获取开始计数器值失败" << endl;
        return 1;
    }

    vector<double> x_data = {1.1, 2.3, 3.9, 5.1};
    vector<double> y_data = {3.887, 4.276, 4.651, 2.117};

    double target_x1 = 2.101;
    double target_x2 = 4.234;
    double interpolated_value1 = lagrange_interpolation(target_x1, x_data, y_data);
    double interpolated_value2 = lagrange_interpolation(target_x2, x_data, y_data);

    if (!QueryPerformanceCounter(&end)) {
        cerr << "获取结束计数器值失败" << endl;
        return 1;
    }
    double elapsedTime = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart;

    cout << "在 x = " << target_x1 << " 处的插值结果为: " << interpolated_value1 << endl;
    cout << "在 x = " << target_x2 << " 处的插值结果为: " << interpolated_value2 << endl;
    cout << "程序执行时间: " << elapsedTime << " 秒" << endl;


    return 0;
}
