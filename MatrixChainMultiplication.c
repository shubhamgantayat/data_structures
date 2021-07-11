#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define C 20
void matrix_chain_order(int[],int,int[][C],int[][C]);
void print_optimal_parens(int[][C],int,int);
int main() {
    int n,p[C],m[C][C],s[C][C],i;
    printf("\nEnter n : ");
    scanf("%d",&n);
    printf("\nEnter array : ");
    for(i = 0;i<n;i++)
        scanf("%d",&p[i]);
    matrix_chain_order(p,n,m,s);
    printf("\nOrder of multiplication : \n");
    print_optimal_parens(s,0,n-2);
    return 0;
}
void matrix_chain_order(int p[],int len,int m[][C],int s[][C]) {
    int n = len - 1;
    int i,j,l,k,q;
    for(i=0;i<n;i++) {
        m[i][i] = 0;
    }
    for(l = 1;l<n;l++) {
        for(i=0;i<n-l;i++) {
            j = i+l;
            m[i][j] = INT_MAX;
            for(k = i;k<j;k++) {
                q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q<m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int s[][C],int i,int j) {
    if(i == j) {
        printf(" A%d ",i+1);
    }
    else {
        printf("(");
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j]+1,j);
        printf(")");
    }
}
