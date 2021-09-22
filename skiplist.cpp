#include <iostream>
#include "skiplist.h"
using namespace std;

int main()
{
    srand(time(0));
    int find_test;
    SkipList<int, string> sList;
    for (auto i = 0; i < 15; i++)
    {
      auto q = rand() % (100 - 1) - 1;
      if (i == 11)
        find_test = q;
      sList.insert(q, to_string(q));
    }
    sList.show();
    if (sList.find(find_test))
      cout<<find_test<<" is in the list\n";
    else 
      cout<<"couldnt find "<<find_test<<"\n";
    return 0;
}