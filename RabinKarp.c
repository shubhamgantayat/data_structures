#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void rabin_karp_matcher(char[],char[],int,int);
int main() {
    char P[100],T[100];
    int d,q;
    d = 256;
    q = 101;
    printf("\nEnter text : ");
    scanf(" %[^\n]",T);
    printf("\nEnter pattern : ");
    scanf(" %[^\n]",P);
    rabin_karp_matcher(T,P,d,q);
    return 0;
}

void rabin_karp_matcher(char T[],char P[],int d,int q) {
    int m,n,i,p,t,h;
    n = strlen(T);
    m = strlen(P);
    h = pow(d,m-1);
    h = 1;
    p = 0;
    t = 0;
    for(i = 0;i<m-1;i++) {
        h = (h*d)%q;
    }
    for(i = 0;i<m;i++) {
        p = ((d * p) + P[i])%q;
        t = ((d * t) + T[i])%q;
    }
    for(i = 0;i<=n-m;i++) {
        if(p == t) {
            printf("\nPattern at index %d",i);
        }
        if(i<n-m) {
            t = (d * (t - T[i]*h) + T[i+m])%q;
            if(t<0)
                t = t+q;
        }
    }
}
