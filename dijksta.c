#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct {
    int src;
    int d;
    int pi;
}vertex;
int left(int);
int right(int);
int parent(int);
void min_heap_insert(vertex[],int*,int,int);
void heap_decrease_key(vertex[],int,int,int);
int heap_extract_min(vertex[],int*);
void min_heapify(vertex[],int,int);
void swap(vertex*,vertex*);
void relax(int,int,int[][MAX],int,vertex[]);
void initialize_single_source(int[][MAX],int,int,vertex[]);
void dijkstra(int[][MAX],int,int,vertex[]);
void print_path(vertex[],int,int);
int main() {
    int G[][MAX] = {{99999,10,99999,5,99999},
                    {99999,99999,1,2,99999},
                    {99999,99999,99999,99999,4},
                    {99999,3,9,99999,2},
                    {7,99999,6,99999,99999}};
    int n = 5,s,v,i;
    vertex vt[MAX],vert[MAX];
    printf("\nEnter source : ");
    scanf("%d",&s);
    dijkstra(G,n,s,vt);
    for(i = 0;i<n;i++) {
        vert[vt[i].src] = vt[i];
    }
    /* printf("\nsrc\td\tpi");
    for(i = 0;i<n;i++) {
        printf("\n%d\t%d\t%d",vert[i].src,vert[i].d,vert[i].pi);
    }  */
    printf("\nEnter destination : ");
    scanf("%d",&v);
    printf("\nPath - ");
    print_path(vert,s,v);
    printf("\nCost of path : %d\n",vert[v].d);
    return 0;
}

void print_path(vertex vt[],int s,int v) {
    if(v == s) {
        printf("%d  ",s);
    }
    else if(vt[v].pi == -1) {
        printf("No path exists from s to v");
    }
    else {
        print_path(vt,s,vt[v].pi);
        printf("%d  ",v);
    }
}

void dijkstra(int G[][MAX],int n,int s,vertex vt[]) {
    int heapsize = 0,u,v,i;
    initialize_single_source(G,n,s,vt);
    for(i = 0;i<n;i++)
        min_heap_insert(vt,&heapsize,i,vt[i].d);
    while(heapsize != 0) {
        u = heap_extract_min(vt,&heapsize);
        for(v = 0;v<n;v++) {
            if(G[vt[u].src][vt[v].src] != 99999) {
                relax(u,v,G,heapsize,vt);
            }
        }
    }
}

void initialize_single_source(int G[][MAX],int n,int s,vertex vt[]) {
    int i;
    for(i = 0;i<n;i++) {
        vt[i].src = i;
        vt[i].d = 99999;
        vt[i].pi = -1;
    }
    vt[s].d = 0;
}

void relax(int u,int v,int G[][MAX],int heapsize,vertex vt[]) {
    int key;
    if(vt[v].d > vt[u].d + G[vt[u].src][vt[v].src]) {
        vt[v].pi = vt[u].src;
        key = vt[u].d + G[vt[u].src][vt[v].src];
        heap_decrease_key(vt,heapsize,v,key);
    }
}

void heap_decrease_key(vertex vt[],int heapsize,int i,int key) {
    if(key > vt[i].d)
        return;
    vt[i].d = key;
    while(i > 0 && vt[parent(i)].d > vt[i].d) {
        swap(&vt[i],&vt[parent(i)]);
        i = parent(i);
    }
}

void min_heap_insert(vertex vt[],int *heapsize,int src,int key) {
    vt[*heapsize].d = 99999;
    vt[*heapsize].src = src;
    *heapsize = *heapsize + 1;
    heap_decrease_key(vt,*heapsize,*heapsize - 1,key);
}

int heap_extract_min(vertex vt[],int *heapsize) {
    int n = *heapsize,i;
    vertex min;
    if(n < 0) {
        printf("\nUnderflow");
    }
    min = vt[0];
    n = n - 1;
    *heapsize = n;
    swap(&vt[0],&vt[*heapsize]);
    min_heapify(vt,n,0);
    return n;
}

void min_heapify(vertex vt[],int heapsize,int i) {
    int l,r,smallest;
    l = left(i);
    r = right(i);
    smallest = i;
    if(l < heapsize && vt[l].d < vt[smallest].d)
        smallest = l;
    if(r < heapsize && vt[r].d < vt[smallest].d)
        smallest = r;
    if(smallest != i) {
        swap(&vt[i],&vt[smallest]);
        min_heapify(vt,heapsize,smallest);
    }
}

void swap(vertex *v1,vertex *v2) {
    vertex v = *v1;
    *v1 = *v2;
    *v2 = v;
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