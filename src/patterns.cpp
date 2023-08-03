#include "patterns.h"

void triangle_one(int row, int column) {
    if (row == 0) return;

    if (column < row) {
        cout << "*";
        triangle_one(row, ++column);
    } else {
        cout << endl;
        triangle_one(--row, 0);
    }
}

void triangle_two(int row, int column) {
    if (row == 0) return;
    if (column < row) {
        triangle_two(row, column+1);
        cout << "*";
    } else {
        triangle_two(row-1, 0);
        cout << endl;
    }
}
