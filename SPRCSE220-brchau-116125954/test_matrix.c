
#include <criterion/criterion.h>
#include "matrix.h"

Test(SparseMatrix, simple_sparse)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,0},
        {0,2,0},
        {0,0,3}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, simple_sparse2)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,3},
        {0,0,0},
        {0,2,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, all_in_one_row)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,2,3},
        {0,0,0},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, not_sparse)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,2,3},
        {0,0,0},
        {0,5,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,-1);
}

Test(SparseMatrix, less_elements)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,3},
        {0,0,0},
        {0,0,0}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,2);
}

Test(SparseMatrix, larger_example)
{
    int D[2] = {5,5};

    int M[5][5] = {
        {1,0,0,0,0},
        {0,2,0,0,0},
        {0,0,3,0,0},
        {0,0,0,4,0},
        {0,0,0,0,5}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,5);
}

Test(SparseMatrix, larger_row)
{
    int D[2] = {5,4};

    int M[5][4] = {
        {1,0,0,0},
        {0,2,0,5},
        {0,0,3,0},
        {0,0,0,4},
        {0,0,0,0}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,5);
}

Test(SparseMatrix, larger_col)
{
    int D[2] = {4,5};

    int M[4][5] = {
        {1,0,0,0,5},
        {0,2,0,0,0},
        {0,0,3,0,0},
        {0,0,0,4,0},
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,5);
}


Test(SparseMatrix, one_row)
{
    int D[2] = {1,5};

    int M[1][5] = {
        {1,0,3,0,5}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, one_col)
{
    int D[2] = {5,1};

    int M[5][1] = {
        {1},
        {2},
        {0},
        {0},
        {4}
    };

    int S[3][5];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}

Test(SparseMatrix, one_by_one)
{
    int D[2] = {1,1};

    int M[1][1] = {
        {1}
    };

    int S[3][1];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,1);
}

Test(HadamardProduct, compatible)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(HadamardProduct, too_big)
{
    int D[6] = {2,2,2,2,3,3};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[3][3];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,2);
}

Test(HadamardProduct, too_small)
{
    int D[6] = {2,2,2,2,1,1};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-3);
}


