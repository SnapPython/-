#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int n = 3; // the dimension of the matrix
int maxIterations = 1000;
double tolerance = 1e-6;


void gaussSeidel(double** matrix, double* b, double* x, int maxIterations, double tolerance) {
    auto xNew = new double[n];
    int iteration = 0;
    double error = tolerance + 1;

    while (iteration < maxIterations && error > tolerance) {
        for (int i = 0; i < n; i++) {
            double sum1 = 0;
            double sum2 = 0;
            for (int j = 0; j < i; j++) {
                sum1 += matrix[i][j] * xNew[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum2 += matrix[i][j] * x[j];
            }
            xNew[i] = (b[i] - sum1 - sum2) / matrix[i][i];
        }

        error = 0;
        for (int i = 0; i < n; i++) {
            double diff = fabs(xNew[i] - x[i]);
            if (diff > error) {
                error = diff;
            }
        }

        for (int i = 0; i < n; i++) {
            x[i] = xNew[i];
        }

        iteration++;
    }

    delete[] xNew;
}

int main() {
    int n = 3;
    auto matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }
    auto b = new double[n];
    auto* x = new double[n];

    matrix[0][0] = 10; matrix[0][1] = -2; matrix[0][2] = -1;
    matrix[1][0] = -2; matrix[1][1] = 10; matrix[1][2] = -1;
    matrix[2][0] = -1; matrix[2][1] = -2; matrix[2][2] = 5;
    b[0] = 3;
    b[1] = 15;
    b[2] = 10;


    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    gaussSeidel(matrix, b, x, maxIterations, tolerance);

    cout << "线性方程组的解为：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(6) << x[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] b;
    delete[] x;

    return 0;
}