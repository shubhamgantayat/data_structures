#include<stdio.h>
#include<stdlib.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main() {
    int n,*ar,i;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    ar = (int*)calloc(n,sizeof(int));
    printf("\nEnter array : ");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    mergesort(ar,0,n-1);
    printf("\nSorted array : ");
    for(i=0;i<n;i++)
        printf("%d\t",ar[i]);
    return 0;
}
void mergesort(int ar[],int l,int h) {
    int mid = (l + h)/2;
    if(l<h) {
        mergesort(ar,l,mid);
        mergesort(ar,mid+1,h);
        merge(ar,l,mid,h);
    }
}
void merge(int ar[],int l,int mid,int h) {
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int i,j,k=l,L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i] = ar[l+i];
    for(j=0;j<n2;j++)
        R[j] = ar[mid+1+j];
    i=0;
    j=0;
    while((i<n1) && (j<n2)) {
        if(L[i] < R[j])
            ar[k++] = L[i++];
        else
            ar[k++] = R[j++];
    }
    while(i<n1)
        ar[k++] = L[i++];
    while(j<n2)
        ar[k++] = R[j++];

}
