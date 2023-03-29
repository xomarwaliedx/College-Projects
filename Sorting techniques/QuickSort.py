import random

def RandQuickSort(a, p, r):
    if p < r:
        q = randomizedPartition(a, p, r)
        RandQuickSort(a, p, q - 1)
        RandQuickSort(a, q + 1, r)

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