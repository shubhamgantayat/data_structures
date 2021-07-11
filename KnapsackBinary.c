#include<stdio.h>
#include<stdlib.h>
typedef struct {
    float weight;
    float value;
}item;
float knapsack(item[],int,float);
float max(float a,float b);
int main() {
    int n,i;
    float W;
    item *items;
    printf("\nEnter weight of knapsack : ");
    scanf("%f",&W);
    printf("\nEnter no. of items : ");
    scanf("%d",&n);
    items = (item*)calloc(n,sizeof(item));
    for(i = 0;i<n;i++) {
        printf("\nEnter value : ");
        scanf("%f",&items[i].value);
        printf("\nEnter weight : ");
        scanf("%f",&items[i].weight);
    }
    printf("\nTotal profit : %.2f\n",knapsack(items,n,W));
    return 0;
}

float knapsack(item items[],int n,float W) {
    if(n == 0 || W == 0)
        return 0;
    else {
        if(items[n - 1].weight <= W) {
            return max(items[n - 1].value + knapsack(items,n-1,W - items[n - 1].weight),knapsack(items,n-1,W));
        }
        else {
            return knapsack(items,n-1,W);
        }
    }
}

float max(float a,float b) {
    return a>b?a:b;
}
