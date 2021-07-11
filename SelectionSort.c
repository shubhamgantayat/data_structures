#include<stdio.h>
#include<stdlib.h>
void selectionSort(int [],int);
void swap(int*,int*);
int main() {
    int n,*p,i;
    printf("\nEnter n : ");
    scanf("%d",&n);
    p = (int*)calloc(n,sizeof(int));
    printf("\nEnter the array : ");
    for(i = 0;i<n;i++)
        scanf("%d",&p[i]);
    selectionSort(p,n);
    printf("\nAfter sorting : ");
    for(i = 0;i<n;i++)
        printf("%d\t",p[i]);
    return 0;
}
void selectionSort(int a[],int n) {
    int startpos,minpos,temp,i;
    for(startpos =0;startpos<n-1;startpos++) {
        minpos = startpos;
        for(i=minpos+1;i<n;i++) {
            if(a[i] < a[minpos])
                minpos = i;
        }
        swap(&a[startpos],&a[minpos]);
    }
}
void swap(int *x,int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
