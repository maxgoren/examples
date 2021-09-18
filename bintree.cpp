#include <iostream>
#include <stack>
#include <memory>
using namespace std;

class BinaryTree {
    private:
    class BTNode {
        public:
        int data;
        shared_ptr<BTNode> left;
        shared_ptr<BTNode> right;
        BTNode(int d) : data(d) { }
        BTNode() { }
    };
    shared_ptr<BTNode> root;
    void inorderR(shared_ptr<BTNode> x);
    public:
    BinaryTree();
    void insert(int d);
    void find(int d);
    void showSorted();
    void iterativeTraversal();
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::insert(int d)
{
    shared_ptr<BTNode> t = root;
    shared_ptr<BTNode> p;
    shared_ptr<BTNode> ins(new BTNode(d));
    if (root == nullptr)
    {
        root = ins;
    } else {
      while (t != nullptr)
      {
        p = t;
        t = (d < t->data) ? t->left:t->right;
      }
      if (d < p->data) p->left = ins;
      else  p->right = ins;
    }
}

void BinaryTree::find(int d)
{
    shared_ptr<BTNode> t;
    t = root;
    while (t != nullptr)
    {
        if (d == t->data)
        {
            cout<<d<<" exists in the tree\n";
        } else {
            if (d < t->data)
            t = t->left;
            else
            t = t->right;
        }
    }
}

void BinaryTree::showSorted()
{
    inorderR(root);
    cout<<endl;
}

void BinaryTree::inorderR(shared_ptr<BTNode> x)
{
    if (x != nullptr)
    {
        inorderR(x->left);
        cout<<x->data<<" ";
        inorderR(x->right);
    }
}

void BinaryTree::iterativeTraversal()
{
    stack<shared_ptr<BTNode>> s;
    shared_ptr<BTNode> current;
    if (root != nullptr)
    {
    s.push(root);
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        cout<<current->data<<" ";
        if (current->left != nullptr) s.push(current->left);
        if (current->right != nullptr) s.push(current->right);
    }
    cout<<endl;
    } else {
        cout<<"Tree is empty,\n";
    }
}

int main()
{
    BinaryTree example;
    example.insert(27);
    example.insert(38);
    example.insert(13);
    example.insert(8);
    example.insert(19);
    example.insert(43);
    example.insert(30);
    example.iterativeTraversal();
    example.showSorted();
    return 0;
}