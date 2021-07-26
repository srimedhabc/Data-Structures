#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class node
{
    public:
   int data;
   node* left;
   node* right;
};
bool printAncestors(node *root, int target)
{
  if (root == NULL)
     return false;
  if (root->data == target){
     cout<<"ancestors are "<<endl;
     return true;
  }
  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
  return false;
}
node* newnode(int data)
{
  node* Node = new node;
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return(Node);
}
int main()
{
  node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  printAncestors(root, 7);
  return 0;
}
