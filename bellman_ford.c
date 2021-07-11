#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
typedef struct {
    int d[MAX];
    int pi[MAX];
}vertex;
void initialize_single_source(int[][MAX],int,int,vertex*);
void relax(int,int,int[][MAX],vertex*);
int bellman_ford(int[][MAX],int,int,vertex*);
void print_path(vertex,int,int);
int main() {
    vertex vt;
    int s = 0,v,n = 5,i;
    int G[][MAX] = {{INT_MAX,6,INT_MAX,7,INT_MAX},
                    {INT_MAX,INT_MAX,5,8,-4},
                    {INT_MAX,-2,INT_MAX,INT_MAX,INT_MAX},
                    {INT_MAX,INT_MAX,-3,INT_MAX,9},
                    {2,INT_MAX,7,INT_MAX,INT_MAX}};
    printf("\nEnter source : ");
    scanf("%d",&s);
    if(bellman_ford(G,n,s,&vt) == 0) {
        printf("\nEnter destination : ");
        scanf("%d",&v);
        printf("\nPath : ");
        print_path(vt,s,v);
        printf("\n");
    }
    else {
        printf("\nNegative cycle exist\n");
    }
    return 0;
}

void print_path(vertex vt,int s,int v) {
    if(v == s) {
        printf("%d  ",s);
    }
    else if(vt.pi[v] == -1) {
        printf("No path exists from s to v");
    }
    else {
        print_path(vt,s,vt.pi[v]);
        printf("%d  ",v);
    }
}

int bellman_ford(int G[][MAX],int n,int s,vertex *vt) {
    int i,j,k,u,v;
    initialize_single_source(G,n,s,vt);
    for(i = 0;i<n - 1;i++) {
        for(j = 0;j<n;j++) {
            for(k = 0;k<n;k++) {
                if(G[j][k] != INT_MAX) {
                    relax(j,k,G,vt);
                }
            }
        }
    }
    for(i = 0;i<n;i++) {
        for(j = 0;j<n;j++) {
            if(vt->d[j] > vt->d[i] + G[i][j] && G[i][j] != INT_MAX) {
                return -1;
            }
        }
    }
    return 0;
}

void initialize_single_source(int G[][MAX],int n,int s,vertex *vt) {
    int i;
    for(i = 0;i<n;i++) {
        vt->d[i] = INT_MAX;
        vt->pi[i] = -1;
    }
    vt->d[s] = 0;
}

void relax(int u,int v,int G[][MAX],vertex *vt) {
    if(vt->d[v] > vt->d[u] + G[u][v]) {
        vt->d[v] = vt->d[u] + G[u][v];
        vt->pi[v] = u;
    }
}