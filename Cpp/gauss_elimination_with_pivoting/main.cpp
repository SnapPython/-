#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// 交换两行元素
void swapRows(double** matrix, double* b, int row1, int row2, int n) {
    for (int j = 0; j < n; j++) {
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
    double temp_b = b[row1];
    b[row1] = b[row2];
    b[row2] = temp_b;
}

// 寻找列主元并交换
void pivot(double** matrix, double* b, int k, int n) {
    int maxRow = k;
    for (int i = k + 1; i < n; i++) {
        if (fabs(matrix[i][k]) > fabs(matrix[maxRow][k])) {
            maxRow = i;
        }
    }
    if (maxRow!= k) {
        swapRows(matrix, b, k, maxRow, n);
    }
}

// 消元
void eliminate(double** matrix, double* b, int n) {
    for (int k = 0; k < n - 1; k++) {
        pivot(matrix, b, k, n);
        for (int i = k + 1; i < n; i++) {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
}

// 回代
void backSubstitution(double** matrix, double* b, double* x, int n) {
    x[n - 1] = b[n - 1] / matrix[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / matrix[i][i];
    }
}


int main() {
    int n = 3;
    auto matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }
    auto b = new double[n];
    auto x = new double[n];

    matrix[0][0] = 10; matrix[0][1] = -2; matrix[0][2] = -1;
    matrix[1][0] = -2; matrix[1][1] = 10; matrix[1][2] = -1;
    matrix[2][0] = -1; matrix[2][1] = -2; matrix[2][2] = 5;
    b[0] = 3;
    b[1] = 15;
    b[2] = 10;

    eliminate(matrix, b, n);
    backSubstitution(matrix, b, x, n);

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
