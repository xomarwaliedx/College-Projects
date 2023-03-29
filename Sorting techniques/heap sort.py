def max_heapify(A,i):
    l=2i
    r=2i+1
    largest=i
    if l<len(A) and A[l]>A[i]:
        largest=l
    if r<len(A) and A[r]>A[i]:
        largest=r
    if largest!=i:
        A[i],A[largest]=A[largest],A[i]
        max_heapify(A,largest)
def build_max_heap(A):
    for i in range(len(A)/2,1):
        max_heapify(A,i)
def heap_sort(A):
    build_max_heap(A)
    for i in range(len(A),2):
