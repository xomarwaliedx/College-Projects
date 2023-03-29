import random
def RandQuickSort(A, p, r,k):
    if p < r:
        q = randomizedPartition(A, p, r)
        if q+1==k:
            print(A[q])
            return
        elif q+1>k:
            RandQuickSort(A, p, q - 1,k)
        else:
            RandQuickSort(A, q + 1, r,k)
    elif p==r and p+1==k:
        print(A[p])
        return

def randomizedPartition(a, p, r):
    i = random.randint(p, r)

    a[r], a[i] = a[i], a[r]
    return partition(a, p, r)

def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):

        if A[j] <= x:
            i = i + 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1

A=[0,17, 5 ,4 ,3 ,2]

RandQuickSort(A,0,5,1)
print(A)