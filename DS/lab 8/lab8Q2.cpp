#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
};

class DList{
	public:
		void append(Node** head,int ele)
		{
			Node* temp = new Node;
			Node *cur=*head;
			temp->data=ele;
			temp->next=NULL;
			if (*head==NULL)
			{
				*head=temp;
				(*head)->prev=NULL;
				return;
			}
			while (cur->next!=NULL)
				cur=cur->next;
			cur->next=temp;
			temp->prev=cur;
		}

		void Delete(Node** head)
		{
			Node *cur;
			Node *temp=new Node();
			cur=*head;
			while (cur->next->next!=NULL)
			cur=cur->next;
			temp=cur->next;
			cur->next=NULL;
			delete(temp);
		}

		void PopFront(Node** head)
			{
				Node *cur;
				Node *temp=new Node();
				temp=*head;
				cur=temp->next;
				*head=cur;
				delete(temp);
			}

		void Insert(Node** head, int pos, int ele)
		{
			Node *cur;
			Node *temp=new Node;
			temp->data=ele;
			cur=*head;
			int c=2;
			while (c!=pos)
			{
				cur=cur->next;
				c++;
			}
			temp->prev=cur;
			temp->next=cur->next;
			cur->next=temp;
		}

		int Disp(Node** head)
			{
				int key;
				Node *cur;
				cur=*head;
				key=cur->data;
				return key;
			}

		void printList(Node *node)
			{
			    while (node != NULL)
			    {
			        cout<<" "<<node->data;
			        node = node->next;
			    }
			}
};

void ConcatLists(DList list1, Node* head1, DList list2, Node* head2)
{
	Node *cur1=head1;
	Node *cur2=head2;
	Node* temp = new Node;
	int c2=1;
	while (cur2->next!=NULL)
	{
		cur2=cur2->next;
		c2++;
	}
	cur2=head2;
	while (c2!=0)
	{
		int ele;
		ele=list2.Disp(&head2);
		list1.append(&head1,ele);
		list2.PopFront(&head2);
		c2--;
	}
	list1.printList(head1);
}

int main()
{
	DList list1,list2;
	Node *head1=NULL, *head2=NULL;
	int ele;
	char ch1='y',ch2='y';
	cout<<"Enter the elements of list1.\n";
	while (ch1=='y')
	{
		cout<<"Enter the element to be added.\n";
		cin>>ele;
		list1.append(&head1,ele);
		cout<<"Enter y to add another element.\n";
		cin>>ch1;
	}
	cout<<"Enter the elements of list2.\n";
	while (ch2=='y')
	{
		cout<<"Enter the element to be added.\n";
		cin>>ele;
		list2.append(&head2,ele);
		cout<<"Enter y to add another element.\n";
		cin>>ch2;
	}
	cout<<"Concatenated list is:\n";
	ConcatLists(list1,head1,list2,head2);
	return 0;
}
