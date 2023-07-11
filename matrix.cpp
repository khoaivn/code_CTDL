#include <iostream>
using namespace std;

const int MAX = 100;

void multiplyMatrix(int mat1[][MAX], int mat2[][MAX], int res[][MAX], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int mat[][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int row1, col1, row2, col2;

    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "Invalid matrix dimensions. Cannot multiply.";
        return 0;
    }

    cout << "Enter the elements of the first matrix: " << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> mat2[i][j];
        }
    }

    multiplyMatrix(mat1, mat2, res, row1, col1, row2, col2);

    cout << "Resultant matrix after multiplication: " << endl;
    displayMatrix(res, row1, col2);

    return 0;
}
