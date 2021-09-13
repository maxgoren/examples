#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int data) : data(data) { next = nullptr; }
    node(const node&) { next = nullptr; }
    node() { next = nullptr; }
};

class List {
    public:
    node* head;
    node* last;
    node* tail;
    List()
    {
        head = new node;
        tail = new node;
        head->next = tail;
        tail->next = tail;
        last = head;
    }
    inline bool empty() { return head->next == tail; }
    void add(int num);
    void remove(int num);
    bool find(int num);

};

void List::add(int num)
{
    node* x = new node(num);
    x->next = last->next;
    last->next = x;
    last = x;
}

bool List::find(int num)
{
    if (!empty())
    {
        for (node* listItr = head->next; listItr != tail; listItr = listItr->next)
        {
            if (num == listItr->data)
            {
                return true;
            }
        }
    }
    return false;
}

void List::remove(int num)
{
    if (!empty())
    {
        for (node* listItr = head; listItr != tail; listItr = listItr->next)
        {
            if (num == listItr->next->data)
            {
                node *t = listItr->next;
                listItr->next = listItr->next->next;
                delete t;
            }
        }
    }
}

void printList(List& list)
{
    if (!list.empty())
    {
        for (node* listItr = list.head->next; listItr != list.tail; listItr = listItr->next)
        {
            std::cout<<listItr->data<<" ";
        }
        std::cout<<"\n";
    } else {
        std::cout<<"List is empty!\n";
    }
}


int main()
{
    List myList;
    printList(myList);
    myList.add(1);
    myList.add(24);
    myList.add(3);
    printList(myList);
    if (myList.find(24))
    {
      myList.remove(24);
    }
    myList.add(16);
    printList(myList);
    return 0;
}