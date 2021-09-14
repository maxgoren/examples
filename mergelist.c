#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CUTOFF 2
//list node definition
struct listNode_t {
    int64_t data;
    struct listNode_t *next;
};

//defining our list
struct list {
    struct listNode_t *head;
    struct listNode_t *tail;
    struct listNode_t *z;
    int size;
    
};

//helper function for creating nodes
struct listNode_t* newNode(int64_t d)
{
    struct listNode_t* n = (struct listNode_t*)malloc(sizeof(struct listNode_t));
    n->data = d;
    n->next = NULL;
    return n;
}

//helper function to create a list
struct list* newList()
{
    struct list* nl = (struct list*)malloc(sizeof(struct list));
    nl->size = 0;
    nl->head = newNode(INT64_MIN);
    nl->z = newNode(INT64_MAX);
    nl->head->next = nl->z;
    nl->z->next = nl->z;
    return nl;
}

//Add elements to a linked list in the order they are recieved
void Push_list(struct list** l, int64_t d)
{
    struct listNode_t *t = newNode(d);
    if ((*l)->head->next == (*l)->z)
    {
      (*l)->head->next = (*l)->tail = t;
      (*l)->tail->next = (*l)->z;
    } else {
        t->next = (*l)->z;
        (*l)->tail->next = t;
        (*l)->tail = t;
    }
    (*l)->size++;
}

//Add elements to a linked list IN SORTED ORDER
void Push_sorted(struct list** l, int64_t d)
{
   struct listNode_t *t = newNode(d);
   for (struct listNode_t *listIter = (*l)->head; listIter != (*l)->z; listIter = listIter->next)
   {
       if (d > listIter->data && d <= listIter->next->data)
       {
           t->next = listIter->next;
           listIter->next = t;
           (*l)->size++;
       }
   }
}

//helper function for printing our linked list
void printList(struct list *l)
{
    if (l->head->next != l->z)
    {
    for (struct listNode_t *t = l->head->next; t != l->z; t = t->next)
    {
        printf("%d ", t->data);
    }
    } else {
        printf("list is empty");
    }
    printf("\n");
}

//this function takes two lists as an input, and outputs a single list in sorted order
//comprised of the elements from the two input lists.
//By implementing Push_sorted we're combining insertion sort & mergesort
struct list* mergeList(struct list *l1, struct list *l2)
{
    struct list *result = newList();
    struct listNode_t *h1, *h2;
    if (l1->head->next != l1->z)
    {
     for (h1 = l1->head->next; h1 != l1->z; h1 = h1->next)
     {
        Push_sorted(&result, h1->data);
     }
    }
    if (l2->head->next != l2->z)
    {
     for (h2 = l2->head->next; h2 != l2->z; h2 = h2->next)
     {
        Push_sorted(&result, h2->data);
     }
    }
    return result;
}

//input a linked list and recursively split it in to
//front and back portions for lists above a certain size
struct list* mergeSort(struct list* tosort)
{
    struct list *res;
    struct listNode_t *listItr;
    int i, mid;
    if (tosort->size > CUTOFF)
    {
        struct list* front = newList();
        struct list* back = newList();
        mid = tosort->size / 2;
        listItr = tosort->head;
        //split our list into two halves
        for (i = 0; i <= mid; i++)
        {
          Push_list(&front, listItr->data);
          listItr = listItr->next;
        }
        for(; i <= tosort->size; listItr = listItr->next, i++)
        {
          Push_list(&back, listItr->data);
        }
        //recursively call merge sort on front half of list and back half of list
        mergeSort(front);
        mergeSort(back);
        res = mergeList(front, back);
    }
    return res;
}

int main()
{
    srand(time(0));
    struct list *head = newList();
    for (int i = 0; i < 10; i++)
       Push_list(&head, rand()%(100-2)-1);
    printList(head);
    struct list *res = mergeSort(head);
    printList(res);
    return 0;
}