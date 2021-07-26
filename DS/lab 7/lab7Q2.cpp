#include <iostream>
using namespace std;
class node
{
    public:
    int info;
    node *next;
};
node *head=NULL;
class operations
{
    public:
    void create_list(node *curr)
    {
        int x;
        cout<<"Enter the number to input in the list\n";
        cin>>x;
        node *temp=new node();
        temp->info=x;
        if(head==NULL)
        {
            head=temp;
            curr=head;
        }
        else
        {
            curr->next=temp;
            temp->next=NULL;
            curr=temp;
        }
        cout<<"Press 1 to enter more items and 0 to exit\n";
        int n;
        cin>>n;
        if(n)
        {
            create_list(curr);
        }
    }
    void traverse()
    {
        static node*curr=head;
        if(curr!=NULL)
        {
            cout<<curr->info<<" ";
            curr=curr->next;
            traverse();
        }
    }
};
int main()
{
    operations obj;
    obj.create_list(NULL);
    obj.traverse();
    return 0;
}
