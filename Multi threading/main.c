#include<stdio.h>
#include<stdlib.h>
#include <time.h>


#define Item(X, I, J, NCOL)      X[((J) + (I) * (NCOL))]

extern void matmult(int* A, int* B, int* C, int l, int m, int n);
extern void matmult_v1(int* A, int* B, int* C, int l, int m, int n);
extern void matmult_v2(int* A, int* B, int* C, int l, int m, int n);
void populateMatrix(int *X, int nrow, int ncol);
void printMatrix(int *X, int nrow, int ncol);
int main()
{
    clock_t t;
    int l=200, m=200, n=200;
    int *A = (int*)malloc(l*m*sizeof(int));
    int *B = (int*)malloc(m*n*sizeof(int));
    int *C = (int*)malloc(l*n*sizeof(int));
    
    populateMatrix(A, l, m);
    populateMatrix(B, m, n);
    
    t = clock();
    
    matmult(A, B, C, l, m, n);
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("took %f seconds to execute \n", time_taken);
    
//    printMatrix(A, l, m);
//    printMatrix(B, m, n);
//    printMatrix(C, l, n);
    
    printf("\n\ndone\n\n");
    
    t = clock();

    matmult_v1(A, B, C, l, m, n);
    
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("took %f seconds to execute \n", time_taken);
    
//    printMatrix(A, l, m);
//    printMatrix(B, m, n);
//    printMatrix(C, l, n);
    
    printf("\n\ndone2\n\n");
    t = clock();

    matmult_v2(A, B, C, l, m, n);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("took %f seconds to execute \n", time_taken);
//
//    printMatrix(A, l, m);
//    printMatrix(B, m, n);
//    printMatrix(C, l, n);
//
    
    free(A);
    free(B);
    free(C);
    
    
    return 0;
}


/*
 * fill in a matrix with random numbers
 */
void populateMatrix(int *X, int nrow, int ncol)
{
    for(int i=0; i<nrow; i++)
        for(int j=0; j<ncol; j++)
            Item(X, i, j, ncol) = (((long)X)
                                   + ((long)&nrow)
                                   + ((long)&nrow)
                                   - (~(i*ncol+nrow)
                                      +(j*nrow+ncol))
                                   ) %29311%10;
}



/*
 * prints a matrix on stdout
 */
void printMatrix(int *X, int nrow, int ncol)
{
    for(int i=0; i<nrow; i++)
    {
        for(int j=0; j<ncol; j++)
            printf("%d\t", Item(X, i, j, ncol));
        printf("\n");
    }
    printf("\n");
    printf("\n");
}
