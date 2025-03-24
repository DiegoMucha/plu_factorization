#pragma once
#include "libraries.h"

class Matrix {
    private:
        vector<vector<float>> matrix;
        int n;
        char LU;
    public:
        Matrix(int n, char LU);
        vector<vector<float>> get_matrix();
        void set_row(int i, vector<float>& row);
        void set_val(int i, int j, int value);
        void show_matrix(char type);
};