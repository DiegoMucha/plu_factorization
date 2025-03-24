#include "Matrix.h"

void set_matrix_values(Matrix& og_matriz, int n) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Set the value of the [" << i+1 << "][" << j+1 << "] element: ";
            cin >> value;
            og_matriz.set_val(i, j, value);
        }
    }
}

void factorizar_lu(int n) {
    Matrix og_matrix(n, 'O');
    Matrix l_matrix(n, 'L');
    set_matrix_values(og_matrix, n);
    Matrix u_matrix = og_matrix;
    Matrix p_matrix(n, 'P');
    // factorization
    for (int i = 0; i < n-1; i++) {
        int pivot = u_matrix.get_matrix()[i][i];
        if (pivot == 0) {
            bool possible_swap = false;
            for (int j = i+1; j < n; j++) {
                if (u_matrix.get_matrix()[j][i] != 0) {
                    vector<float> temp_row = u_matrix.get_matrix()[j];
                    u_matrix.set_row(j, u_matrix.get_matrix()[i]);
                    u_matrix.set_row(i, temp_row);

                    temp_row = p_matrix.get_matrix()[j];
                    p_matrix.set_row(j, p_matrix.get_matrix()[i]);
                    p_matrix.set_row(i, temp_row);
                    possible_swap = true;
                    pivot = u_matrix.get_matrix()[i][i];
                    break;
                }
            }
            if (!possible_swap) {
                break;
            }
        }
        for (int j = i+1; j < n; j++) {
            float div_value = (u_matrix.get_matrix()[j][i] / pivot) * -1;
            l_matrix.set_val(j, i, div_value*-1);
            for (int k = i; k < n; k++) {
                int value = u_matrix.get_matrix()[i][k]*div_value + u_matrix.get_matrix()[j][k];
                u_matrix.set_val(j, k, value);
            }
        }
    }
    p_matrix.show_matrix('P');
    u_matrix.show_matrix('U');
    l_matrix.show_matrix('L');
}

int main() {
    int n = 3;
    factorizar_lu(n);
}