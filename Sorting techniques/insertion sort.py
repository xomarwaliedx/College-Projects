def insertion_sort (A):
    for i in range(1, len(A)):
        key = A[i]
        current=i-1
        while current >= 0 and key < A[current]:
                A[current+1] = A[current]
                current=current-1
        A[current+1]=key

A=[2,1,9,8,5,3,4,6,7]
insertion_sort(A)
print(A)