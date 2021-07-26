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

		void DeleteP(Node** head, int pos)
		{
			Node *cur,*keep;
			cur=*head;
			Node* temp=new Node;
			int c=1;
			while (c!=pos)
			{
				keep=cur;
				cur=cur->next;
				c++;
			}
			temp=cur;
			keep->next=cur->next;
			cur->next->prev=keep;
			delete(temp);
		}

        void Insert_Before(Node** head,int key,int new_data)
			{
				Node *cur,*keep;
				cur=*head;
				Node *temp=new Node();
				temp->data=new_data;
				while (cur->data!=key&&cur->next!=NULL)
				{
					keep=cur;
					cur=cur->next;
				}
				keep->next=temp;
				temp->prev=keep;
				temp->next=cur;
				cur->prev=temp;
			}

			void Insert_After(Node** head,int key,int new_data)
			{
				Node *cur,*keep;
				cur=*head;
				Node *temp=new Node();
				temp->data=new_data;
				while (cur->data!=key&&cur->next!=NULL)
				{
					cur=cur->next;
					keep=cur->next;
				}
				cur->next=temp;
				temp->prev=cur;
				temp->next=keep;
				keep->prev=temp;
			}

		void Reverse(Node** head)
		{
		    Node *temp=NULL;
		    Node *cur=*head;
		    while (cur!=NULL)
		    {
		        temp = cur->prev;
		        cur->prev=cur->next;
		        cur->next=temp;
		        cur=cur->prev;
		    }
		    if(temp != NULL )
		        *head=temp->prev;
		}

		void printList(Node *node)
			{
			    while (node != NULL)
			    {
			        cout<<" "<<node->data;
			        node = node->next;
			    }
			    cout<<endl;
			}
};

int main()
{
	DList list;
	Node *head=NULL;
	int ele,op;
	char ch='y';
	cout<<"Enter 1:Append\t 2:Delete\t 3.Insert At a position\t 4:Delete At a Position\t 5:Insert Before An Element\n";
	cout<<"6:Insert After an Element\t 7:Reverse the list\t 8:Display the list\n";
	while (ch=='y')
	{
		cout<<"Operation Number:\n";
		cin>>op;
		switch(op)
		{
			case(1):
			{
				cout<<"Enter the element to add.\n";
				cin>>ele;
				list.append(&head,ele);
				break;
			}
			case(2):
			{
				list.Delete(&head);
				break;
			}
			case(3):
			{
				int p;
				cout<<"Enter the position to add the element.\n";
				cin>>p;
				cout<<"Enter the element.\n";
				cin>>ele;
				list.Insert(&head,p,ele);
				break;
			}
			case (4):
				{
					int p;
					cout<<"Enter the position of the element to be deleted.\n";
					cin>>p;
					list.DeleteP(&head,p);
					break;
				}
			case (5):
				{
					int num;
					cout<<"Enter the element you want to insert.\n";
					cin>>ele;
					cout<<"Enter the element you want to insert it before.\n";
					cin>>num;
					list.Insert_Before(&head,num,ele);
					break;
				}
			case (6):
				{
					int num;
					cout<<"Enter the element you want to insert.\n";
					cin>>ele;
					cout<<"Enter the element you want to insert it after.\n";
					cin>>num;
					list.Insert_After(&head,num,ele);
					break;
				}
			case (7):
				{
					list.Reverse(&head);
					list.printList(head);
					break;
				}
			case (8):
					{
						list.printList(head);
						break;
					}
		}
		cout<<"Enter y to perform another operation.\n";
		cin>>ch;
	}
}
