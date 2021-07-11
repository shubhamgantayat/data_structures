#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char[],char[]);
int main() {
	char T[100],P[100];
	int d,q;
	printf("\nEnter text : ");
	scanf(" %[^\n]",T);
	printf("\nEnter pattern : ");
	scanf(" %[^\n]",P);
	search(T,P);
	return 0;
}
void search(char T[],char P[]) {
    int m,n,i,j;
    n = strlen(T);
    m = strlen(P);
    for(i = 0;i<n-m+1;i++) {
        for(j = 0;j<m;j++) {
            if(T[i+j] != P[j])
                break;
        }
        if(j == m) {
            printf("\nPattern found at index %d",i);
        }
    }
}

