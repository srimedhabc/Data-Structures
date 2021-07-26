#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* Node = new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void iterativePreorder(node *root)
{
    if (root == NULL)
       return;
    stack<node *> s;
    s.push(root);
    while (s.empty() == false)
    {
        node *node = s.top();
        cout<<node->data<<ends;
        s.pop();
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
    }
}
int main()
{
  node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  return 0;
}
