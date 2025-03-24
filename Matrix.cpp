#include "Matrix.h"

Matrix::Matrix(int n, char LU) {
    this->n = n;
    for (int i = 0; i < n; i++) {
        this->matrix.push_back(vector<float>());
        for (int j = 0; j < n; j++) {
            this->matrix[i].push_back(0);
        }
    }
    if (LU == 'L' || LU == 'P') {
        for (int i = 0; i < n; i++) {
            this->matrix[i][i] = 1;
        }
    }
}

vector<vector<float>> Matrix::get_matrix() {
    return this->matrix;
}
void Matrix::set_val(int i, int j, int value) {
    this->matrix[i][j] = value;
}

void Matrix::show_matrix(char type) {
    cout << "\nMatrix " << type << ": " << "\n";
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->n; j++) {
            cout << fixed << setprecision(2);
            cout << this->matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Matrix::set_row(int i, vector<float>& row) {
    this->matrix[i] = row;
}