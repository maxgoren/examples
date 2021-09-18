#include <stdio.h>
#include <stdlib.h>
int i;
struct node {
    int data;
    struct node* l;
    struct node* r;
};

void treeToArr(struct node* t, int A[])
{
    if (t != NULL)
    {
        treeToArr(t->l, A);
        A[i++] = t->data;
        treeToArr(t->r, A);
    }
}

void treesort(int A[], int sz)
{
    struct node* root = NULL;;
    struct node* t, *itr, *p;
    for (int i = 0; i < sz; i++)
    {
        t = malloc(sizeof(struct node));
        t->data = A[i];
        t->l = t->r = NULL;
        if (root == NULL)
        { 
         root = t;
        } else {
          for (itr = root; itr != NULL; itr = (A[i] < itr->data) ? itr->l:itr->r)
            p = itr;
      
          if (A[i] < p->data) p->l = t;
          else p->r = t;
        }
    }
    i = 0;
    treeToArr(root, A);
}

void printArr(int A[], int sz)
{
    for (int i = 0; i < sz; i++)
       printf("%d ", *(A+i));
    printf("\n");
}

int main()
{
    int A[] = { 13, 37, 42, 11, 7, 69, 5, 108, 127, 17};
    int sz = sizeof(A)/sizeof(A[0]);
    printArr(A, sz);
    treesort(A, sz);
    printArr(A, sz);
    return 0;
}