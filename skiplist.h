#include <iostream>
#include <cstdlib>
#include <climits>
#include <random>
using namespace std;

const int max_level = 7;
template <typename keyType, typename valueType>
class SkipList {
    private:
        class SkipNode {
          public:
            keyType key;
            valueType value;
            unsigned int depth;
            SkipNode *next[max_level];
            SkipNode *prev[max_level];
	        SkipNode(keyType k) : key(k) { depth = 0; }
            SkipNode(keyType k, valueType v) : key(k), value(v) { depth = 0; }
            ~SkipNode()
            {
                
            }
        };
        unsigned int sz;
        unsigned int randLevel();
        SkipNode* search(keyType);
    public:
        SkipNode *head[max_level];
        SkipNode *z;
        random_device rd;
        SkipList()
        {
            z = new SkipNode(INT_MAX);
            sz = 0;
            for (auto i = 0; i < max_level; i++)
            {
              head[i] = new SkipNode(INT_MIN);

              z->next[i] = z;
              head[i]->next[i] = z;
              head[i]->prev[i] = head[i];
              z->prev[i] = head[i];
            }
        }
        unsigned int coinFlip();
        inline bool empty(int level) { return head[level]->next[level] == z; }
        bool find(keyType);
        void insert(keyType, valueType);
        void remove(keyType);
        void showLevel(int n);
        void show();
};

template <typename keyType, typename valueType>
void SkipList<keyType, valueType>::showLevel(int level)
{
    SkipNode *t;
    if (level > max_level)
    {
        cout<<"Level exceeds max.\n";
        return;
    } else if (!empty(level)) {

      for (t = head[level]->next[level]; t != z; t = t->next[level])
      {
         cout<<t->key<<" ";
      }

    } else {
        cout<<"(empty)";
    }
    cout<<endl;
}

template <typename keyType, typename valueType>
void SkipList<keyType, valueType>::show()
{
    //display each level
    cout<<"Show called\n";
    for (auto i = max_level-1; i > -1; i--)
    {
      cout<<"Level "<<i+1<<": ";
      showLevel(i);
    }
}

template <typename keyType, typename valueType>
unsigned int SkipList<keyType, valueType>::coinFlip()
{
    mt19937_64 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);
    return distrib(gen);
}

template <typename keyType, typename valueType>
unsigned int SkipList<keyType, valueType>::randLevel()
{
    //count coin flips until tails
    uint n = 0;
    while (coinFlip() > 50)
    {
        n++;
    }
    //return number of coin flips as the number of levels to use
    return n;
}

template <typename keyType, typename valueType>
void SkipList<keyType, valueType>::insert(keyType key, valueType val)
{
    SkipNode *n = new SkipNode(key, val);
    int ins_level = randLevel();
    if (ins_level > max_level)
    {
        ins_level = max_level;
    }
    for (auto i = 0; i <= ins_level; i++)
    {
        for (SkipNode *t = head[i]; t != z; t = t->next[i])
        {
            if (key > t->key && key < t->next[i]->key)
            {
                n->depth++;
                n->next[i] = t->next[i];
                n->prev[i] = t->prev[i]; 
                t->next[i] = n;
                t->next[i]->prev[i] = n;
            }
        }
        cout<<key<<" inserted on level: "<<i<<endl;
    }
    sz++;
}

template <typename keyType, typename valueType>
typename SkipList<keyType, valueType>::SkipNode* SkipList<keyType, valueType>::search(keyType key)
{
   
        
            int i = 0;
            while (i < max_level && key > head[i]->next[i]->key) i++;
            for (int p = i; p > -1; p--)
            {
                for (SkipNode *t = head[p]->next[p]; t != z; t = t->next[p])
                {
                    if (key == t->key)
                    {
                        return t;
                    }
                }
            }
        
    return NULL;
}

template <typename keyType, typename valueType>
bool SkipList<keyType, valueType>::find(keyType key)
{
    SkipNode *t = search(key);
    if (t == NULL)
    {
        return false;
    }
    return true;
}

template <typename keyType, typename valueType>
void SkipList<keyType, valueType>::remove(keyType key)
{
    SkipNode *current;
    if ((current = search(key)))
    {
        for (int i = current->depth-1; i > -1; i--)
        {
            cout<<"deleting "<<current->key<<" from "<<i<<endl;
            current->next[i]->prev[i] = current->prev[i];
            current->prev[i]->next[i] = current->next[i];
        }
    } 
}