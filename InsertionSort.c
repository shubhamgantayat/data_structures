#include<stdio.h>
#include<stdlib.h>
void insertionSort(int[],int);
int main() {
    int n,*p,i;
    printf("\nEnter n : ");
    scanf("%d",&n);
    p = (int*)calloc(n,sizeof(int));
    printf("\nEnter the array : ");
    for(i = 0;i<n;i++)
        scanf("%d",&p[i]);
    insertionSort(p,n);
    printf("\nAfter sorting : ");
    for(i = 0;i<n;i++)
        printf("%d\t",p[i]);
    return 0;
}
void insertionSort(int ar[],int n) {
    int i,j,key;
    for(i = 1;i<n;i++) {
        key = ar[i];
        j = i-1;
        while(j>=0 && ar[j]>key) {
            ar[j+1] = ar[j];
            j = j-1;
        }
        ar[j+1] = key;
    }
}
