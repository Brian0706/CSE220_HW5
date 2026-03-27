
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
    int D[4] = {3,3,5,1};

    int A[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    int DS[5][1];

    int r = DiagonalSum(D,A,DS);
    printf("%d\n",r);
    print_matrix("A",(int *) DS, 5,1);
    return 0;
}