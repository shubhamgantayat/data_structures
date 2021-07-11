#include<stdio.h>
#include<stdlib.h>
int partition(int[],int,int);
void quicksort(int[],int,int);
void swap(int*,int*);
int main() {
    int n,*ar,i;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    ar = (int*)calloc(n,sizeof(int));
    printf("\nEnter array : ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    quicksort(ar,0,n-1);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
    return 0;
}
void swap(int *x,int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void quicksort(int ar[],int l,int h) {
    int pivot;
    if(l<h) {
        pivot = partition(ar,l,h);
        quicksort(ar,l,pivot-1);
        quicksort(ar,pivot+1,h);
    }
}
int partition(int ar[],int l,int h) {
    int pivot = h;
    int k = l-1;
    int i;
    for(i=l;i<h;i++) {
        if(ar[i] < ar[pivot]) {
            k++;
            swap(&ar[i],&ar[k]);
        }
    }
    swap(&ar[k+1],&ar[pivot]);
    return k+1;
}
