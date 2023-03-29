def selection_sort(A,n):

    for i in range(n - 1):
        iMin = i
        for j in range(i+1,n):
            if A[j] < A[iMin]:
                iMin = j
        if i != iMin:
            A[i], A[iMin] = A[iMin], A[i]


"A = [1, 8, -9, 5, 4, 3, 88]"
"selection_sort(A)"
"print(A)"
