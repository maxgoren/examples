//A sorted linked list implementation of a min-priority queue
//(c) 2021 Max Goren - MaxGCoding.com
//Distributed under the MIT License. (See Bottom)
template <typename item_t>
class pq {
   public:
   const int itemMIN = -66642069;
   const int itemMAX = 66642069;
   class node {
       public:
       int priority;
       item_t item;
       node* next;
       node(int priority, item_t item) : item(item), priority(priority) { }
       node() { }
   };
   node* head;
   node* z;
   pq()
   {
       head = new node;
       z = new node;
       head->next = z;
       z->next = z;
       head->priority = itemMIN;
       z->priority = itemMAX;
   }
   inline bool empty() { return head->next == z; }
   inline item_t top() { return head->next->item; }
   void push(item_t i, int p);
   item_t pop();
   void update(item_t, int p);
};

template <typename item_t>
void pq<item_t>::push(item_t i, int p)
{
   node* ins = new node(p, i);
   if (empty())
   {
       ins->next = head->next;
       head->next = ins;
       return;
   }
   for (node* t = head; t != z; t = t->next)
   {
       if (p > t->priority && p < t->next->priority)
       {
           ins->next = t->next;
           t->next = ins;
       }
   }
}


template <typename item_t>
item_t pq<item_t>::pop()
{
    node *t = head->next;
    item_t ret = t->item;
    head->next = head->next->next;
    delete t;
    return ret;
}


//search for our item, if found, we remove it from the list
//change its priority, and reinsert it in the list.
template <typename item_t>
void pq<item_t>::update(item_t i, int p)
{
    node* t = head;
    node *x;
    bool found = false;
    for (; t != z; t = t->next)
    {
        if (i == t->next->item)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        t->next = t->next->next;
        push(i, p);
    } else {
        push(i, p);
    }
}

/*
MIT License

Copyright (c) 2021 Max Goren

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/