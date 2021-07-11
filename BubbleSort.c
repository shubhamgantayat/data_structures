#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int [],int);
void swap(int*,int*);
int main() {
    int n,*p,i;
    printf("\nEnter n : ");
    scanf("%d",&n);
    p = (int*)calloc(n,sizeof(int));
    printf("\nEnter the array : ");
    for(i = 0;i<n;i++)
        scanf("%d",&p[i]);
    bubbleSort(p,n);
    printf("\nAfter sorting : ");
    for(i = 0;i<n;i++)
        printf("%d\t",p[i]);
    return 0;
}
void swap(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int ar[],int n) {
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(ar[j] > ar[j+1])
                swap(&ar[j],&ar[j+1]);
}
