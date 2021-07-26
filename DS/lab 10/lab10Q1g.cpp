#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
unsigned int getLeafCount(node* Node)
{
    if(Node == NULL)
        return 0;
    if(Node->left == NULL && Node->right == NULL)
        return 1;
    else
        return getLeafCount(Node->left)+getLeafCount(Node->right);
}
node* newNode(int data)
{
    node* Node=new node;
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
return(Node);
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<"Leaf count of the tree is : "<<getLeafCount(root)<<endl;
    return 0;
}
