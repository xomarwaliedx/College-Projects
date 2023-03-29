def merge(A,left,mid,right):
    nL=mid-left+1
    nR=right-mid
    l=[None]*nL
    r=[None]*nR
    for i in range(0,nL):
        l[i]=A[left+i]
    for j in range(0,nR):
        r[j]=A[mid+1+j]
    i=0
    j=0
    k=left
    while i<nL and j<nR:
        if l[i]<=r[j]:
            A[k]=l[i]
            i=i+1
            k=k+1
        else:
            A[k]=r[j]
            j=j+1
            k=k+1
    while(i<nL):
        A[k]=l[i]
        i=i+1
        k=k+1
    while(j<nR):
        A[k]=r[j]
        j=j+1
        k=k+1
def mergesort(A,left,right):
    if left<right:
        mid=(left+right)//2
        mergesort(A,left,mid)
        mergesort(A, mid+1, right)
        merge(A,left,mid,right)

A=[5,6,2,7,8,-96,41,0,96]
n=len(A)
mergesort(A,0,n-1)
print(A)