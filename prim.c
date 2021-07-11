#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    int src;
    int pi;
    int key;
}vertex;
void min_heapify(vertex[],int,int);
int heap_extract_min(vertex[],int*);
void min_heap_insert(vertex[],int*,int);
void heap_decrease_key(vertex[],int,int,int);
void swap(vertex*,vertex*);
int left(int);
int right(int);
int parent(int);
void mst_prim(int[][MAX],int,int,vertex[]);

int main() {
    int G[][MAX] = {{99999,4,99999,99999,99999,99999,99999,8,99999},
                    {4,99999,8,99999,99999,99999,99999,11,99999},
                    {99999,8,99999,7,99999,4,99999,99999,2},
                    {99999,99999,7,99999,9,14,99999,99999,99999},
                    {99999,99999,99999,9,99999,10,99999,99999,99999},
                    {99999,99999,4,14,10,99999,2,99999,99999},
                    {99999,99999,99999,99999,99999,2,99999,1,6},
                    {8,11,99999,99999,99999,99999,1,99999,7},
                    {99999,99999,2,99999,99999,99999,6,7,99999}};
    int n = 9,i;
    vertex v[MAX];
    mst_prim(G,n,0,v);
    printf("\nv1\tv2\tweight");
    for(i = 0;i < n - 1;i++) {
        printf("\n%d\t%d\t%d",v[i].src,v[i].pi,v[i].key);
    }
    printf("\n");
    return 0;
}

void mst_prim(int G[][MAX],int n,int r,vertex v[]) {
    int i,u,heapsize = 0,d;
    for(i = 0;i<n;i++) {
        v[i].key = 99999;
        v[i].src = i;
        v[i].pi = -1;
    }
    v[r].key = 0;
    for(i = 0;i<n;i++) {
        min_heap_insert(v,&heapsize,v[i].key);
    }
    while(heapsize != 0) {
        u = heap_extract_min(v,&heapsize);
        for(i = 0;i<heapsize;i++) {
            if(G[v[u].src][v[i].src] < v[i].key) {
                v[i].pi = v[u].src;
                heap_decrease_key(v,heapsize,i,G[v[u].src][v[i].src]);
            }
        }
    }
}

void min_heap_insert(vertex v[],int *heapsize,int key) {
    v[*heapsize].key = 99999;
    *heapsize = *heapsize + 1;
    heap_decrease_key(v,*heapsize,*heapsize - 1,key);
}

void heap_decrease_key(vertex v[],int heapsize,int i,int key) {
    if(v[i].key < key) {
        return;
    }
    v[i].key = key;
    while(i > 0 && v[parent(i)].key > key) {
        swap(&v[i],&v[parent(i)]);
        i = parent(i);
    }
}

int heap_extract_min(vertex v[],int *heapsize) {
    if(*heapsize < 0) {
        return -1;
    }
    *heapsize = *heapsize - 1;
    swap(&v[0],&v[*heapsize]);
    min_heapify(v,*heapsize,0);
    return *heapsize;
}

void min_heapify(vertex v[],int heapsize,int pos) {
    int l,r,min;
    l = left(pos);
    r = right(pos);
    min = pos;
    if(l < heapsize && v[l].key < v[min].key)
        min = l;
    if(r < heapsize && v[r].key < v[min].key)
        min = r;
    if(min != pos) {
        swap(&v[min],&v[pos]);
        min_heapify(v,heapsize,min);
    }
}

void swap(vertex *v1,vertex *v2) {
    vertex tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}