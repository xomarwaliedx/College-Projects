def merge(A, left, mid, right):
    nL = mid - left + 1
    nR = right - mid
    l = [None] * nL
    r = [None] * nR
    for i in range(0, nL):
        l[i] = A[left + i]
    for j in range(0, nR):
        r[j] = A[mid + 1 + j]
    i = 0
    j = 0
    k = left
    while i < nL and j < nR:
        if l[i] <= r[j]:
            A[k] = l[i]
            i = i + 1
            k = k + 1
        else:
            A[k] = r[j]
            j = j + 1
            k = k + 1
    while (i < nL):
        A[k] = l[i]
        i = i + 1
        k = k + 1
    while (j < nR):
        A[k] = r[j]
        j = j + 1
        k = k + 1


def selection_sort(A):
    n = len(A)
    for i in range(n - 1):
        iMin = i
        for j in range(i + 1, n):
            if A[j] < A[iMin]:
                iMin = j
        if i != iMin:
            A[i], A[iMin] = A[iMin], A[i]


def hybrid(A, left, right, threshold):
    if right - left > threshold - 1:
        mid = (left + right) // 2
        hybrid(A, left, mid, threshold)
        hybrid(A, mid + 1, right, threshold)
        merge(A, left, mid, right)
    else:
        selection_sort(A)


A = [5, 6, 2, 7, 8, -96, 41, 0, 96, 894, 96, -8, 87, 85, 35]
n = len(A)
hybrid(A, 0, n - 1, 6)
print(A)
