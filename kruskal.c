#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    int v1;
    int v2;
    int weight;
}edge;
typedef struct {
    int parent;
    int rank;
}set;
void make_set(set[],int);
void union_sets(set[],int,int);
void link(set[],int,int);
int find_set(set[],int);
void build_max_heap(edge[],int);
void max_heapify(edge[],int,int);
void heapsort(edge[],int);
int left(int);
int right(int);
void swap(edge*,edge*);
void mst_kruskal(edge[],int,int);
int main() {
    int m = 9,n = 0,i,j;
    edge e[MAX];
    int G[][MAX] = {{99999,4,99999,99999,99999,99999,99999,8,99999},
                    {4,99999,8,99999,99999,99999,99999,11,99999},
                    {99999,8,99999,7,99999,4,99999,99999,2},
                    {99999,99999,7,99999,9,14,99999,99999,99999},
                    {99999,99999,99999,9,99999,10,99999,99999,99999},
                    {99999,99999,4,14,10,99999,2,99999,99999},
                    {99999,99999,99999,99999,99999,2,99999,1,6},
                    {8,11,99999,99999,99999,99999,1,99999,7},
                    {99999,99999,2,99999,99999,99999,6,7,99999}};
    for(i = 0;i<m;i++) {
        for(j = i+1;j<m;j++) {
            if(G[i][j] < 99999) {
                e[n].v1 = i;
                e[n].v2 = j;
                e[n].weight = G[i][j];
                n++;
            }
        }
    }
    mst_kruskal(e,n,m);
    printf("\n");
    return 0;
}

void mst_kruskal(edge e[],int n,int m) {
    // m is total no. of vertices
    // n is total no. of edges
    int i,k = 0,l;
    edge A[n];
    set sets[m];
    for(i = 0;i < m;i++) {
        make_set(sets,i);
    }
    heapsort(e,n);
    for(i = 0;i<n;i++) {
        if(find_set(sets,e[i].v1) != find_set(sets,e[i].v2)) {
            A[k] = e[i];
            k++;
            union_sets(sets,e[i].v1,e[i].v2);
        }
    }
    printf("\nv1\tv2\tweight");
    for(i = 0;i<k;i++) {
        printf("\n%d\t%d\t%d",A[i].v1,A[i].v2,A[i].weight);   
    }
}
void heapsort(edge e[],int heapsize) {
    int i;
    build_max_heap(e,heapsize);
    for(i = heapsize - 1;i>=0;i--) {
        swap(&e[i],&e[0]);
        max_heapify(e,i,0);
    }
}

void build_max_heap(edge e[],int heapsize) {
    int i;
    for(i = heapsize/2 - 1;i >= 0;i--) {
        max_heapify(e,heapsize,i);
    }
}

void max_heapify(edge e[],int heapsize,int pos) {
    int l,r,max;
    l = left(pos);
    r = right(pos);
    max = pos;
    if(l < heapsize && e[l].weight > e[max].weight)
        max = l;
    if(r < heapsize && e[r].weight > e[max].weight)
        max = r;
    if(max != pos) {
        swap(&e[pos],&e[max]);
        max_heapify(e,heapsize,max);
    }
}

void make_set(set sets[],int x) {
    sets[x].parent = x;
    sets[x].rank = 0;
}

void union_sets(set sets[],int x,int y) {
    link(sets,find_set(sets,x),find_set(sets,y));
}

void link(set sets[],int x,int y) {
    if(sets[x].rank > sets[y].rank)
        sets[y].parent = x;
    else    
        sets[x].parent = y;
    if(sets[x].parent == sets[y].parent)
        sets[y].rank += 1;
}

int find_set(set sets[],int x) {
    if(x != sets[x].parent) {
        sets[x].parent = find_set(sets,sets[x].parent);
    }
    return sets[x].parent;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void swap(edge *e1,edge *e2) {
    edge tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}