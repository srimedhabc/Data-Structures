#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
    public:
    int key;
    node *left, *right;
};
node *newNode(int item)
{
    node *temp =new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
node* insert(node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    return 0;
}
