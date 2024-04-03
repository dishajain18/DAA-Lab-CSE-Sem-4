#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i, int * opCount) {
    int k, v, heapify,j;
    k = i;
    v = arr[k];
    heapify = 0;
    while (heapify == 0 && 2*k <= n) {
        j = 2*k ;
        if (j < n)
            if (arr[j] < arr[j+1])
                j = j + 1;
        if (v >= arr[j])
            heapify = 1;
        else {
            arr[k] = arr[j];
            k = j;
        }
        *opCount = *opCount + 1;
    }
    arr[k] = v;
}

void heapBottomUp(int arr[], int n, int * opCount) {
    int i, v, k, j;
    for(i = (n/2); i >= 1; i--) 
        heapify(arr,n,i,opCount);
}

void main() {
    int n,opCount = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter Elements: ");
    arr[0]=0;
    for(int i = 1; i<=n; i++)
        scanf("%d", &arr[i]);
    
    heapBottomUp(arr,n,&opCount);
    printf("Heapified array: ");
    for(int j=1;j<=n;j++)
        printf("%d ",arr[j]);
    for(int i=0;i<=n-1;i++) {
        int temp = arr[1];
        arr[1] = arr[n-i];
        arr[n-i] = temp;
        
        heapify(arr,n-i-1,1,&opCount);
    }
    printf("\nSorted array: ");
    for(int j=1;j<=n;j++)
        printf("%d ",arr[j]);
    printf("\nOpCount: %d\n",opCount);
}
