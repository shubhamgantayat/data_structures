/*
DFS for Directed Graph.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    int d[MAX];
    int pi[MAX];
    char color[MAX];
    int f[MAX];
}vertex;
void dfs(int[][MAX],int,vertex*);
void dfs_visit(int[][MAX],int,vertex*,int,int*);
void print(vertex,int);
int main() {
    int G[MAX][MAX]={{0,0,0,0,0,0,0},
                     {0,0,1,1,0,0,0},
                     {0,1,0,0,1,0,0},
                     {0,1,0,0,1,0,0},
                     {0,0,1,1,0,1,1},
                     {0,0,0,0,1,0,0},
                     {0,0,0,0,1,0,0}};
    int n = 7,i;
    vertex v;
    dfs(G,n,&v);
    /* printf("\n%s\t%s\t%s\t%s","v","pi","d","f");
    printf("\n____________________________");
    for(i = 0;i<n;i++) {
        if(v.pi[i] != -1)
            printf("\n%d\t%d\t%d\t%d",i,v.pi[i],v.d[i],v.f[i]);
        else
            printf("\n%d\t%-8s%d\t%d",i,"NIL",v.d[i],v.f[i]);
    }
    printf("\n"); */
    printf("\nOrder of traversal : ");
    print(v,n);
    return 0;
}

void dfs(int G[][MAX],int n,vertex *v) {
    int i,time;
    for(i = 0;i<n;i++) {
        v->color[i] = 'w';
        v->pi[i] = -1;
    }
    time = 0;
    for(i = 0;i<n;i++) {
        if(v->color[i] == 'w') {
            dfs_visit(G,n,v,i,&time);
        }
    }
}

void dfs_visit(int G[][MAX],int n,vertex *v,int u,int *time) {
    int i;
    v->color[u] = 'g';
    *time = *time + 1;
    v->d[u] = *time;
    for(i = 0;i<n;i++) {
        if(v->color[i] == 'w' && G[u][i] == 1) {
            v->pi[i] = u;
            dfs_visit(G,n,v,i,time);
        }
    }
    v->color[u] = 'b';
    *time = *time + 1;
    v->f[u] = *time;
}

void print(vertex v,int n) {
    int sorted_d[n],sorted_v[n],i,j,tmp;
    for(i = 0;i<n;i++) {
        sorted_v[i] = i;
        sorted_d[i] = v.d[i];
    }
    for(i = 0;i<n-1;i++) {
        for(j = 0;j<n-1-i;j++) {
            if(sorted_d[j] > sorted_d[j+1]) {
                tmp = sorted_d[j];
                sorted_d[j] = sorted_d[j+1];
                sorted_d[j+1] = tmp;
                tmp = sorted_v[j];
                sorted_v[j] = sorted_v[j+1];
                sorted_v[j+1] = tmp;
            }
        }
    }
    for(i = 0;i<n-1;i++) {
        printf("%d --> ",sorted_v[i]);
    }
    printf("%d\n",sorted_v[i]);
}