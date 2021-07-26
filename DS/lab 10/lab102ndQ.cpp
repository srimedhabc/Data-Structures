#include<iostream>
using namespace std;
class tree_node{
public:
    int data;
    tree_node *rc,*lc;
};
tree_node* createBT()
{
    int x;
    tree_node *p=new tree_node;
    cout<<"Enter data(-1 for no data)"<<endl;
    cin>>x;
    if(x==-1)
        return NULL;
    p->data=x;
    cout<<"Enter the left child of "<<x<<endl;
    p->lc=createBT();
    cout<<"Enter the right child of "<<x<<endl;
    p->rc=createBT();
    return p;
}
void inorder(tree_node *ptr)
{
    if(ptr)
    {
        inorder(ptr->lc);
        cout<<ptr->data<<endl;
        inorder(ptr->rc);
    }
}
int main()
{
    tree_node *root;
    root=createBT();
    cout<<"The items of the binary tree in inorder represetation are\n";
    inorder(root);
    return 0;
}
