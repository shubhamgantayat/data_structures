#include<stdio.h>
#include<stdlib.h>
struct bst {
    int info;
    struct bst *left;
    struct bst *right;
};
typedef struct bst node;
void insert(node**,int);
void inorder(node*);
node* search(node*,int);
void Delete(node**,int);
int findMin(node*);
int main() {
    int ele,ch;
    node *start = NULL,*p;
    while(1) {
        printf("\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Delete\n7. Find Minimum\n8. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("\nEnter the element to be inserted : ");
                scanf("%d",&ele);
                insert(&start,ele);
                break;
            case 2:
                printf("\nEnter the element to be searched : ");
                scanf("%d",&ele);
                p = search(start,ele);
                if(p == NULL)
                    printf("\nElement not found");
                else
                    printf("\nElement found at address : %ld",p);
                break;
            case 3:
                inorder(start);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("\nEnter the element to be deleted : ");
                scanf("%d",&ele);
                Delete(&start,ele);
                break;
            case 7:
                printf("\nMinimum : %d",findMin(start));
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

void insert(node **start,int ele) {
    if(*start == NULL) {
        (*start) = (node*)malloc(sizeof(node));
        (*start)->info = ele;
        (*start)->left = NULL;
        (*start)->right = NULL;
    }
    else if(ele < ((*start)->info))
        insert(&((*start)->left),ele);
    else
        insert(&((*start)->right),ele);
}

void inorder(node *start) {
    if(start == NULL) {
        return;
    }
    else {
        inorder(start->left);
        printf("%d\t",start->info);
        inorder(start->right);
    }
}

node* search(node *start,int ele) {
    if((start == NULL) || (start->info == ele))
        return start;
    else if(ele < start->info)
        search(start->left,ele);
    else
        search(start->right,ele);
}

int findMin(node *start) {
    if(start == NULL) {
        return -999;
    }
    else {
        if(start->left == NULL)
            return start->info;
        else
            findMin(start->left);
    }
}

void Delete(node **start,int ele) {
    if((*start) == NULL)
        printf("\nElement not found");
    else if((*start)->info == ele) {
        if(((*start)->left == NULL) && ((*start)->right == NULL)) {
            (*start) = NULL;
        }
        else if(((*start)->left == NULL) || ((*start)->right == NULL)) {
            if((*start)->left != NULL)
                (*start) = (*start)->left;
            else
                (*start) = (*start)->right;
        }
        else {
            (*start)->info = findMin((*start)->right);
            Delete(&((*start)->right),findMin((*start)->right));
        }
        printf("\nElement deleted successfully");
    }
    else if(ele < ((*start)->info))
        Delete(&((*start)->left),ele);
    else
        Delete(&((*start)->right),ele);
}
