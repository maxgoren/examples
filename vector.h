#include <stdlib.h>

typedef struct {
  int *arr;
  int max_size;
  int current_size;
} vector;

vector* newVector(int n)
{
  vector* v = malloc(sizeof(vector));
  v->arr = malloc(n + sizeof(int));
  v->max_size = n;
  v->current_size = 0;
  return v;
}

void vector_push_back(vector* v, int n)
{
 if (v->current_size == v->max_size)
 {
  v->max_size *= 2;
  void* temp = realloc(v->arr, v->max_size * sizeof(v->arr));
  if (!temp) {
   return; //realloc failed
  }
  v->arr = temp;
 }
 v->arr[v->current_size++] = n;
}

void vector_shrink_to_size(vector* v)
{
 void* temp = realloc(v->arr, (v->current_size + 1) * sizeof(v->arr));
 if (!temp) {
  return;
 }
 v->arr = temp;
}

void destroyVector(vector* v)
{
  free(v->arr);
  free(v);
}

