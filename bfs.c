/*
BFS for Undirected Graph. 
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
    int ar[MAX];
    int front;
    int rear;
}queue;
void enqueue(queue*,int);
int dequeue(queue*);
void bfs(int [][MAX],int,int[],int[],int);
void print_path(int[],int,int);
void print(int[],int);
int main() {
    int G[MAX][MAX]={{0,1,0,0,1},
                     {1,0,1,1,1},
                     {0,1,0,1,0},
                     {0,1,1,0,1},
                     {1,1,0,1,0}};
    int n = 5,d[5],pi[5],s,i,v;
    printf("\nEnter source vertex : ");
    scanf("%d",&s);
    bfs(G,s,d,pi,n);
    printf("\nEnter destination vertex : ");
    scanf("%d",&v);
    printf("\nPath - ");
    print_path(pi,s,v);
    /* for(v = 0;v<n;v++) {
        printf("\nDestination : %d\n",v);
        print_path(pi,s,v);
        printf("\n");
    } 
    printf("\nOrder of traversal : ");
    print(d,n);*/
    return 0;
}

void print_path(int pi[],int s,int v) {
    if(v == s) {
        printf("%d ",s);
    }
    else if(pi[v] == -1) {
        printf("No path exists from s to v");
    }
    else {
        print_path(pi,s,pi[v]);
        printf("%d ",v);
    }
}

void bfs(int G[][MAX],int s,int d[],int pi[],int n) {
    queue q;
    q.front = -1;
    q.rear = -1;
    char color[n];
    int i,u;
    for(i = 0;i<n;i++) {
        color[i] = 'w';
        d[i] = -1;
        pi[i] = -1;
    }
    if(s >= n)
        return;
    color[s] = 'g';
    d[s] = 0;
    pi[s] = -1;
    enqueue(&q,s);
    while(q.front != -1) {
        u = dequeue(&q);
        for(i = 0;i<n;i++) {
            if(color[i] == 'w' && G[u][i] == 1) {
                color[i] = 'g';
                d[i] = d[u] + 1;
                pi[i] = u;
                enqueue(&q,i);
            }
        }
        color[u] = 'b';
    }
}

void enqueue(queue *q,int ele) {
    if(q->rear == MAX - 1) {
        printf("\nQueue is full");
        return;
    }
    if(q->front == -1) {
        q->front += 1;
    }
    q->rear ++;
    q->ar[q->rear] = ele;
}

int dequeue(queue *q) {
    int x;
    if(q->front == -1) {
        printf("\nQueue is empty");
        return -999;
    }
    else if(q->front == q->rear) {
        x = q->ar[q->front];
        q->front = -1;
        q->rear = -1;
        return x;
    }
    else {
        x = q->ar[q->front];
        q->front += 1;
        return x;
    }
}

void print(int d[],int n) {
    int sorted_d[n],sorted_v[n],i,j,tmp;
    for(i = 0;i<n;i++) {
        sorted_v[i] = i;
        sorted_d[i] = d[i];
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