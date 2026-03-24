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
    int D[6] = {3,3,3,3,3,3};

    int M[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int N[3][3] = {
        {2,2,2},
        {2,2,2},
        {2,2,2}
    };

    int A[3][3];

    int r = HadamardProduct(D,M,N,A);
    print_matrix("A",(int *) A, 3,3);
    return 0;
}