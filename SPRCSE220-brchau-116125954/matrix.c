
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name:
 * SBU ID:
 */

#include "matrix.h"
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

/*----------------------------------------------------
  1. Sparse Matrix
----------------------------------------------------*/
int SparseMatrix(int D[2], int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])])
{

    int rows = D[0];
    int cols = D[1];
    int m = max(rows, cols);
    /*Used to store the value at a certain (row,col) of M*/
    int value;

    int nonZeroCount = 0;
    /*Initialize the array S with 0*/
    memset(S, 0, 3 * m * sizeof(int));

    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        value = *(*(M + i) + j);
        if(value){
          if(nonZeroCount >= m){
            return -1;
          }
          /*Used to set value of S, S's avlues are set even if there
           *the matrix is not sparce.
          */
          *(*(S)+nonZeroCount) = i;
          *(*(S+1)+nonZeroCount) = j;
          *(*(S+2)+nonZeroCount) = value;
          nonZeroCount++;
        }
      }
    }
    return nonZeroCount;
}


// /*----------------------------------------------------
//   2. Hadamard Product
// ----------------------------------------------------*/
int HadamardProduct(const int D[6],
                    const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]],
                    int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    int rows;
    int cols;

    int status;
    int mVal;
    int nVal;
    if(mRows == nRows && mCols == nCols){
      rows = mRows;
      cols = nCols;
      if(aRows < rows || aCols < cols){
        rows = min(aRows, rows);
        cols = min(aCols,cols);
        status = -3;
      }
      else if(aRows > rows || aCols > cols){
        status = 2;
      }
      else{
        status = 1;
      }
    }
    else{
      rows = min(mRows,nRows);
      cols = min(mCols,nCols);
      if(aRows < rows || aCols < cols){
        rows = min(aRows,rows);
        cols = min(aCols,cols);
        status = -2;
      }
      else{
        status = -1;
      }
    }
    memset(A, 0, aRows * aCols * sizeof(int));
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++ ){
        mVal = *(*(M + i) + j);
        nVal = *(*(N + i) + j);
        *(*(A + i) + j) = mVal * nVal;
      }
    }
    return status;
}


// /*----------------------------------------------------
//   3. Matrix Multiplication
// ----------------------------------------------------*/
int Multiplication(const int D[6],
                   const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]],
                   int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];

    int rows = mRows;
    int cols = nCols;
    /*Size of the rows and cols we will multiply*/
    int length;
    int status;
    int value;
    if(mCols != nRows){
      length = min(rows,cols);
      if(aRows < rows || aCols < cols){
        rows = min(aRows,rows);
        cols = min(aCols,cols);
        status = -2;
      }
      else{
        status = -1;
      }
    }
    else{
      length = mCols;
      if(aRows < rows || aCols < cols){
        rows = min(aRows,rows);
        cols = min(aCols,cols);
        status = -3;
      }
      else if(aRows > rows || aCols > cols){
        status = 2;
      }
      else{
        status = 1;
      }
    }
    memset(A, 0, aRows * aCols * sizeof(int));
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        value = 0;
        for(int n = 0; n < length; n++){
          value += *(*(M+i)+n) * *(*(N+n)+j);
        }
        *(*(A+i)+j) = value;
      }
    }
    return status;
}


// /*----------------------------------------------------
//   4. Diagonal Sum
// ----------------------------------------------------*/
int DiagonalSum(const int D[4],
                const int A[D[0]][D[1]],
                int DS[D[2]][D[3]])
{

    int rows = D[0];
    int cols = D[1];

    int dsRows = D[2];
    int dsCols = D[3];
    
    int status;
    int value = 0;
    int diagonalSize = min(rows,cols);
    /*Counter variable for for loops*/
    int i;
    int numOfRows = min(rows, dsRows - 2);
    int numOfCols = min(cols, dsCols);
    memset(DS, 0, dsRows * dsCols * sizeof(int));
    if(dsRows < rows + 2 || dsCols < cols + 2){
      if(dsRows < 1){
        return -1;
      }
      status = -1;
    }
    else if(dsRows > rows + 2 || dsCols > cols + 2){
      status = 2;
    }
    else{
      status = 1;
    }
    if(dsCols > 0){
      for(i = 0; i < diagonalSize; i++){
        value += *(*(A+i)+i);
      }
      *(*DS) = value;
      value = 0;
    }
    if(dsCols > 1){
      for(i = 0; i < diagonalSize;i++){
        value += *(*(A+i)+(cols-i-1));
      }
      *(*(DS)+1) = value;
    }
    if(dsRows > 1){
      for(i = 0; i < numOfCols;i++){
        value = 0;
        for(int j = 0; j < rows; j++){
          value += *(*(A+j)+i);
        }
        *(*(DS+1)+i) = value;
      }
    }
    if(dsCols > 0){
      for(i = 0; i < numOfRows;i++){
        value = 0;
        for(int j = 0; j < cols; j++){
          value += *(*(A+i)+j);
        }
        *(*(DS+i+2)) = value;
      }
    }
    return status;
}
