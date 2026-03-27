
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 *
 * Name: Brian Chau
 * SBU ID: 116125954
 */

 Tests are located in test_matrix.c and functions are located in test_matrix.c

 For all the functions, they check if any of the values in the array D is less than one which would indicate that 
 one of dimensions is either zero or negative which is invalid. In this case the function will return a -4 and not
 do anything.

 Additionally, all functions check for null values and if any the arrays passed are null, the function will return
 a -5 and not do anything. 

 With my tests, they do not check for a null D because this causes the function to crash. This is because the function
 definition uses the values of D so I cannot check for null before they are used by C to fill in the function defintiion.
 Therefore, having D be a null array will cause the program to crash and I can't do anything to stop it.

For diagonalSum, since the anti-diagonal is only defined for square matrices, the anti-diagonnal is not calculated for 
rectangular matrices as the Professor says on Piazza.

For all my functions, the matrix that stores the result is cleared and set to 0. So, even if the matrix is too big,
the indices that don't store anything will be set to 0.