Test(HadamardProduct, diff_sizes)
{
    int D[6] = {2,2,3,3,3,3};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[3][3] = {
        {2,2,4},
        {2,2,4},
        {1,1,1}
    };

    int A[3][3];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(HadamardProduct, diff_sizes2)
{
    int D[6] = {2,2,3,3,1,1};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[3][3] = {
        {2,2,4},
        {2,2,4},
        {1,1,1}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-2);
}

Test(HadamardProduct, compatiable_rect)
{
    int D[6] = {2,3,2,3,2,3};

    int M[2][3] = {
        {1,2,3},
        {3,4,5}
    };

    int N[2][3] = {
        {2,2,2},
        {2,2,2}
    };

    int A[2][3];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(HadamardProduct, compatiable_rect2)
{
    int D[6] = {3,2,3,2,3,2};

    int M[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int N[3][3] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[3][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(HadamardProduct, non_compatiable)
{
    int D[6] = {3,2,2,3,2,3};

    int M[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int N[2][3] = {
        {2,2,2},
        {2,2,2},
    };

    int A[2][3];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(HadamardProduct, one_by_one)
{
    int D[6] = {1,1,1,1,1,1};

    int M[1][1] = {
        {1}
    };

    int N[1][1] = {
        {2}
    };

    int A[1][1];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(HadamardProduct, diff_size_rect)
{
    int D[6] = {2,3,3,2,2,2};

    int M[2][3] = {
        {2,2,2},
        {2,2,2}
    };

    int N[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(HadamardProduct, compatiable2)
{
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

    cr_assert_eq(r,1);
}

Test(Multiplication, simple_case)
{
    int D[6] = {2,2,2,2,2,2};
    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, too_large)
{
    int D[6] = {2,2,2,2,3,3};
    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[3][3];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,2);
}

Test(Multiplication, too_small)
{
    int D[6] = {2,2,2,2,1,1};
    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-3);
}

Test(Multiplication, more_cols)
{
    int D[6] = {2,3,2,2,2,2};
    int M[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(Multiplication, more_cols2)
{
    int D[6] = {2,3,2,2,1,1};
    int M[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-2);
}

Test(Multiplication, more_rows)
{
    int D[6] = {2,2,3,2,2,2};
    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(Multiplication, more_rows2)
{
    int D[6] = {2,2,3,2,1,1};
    int M[2][2] = {
        {1,1},
        {1,1}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[1][1];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-2);
}

Test(Multiplication, rectangles)
{
    int D[6] = {2,3,3,2,2,2};
    int M[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, diff_rect)
{
    int D[6] = {3,2,3,2,3,2};
    int M[3][2] = {
        {1,1},
        {1,1},
        {1,1}
    };

    int N[3][2] = {
        {2,2},
        {2,2},
        {2,2}
    };

    int A[3][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,-1);
}

Test(Multiplication, larger_square)
{
    int D[6] = {4,4,4,4,4,4};
    int M[4][4] = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };

    int N[4][4] = {
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2}
    };

    int A[4][4];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(Multiplication, larger_rect)
{
    int D[6] = {3,4,4,3,3,3};
    int M[3][4] = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };

    int N[4][3] = {
        {2,2,2},
        {2,2,2},
        {2,2,2},
        {2,2,2}
    };

    int A[3][3];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, square_matrix)
{
    int D[4] = {3,3,5,5};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[5][5];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, one_by_one)
{
    int D[4] = {1,1,3,3};

    int A[1][1] = {
        {1}
    };

    int DS[5][5];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, too_large)
{
    int D[4] = {3,3,6,6};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[6][6];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}

Test(DiagonalSum, too_small)
{
    int D[4] = {3,3,4,4};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[4][4];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, rectangle)
{
    int D[4] = {3,4,5,6};

    int A[3][4] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    int DS[5][6];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, too_small_rectangle)
{
    int D[4] = {3,4,5,5};

    int A[3][4] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    int DS[5][5];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, too_small_rectangle2)
{
    int D[4] = {3,4,4,6};

    int A[3][4] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    int DS[4][6];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,-1);
}

Test(DiagonalSum, too_large_rectangle)
{
    int D[4] = {3,4,5,7};

    int A[3][4] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    int DS[5][7];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}

Test(DiagonalSum, too_large_rectangle2)
{
    int D[4] = {3,4,6,6};

    int A[3][4] = {
        {1,2,3,4},
        {4,5,6,5},
        {7,8,9,6}
    };

    int DS[6][6];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,2);
}

Test(DiagonalSum, smallest_rect)
{
    int D[4] = {1,2,3,4};

    int A[3][4] = {
        {1,2}
    };

    int DS[3][4];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, smallest_rect2)
{
    int D[4] = {2,1,4,3};

    int A[2][1] = {
        {1},
        {2}
    };

    int DS[4][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, largerSquare)
{
    int D[4] = {5,5,7,7};

    int A[5][5] = {
        {1,1,1,1,1},
        {2,2,2,2,2},
        {3,3,3,3,3},
        {4,4,4,4,4},
        {5,5,5,5,5}
    };

    int DS[7][7];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}


Test(DiagonalSum, largerRect1)
{
    int D[4] = {5,6,7,8};

    int A[5][6] = {
        {1,1,1,1,1,1},
        {2,2,2,2,2,2},
        {3,3,3,3,3,3},
        {4,4,4,4,4,4},
        {5,5,5,5,5,5}
    };

    int DS[7][8];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}

Test(DiagonalSum, largerRect2)
{
    int D[4] = {6,5,8,7};

    int A[6][5] = {
        {1,1,1,1,1},
        {2,2,2,2,2},
        {3,3,3,3,3},
        {4,4,4,4,4},
        {5,5,5,5,5},
        {6,6,6,6,6}
    };

    int DS[8][7];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}
