#include<stdio.h>
#include<stdlib.h>
#define MAX 8
void putQueen(int[][MAX],int,int);
void display(int[][MAX],int);
int main() {
    int n,chess[MAX][MAX],i,j;
    printf("\nEnter n : ");
    scanf("%d",&n);
    for(i = 0;i<n;i++) {
        for(j = 0;j<n;j++)
            chess[i][j] = 0;
    }
    putQueen(chess,n,0);
    printf("\n");
    return 0;
}

void putQueen(int chess[][MAX],int n,int row) {
    int i,j,k,left_diagonal,right_diagonal,col;
    for(i = 0;i<n;i++) {
        left_diagonal = 0;
        right_diagonal = 0;
        col = 0;
        for(j = row - 1,k = i - 1;j>=0 && k>=0;j--,k--) {
            if(chess[j][k] == 1) {
                left_diagonal = 1;
            }
        }
        for(j = row - 1,k = i + 1;j>=0 && k<n;j--,k++) {
            if(chess[j][k] == 1) {
                right_diagonal = 1;
            }
        }
        for(j = 0;j<n;j++) {
            if(chess[j][i] == 1) {
                col = 1;
            }
        }
        if(col == 0 && left_diagonal == 0 && right_diagonal == 0) {
            
            chess[row][i] = 1;
            if(row != n-1)
                putQueen(chess,n,row+1);
            else {
                printf("\n");
                display(chess,n);
            }
        }
        chess[row][i] = 0;
    }
}

void display(int chess[][MAX],int n) {
    int i,j,ar[n];
    for(i = 0;i<n;i++) {
        for(j = 0;j<n;j++) {
            if(chess[i][j] == 1) {
                ar[i] = j + 1;
            }
        }
    }
    for(i = 0;i<n;i++) {
        printf("%d\t",ar[i]);
    }
}