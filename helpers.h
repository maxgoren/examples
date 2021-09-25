#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* * * * * * * * * * * * * * *
* Add Boolean type for C     *
* * * * * * * * * * * * * * */
typedef int Bool;
#define true 1
#define false 0

/* * * * * * * * * * * * * *
*                          *
*         min/max          *
*                          *
* * * * * * * * * * * * * */

int min(int a, int b)
{
   return (a < b) ? a:b;
}

int max(int a, int b)
{
    return (a > b) ? a:b;
}

/* * * * * * * * * * * * * *
 *                         *
 * Random number functions *
 *                         *
 * * * * * * * * * * * * * */

/** seeds rand, if -1 is passed, time(0) is used */
void seedRand(int seed)
{
    if (seed == -1)
      seed = time(0);

    srand(seed);
}

/** generate a random number between lo and hi */
int randomNumber(int lo, int hi)
{
  return (rand() % (hi - lo + 1)) + lo;
}

/** simulate a coin flip */
unsigned int coinFlip()
{
    return 1 - (rand()%(2));
}

/* * * * * * * * * * * *
 *                     *
 *  array functions    *
 *                     *
 * * * * * * * * * * * */

/** swap positions of two numbers in an array */
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

/** generate an array of size [size] containing random numbers between hi and lo */
int* randomArray(int size, int lo, int hi)
{
    int num = 0;
    int *result = (int*)malloc(sizeof(result)/sizeof(int));
    for (int i = 0; i < size; i++)
    {
        num = randomNumber(lo, hi);
        result[i] = num;
    }
    return result;
}


/** print the contents of an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/** sort an array (selection sort) */
void sortArray(int arr[], int size)
{
    int i, j, smallest;
    for (i = 0; i < size; i++)
    {
        int smallest = i;
        for (j = i; j < size; j++)
        {
            if (arr[j] < arr[smallest])
              smallest = j;
        }
        if (arr[smallest] < arr[i])
        {
          swap(arr, i, smallest);
        }
    }
}

/** return smallest value in an array */
int getMinFromArray(int arr[], int size)
{
    int smallest = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[smallest])
         smallest = i;
    }
    return arr[smallest];
}

/** return largest value in array */
int getMaxFromArray(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[largest])
          largest = i;
    }
    return arr[largest];
}

/** Search for a value in an array using Binary Search */
Bool binarySearch(int t[], int val, int size)
{
    int l = 0;
    int r = size;
    int m = (l+r) / 2;
    while (r >= l)
    {
      
      m = (l+r) / 2;
      if (val == t[m]) 
      {
          return true;
      }
      if ( val < t[m]) r = m - 1;
      else l = m + 1;
    }
    return false;
}

/* * * * * * * * * *
 *                 *
 *  List functions *
 *                 *
 * * * * * * * * * */

/** singly linked list node */
struct listNode {
    int value;
    struct listNode *next;
};

/** Generate a singly linked list of N random numbers between lo and hi */
struct listNode* randomList(int size, int lo, int hi)
{
   struct listNode *head = (struct listNode*)malloc(sizeof(struct listNode));
   head->value = randomNumber(lo, hi);
   head->next = NULL; 
   struct listNode *tmp;
   int i;
   for (i = 1; i < size; i++)
   {
       tmp = (struct listNode*)malloc(sizeof(struct listNode));
       tmp->value = randomNumber(lo, hi);
       tmp->next = head->next;
       head->next = tmp;
   }
   return head;
}

/** print a singly linked list */
void printList(struct listNode* head)
{
    for (struct listNode *itr = head; itr != NULL; itr = itr->next)
    {
        printf("%d ", itr->value);
    }
    printf("\n");
}

/** sort a singly linked list (selection sort) */
void sortList(struct listNode **head)
{
    for (struct listNode *i = (*head); i != NULL; i = i->next)
    {
        struct listNode* smallest = i;
        for (struct listNode *j = i; j != NULL; j = j->next)
        {
            if (j->value < smallest->value)
              smallest = j;
        }
        if (smallest->value < i->value)
        {
            int tmp = i->value;
            i->value = smallest->value;
            smallest->value = tmp;
        }
    }
}