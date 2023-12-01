#include<iostream>
using namespace std;

void readMatrix(int** &a, int rows, int columns) {
    a = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[columns];
        for (int j = 0; j < columns; j++) {
            cin >> a[i][j];
        }
    }
}

void printMatrix(int** a, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void matMul(int** a, int r1, int c1, int** b, int r2, int c2, int** &result) {
    if (c1 != r2) {
        cout << "Not conformable for multiplication" << endl;
        return;
    }

    result = new int*[r1];
    for (int i = 0; i < r1; i++) {
        result[i] = new int[c2];
        for (int j = 0; j < c2; j++) {
            int val = 0;
            for (int k = 0; k < c1; k++) {
                val += a[i][k] * b[k][j];
            }
            result[i][j] = val;
        }
    }
}

int main() {
    int **a, **b, **result;

    readMatrix(a, 1, 2);
    printMatrix(a, 1, 2);

    readMatrix(b, 2, 3);
    printMatrix(b, 2, 3);

    matMul(a, 1, 2, b, 2, 3, result);
    printMatrix(result, 1, 3);

    // Deallocate memory
    for (int i = 0; i < 1; i++) {
        delete[] a[i];
    }
    delete[] a;

    for (int i = 0; i < 2; i++) {
        delete[] b[i];
    }
    delete[] b;

    for (int i = 0; i < 1; i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
