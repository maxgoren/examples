#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define true 1
#define false 0

typedef int bool;

void swap(int i[], int a, int b)
{
  int tmp = i[a];
  i[a] = i[b];
  i[b] = tmp;
}

void printArr(int t[], int size)
{
    for (int v = 0; v < size; v++)
    {
      printf("%d ", t[v]);
    }
    printf("\n");
}

void selSort(int p[], int size)
{
    for (int i = 0; i < size; i++)
    {
      int smallest = i;
      for (int q = i; q < size; q++)
      {
          if (p[q] < p[smallest])
          {
              smallest = q;
          }
      }
      swap(p, i, smallest); 
    }
}

bool sequentialSearch(int val, int t[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (t[i] == val)
        {
          printf("Found!\nItems Searched: %d\n", i);
          return true;
        }
    }
    return false;
}

bool binarySearch(int val, int t[], int size)
{
    int l = 0;
    int r = size;
    int m = (l+r) / 2;
    int count = 0;
    while (r >= l)
    {
      
      m = (l+r) / 2;
      if (val == t[m]) 
      {
          printf("Found\nItems Searched: %d\n", count);
          return true;
      }
      if ( val < t[m]) r = m - 1;
      else l = m + 1;
      count++;
    }
    return false;
}

bool binarySearchR(int val, int t[], int l, int r)
{
    int m = (l + r) / 2;
    if (r >= l)
    {
        if (val == t[m])
        return true;
        if (val < t[m]) return binarySearchR(val, t, l, m-1);
        else return binarySearchR(val, t, m+1, r);
    }
    return false;
}

void compareSearches(int val, int t[], int size)
{
    printf("Searching For: %d\n", val);
    printf("Running Binary Search...\n");
    if (binarySearch(val, t, size))                  
        printf("   found %d\n",val);
    else 

    printf("Running Sequential Search...\n");
    if (sequentialSearch(val, t, size))                  
    else 
        printf("%d not found.\n", val);
}

int main()
{
    srand(time(0));
    int i;
    
    int t[10000];
    int srch_test;
    int q;
    for (i = 0; i < 10000; i++)
    {
      q = rand() % (20000 - 2);
      if (i == 42) srch_test = q;
      t[i] = q;
    }
    printf("Random numbers generated: \n");
    printArr(t, 10000);
    printf("\nSorting array for binary search\n");
    selSort(t, 10000);
        printArr(t, 10000);

   compareSearches(srch_test, t, 10000);
}