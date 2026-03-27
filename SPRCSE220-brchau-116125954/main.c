
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
    int D[6] = {4,3,2,2};

    int A[4][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {1,2,3}
    };

    int DS[2][2];

    int r = DiagonalSum(D,A,DS);
    printf("%d\n",r);
    print_matrix("A",(int *) DS, 2,2);
    return 0;
}