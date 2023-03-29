#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>


#define Item(X, I, J, NCOL)      X[((J) + (I) * (NCOL))]

/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
void matmult(int* A, int* B, int* C, int l, int m, int n)
{
    for(int i=0; i<l; i++)
        for(int j=0; j<n; j++)
        {
            int sum = 0;
            for(int k=0; k<m; k++)
                sum += Item(A, i, k, m) * Item(B, k, j, n);
            Item(C, i, j, n) = sum;
        }
}



/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */
struct data1{
    int* A;
    int* B;
    int* C;
    int l;
    int m;
    int n;
    int i;
    int j;
} ;

void *version1(void *data)
{
    struct data1 *d=(struct data1 *)data;
    int *A=d->A,*B=d->B,*C=d->C,m=d->m,n=d->n,i=d->i,j=d->j;
    int sum = 0;
    for(int k=0; k<m; k++)
        sum += Item(A, i, k, m) * Item(B, k, j, n);
    Item(C, i, j, n) = sum;
    return NULL;
}

void matmult_v1(int* A, int* B, int* C, int l, int m, int n)
{
    int s=l*m*n;
    struct data1 data[s];
    pthread_t tid[s];
    int counter=0;
    for(int i=0; i<l; i++)
        for(int j=0; j<n; j++)
        {
            data[counter].A=A;
            data[counter].B=B;
            data[counter].C=C;
            data[counter].l=l;
            data[counter].m=m;
            data[counter].n=n;
            data[counter].i=i;
            data[counter].j=j;
            pthread_create(&tid[counter], NULL, version1, (void *)&data[counter]);
            ++counter;
        }
    for(int i=0;i<counter;i++)
    {
        pthread_join( tid[i], NULL );

    }

}



/*
 * matrix multiplication
 *     C = A*B
 *     A has l rows and m cols
 *     B has m rows and n cols
 *     C has l rows and n cols
 */

void *version2(void *data)
{
    struct data1 *d=(struct data1 *)data;
    int *A=d->A,*B=d->B,*C=d->C,m=d->m,n=d->n,i=d->i;
    for(int j=0; j<n; j++)
    {
        int sum = 0;
        for(int k=0; k<m; k++)
            sum += Item(A, i, k, m) * Item(B, k, j, n);
        Item(C, i, j, n) = sum;
    }
    return NULL;
}
void matmult_v2(int* A, int* B, int* C, int l, int m, int n)
{
    int s=l*m*n;
    struct data1 data[s];
    pthread_t tid[s];
    int counter=0;
    for(int i=0; i<l; i++)
    {
        data[counter].A=A;
        data[counter].B=B;
        data[counter].C=C;
        data[counter].l=l;
        data[counter].m=m;
        data[counter].n=n;
        data[counter].i=i;
        pthread_create(&tid[counter], NULL, version1, (void *)&data[counter]);
        ++counter;
    }
}
