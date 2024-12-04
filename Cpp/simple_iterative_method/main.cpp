#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double iterationFunction(double x) {
    return pow((10/(x+4)),0.5);
}

void generalIterationMethod(double x0, double tolerance, int maxIterations) {
    double x1;
    int iteration = 0;
    do {
        x1 = iterationFunction(x0);
        if (iteration > 0 && fabs(x1 - x0) < tolerance) {
            break;
        }
        x0 = x1;
        iteration++;
    } while (iteration < maxIterations);

    if (iteration == maxIterations) {
        cout << "达到最大迭代次数，可能未收敛到合适的解" << endl;
    } else {
        cout << "经过 " << iteration << " 次迭代，近似根为: " << fixed << setprecision(6) << x1 << endl;
    }
}

int main() {
    double x0 = 1;
    double tolerance = 1e-6;
    int maxIterations = 100;

    generalIterationMethod(x0, tolerance, maxIterations);

    return 0;
}