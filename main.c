//
// Created by Aming on 2021/10/25.
//

#include "stdio.h"

int main() {
    for (int row = 1; row <= 9; ++row) {
        for (int col = 1; col <= row; ++col) {
            printf("%d * %d = %d \n", col, row, col * row);
        }
    }
    return 0;
}