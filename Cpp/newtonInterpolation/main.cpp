#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

struct Point {
    double x;
    double y;
};

double dividedDifference(const vector<Point>& points, int start, int end, int order) {
    if (order == 0) {
        return points[start].y;
    }
    return (dividedDifference(points, start + 1, end, order - 1) - dividedDifference(points, start, end - 1, order - 1)) / (points[end].x - points[start].x);
}

double newtonInterpolation(const vector<Point>& points, double x) {
    int n = points.size();
    double result = dividedDifference(points, 0, 0, 0);
    double term = 1.0;
    for (int i = 1; i < n; ++i) {
        term *= (x - points[i - 1].x);
        result += dividedDifference(points, 0, i, i) * term;
    }
    return result;
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
    vector<Point> points = { {1, 1}, {4, 2}, {9, 3} };
    double xToInterpolate = 5;
    double interpolatedValue = newtonInterpolation(points, xToInterpolate);
    if (!QueryPerformanceCounter(&end)) {
        cerr << "获取结束计数器值失败" << endl;
        return 1;
    }
    double elapsedTime = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart;
    cout << "The interpolated value at x = " << xToInterpolate << " is: " << interpolatedValue << endl;
    cout << "程序执行时间: " << elapsedTime << " 秒" << endl;
    return 0;
}