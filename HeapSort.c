#include<stdio.h>
#include<stdlib.h>
void max_heapify(int[],int,int);
void build_max_heap(int[],int);
void heapsort(int[],int);
void swap(int*,int*);
int left(int);
int right(int);
int main() {
    int n,*ar,i;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    ar = (int*)calloc(n,sizeof(int));
    printf("\nEnter array : ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    heapsort(ar,n);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
    return 0;
}
void max_heapify(int ar[],int heapSize,int pos) {
    int l = left(pos);
    int r = right(pos);
    int largest = pos;
    if((l<heapSize) && (ar[l] > ar[largest]))
        largest = l;
    if((r<heapSize) && (ar[r] > ar[largest]))
        largest = r;
    if(largest != pos) {
        swap(&ar[pos],&ar[largest]);
        max_heapify(ar,heapSize,largest);
    }
}

void build_max_heap(int ar[],int arraySize) {
    int i;
    for(i = arraySize/2-1;i>=0;i--) {
        max_heapify(ar,arraySize,i);
    }
}

void heapsort(int ar[],int arraySize) {
    int i;
    build_max_heap(ar,arraySize);
    for(i = arraySize-1;i>=1;i--) {
        swap(&ar[i],&ar[0]);
        max_heapify(ar,i,0);
    }
}

void swap(int *x,int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}
