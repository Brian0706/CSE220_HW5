
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name: Brian Chau
 * SBU ID: 116125954
 */

#include "./matrix.h"
#include "stdio.h"

void print_matrix(const char *name, int *matrix, int rows, int cols) {
    printf("%s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *((int *)matrix + i * cols + j));
        }
        printf("\n");
    }
}

int main(){
    int D[4] = {2,2,2,2};

    int A[2][2] = {
        {3,5},
        {2,4}
    };

    int DS[2][2];

    int r = DiagonalSum(D,A,DS);
    printf("%d\n",r);
    print_matrix("A",(int *) DS, 2,2);
    return 0;
}