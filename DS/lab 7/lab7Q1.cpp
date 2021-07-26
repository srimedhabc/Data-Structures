#include <iostream>
using namespace std;

class Node{
	public:
		Node *next;
		int data;
};

class List{

		public:
			void Push(Node** head, int new_data)
			{
				Node* new_node = new Node();
	    		new_node->data = new_data;
	    		new_node->next = (*head);
	    		(*head) = new_node;
			}

			void append(Node** head, int new_data)
			{
	    		Node* new_node = new Node();
	    		Node *last = *head;
	    		new_node->data = new_data;
	    		new_node->next = NULL;
	    		if (*head == NULL)
	    		{
	        		*head = new_node;
	        	return;
	    		}
	    		while (last->next != NULL)
	        		last = last->next;
	    		last->next = new_node;
	    		return;
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
				temp->next=cur;
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

				}keep=cur->next;
				cur->next=temp;
				temp->next=keep;
			}

			void DeleteE(Node** head,int key)
			{
				Node *temp,*prev;
				temp=*head;
				if (temp != NULL && temp->data == key)
			    {
			        *head = temp->next;
			        delete(temp);
			        return;
			    }
			    while (temp != NULL && temp->data != key)
			    {
			        prev = temp;
			        temp = temp->next;
			    }
			    if (temp == NULL) return;
			    prev->next = temp->next;
			    delete(temp);
			}

			void Pop(Node** head)
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

			void Disp(Node** head)
			{
				Node *cur;
				cur=*head;
				while (cur->next!=NULL)
					cur=cur->next;
				cout<<cur->data<<endl;
			}
			void printList(Node *node)
			{
			    while (node != NULL)
			    {
			        cout<<" "<<node->data;
			        node = node->next;
			    }
			}

			void reverse(Node** head)
				{
			        Node* current = *head;
			        Node *prev = NULL, *next = NULL;
			        while (current != NULL)
					{
			            next = current->next;
			            current->next = prev;
			            prev = current;
			            current = next;
			        }
			        *head = prev;
			    }

			void sortedInsert(Node** head, Node* new_node)
			{
				Node *cur;
				if (*head==NULL|| (*head)->data >= new_node->data)
				{
					new_node->next = *head;
        			*head=new_node;
				}
				else
				{
					 	cur=*head;
				        while (cur->next!=NULL && cur->next->data < new_node->data)
				        {
				            cur=cur->next;
				        }
				        new_node->next=cur->next;
				        cur->next=new_node;
				}
			}

			void Sort(Node **head)
			{
				Node* sorted=NULL;
				Node* cur=*head;
				Node* next=NULL;
				while (cur!=NULL)
				{
					next=cur->next;
					sortedInsert(&sorted,cur);
					cur=next;
				}
				*head=sorted;
			}
};

int main()
{
	Node *head=NULL;
	List list;
	char ch='y';
	int op,ele;
	cout<<"\n Enter 1:Push 2:Append 3:Insert Before 4:Insert After 5:Delete an element\n 6:Delete from end 7.Delete from Beginning 8:Display the entire list 9:Display last element of the list 10:Reverse"<<endl;
	cout<<" 11:Sort the List  12:Sorted Insert"<<endl;
	while (ch=='y')
	{
		cout<<"Operation number:\n";
		cin>>op;
		switch (op)
			{
				case (1):
				{
					cout<<"Enter the element to be pushed.\n";
					cin>>ele;
					list.Push(&head,ele);
					break;
				}
				case (2):
				{
					cout<<"Enter the element to be appended.\n";
					cin>>ele;
					list.append(&head,ele);
					break;
				}
				case (3):
				{
					int num;
					cout<<"Enter the element you want to insert.\n";
					cin>>ele;
					cout<<"Enter the element you want to insert it before.\n";
					cin>>num;
					list.Insert_Before(&head,num,ele);
					break;
				}
				case (4):
				{
					int num;
					cout<<"Enter the element you want to insert.\n";
					cin>>ele;
					cout<<"Enter the element you want to insert it after.\n";
					cin>>num;
					list.Insert_After(&head,num,ele);
					break;
				}
				case (5):
				{
					cout<<"Enter the element to be deleted.\n";
					cin>>ele;
					list.DeleteE(&head,ele);
					break;
				}
				case (6):
					{
						list.Pop(&head);
						break;
					}
				case (7):
					{
						list.PopFront(&head);
						break;
					}
				case (8):
					{
						list.printList(head);
						break;
					}
				case (9):
					{
						list.Disp(&head);
						break;
					}
				case (10):
					{
						list.reverse(&head);
						list.printList(head);
						break;
					}
				case (11):
					{
						list.Sort(&head);
						list.printList(head);
						break;
					}

				case (12):
					{
						Node* temp=new Node;
						int ele;
						list.Sort(&head);
						cout<<"Enter the element to be added.\n";
						cin>>ele;
						temp->data=ele;
						list.sortedInsert(&head,temp);
						list.printList(head);
					}
				default: return 0;
			}
			cout<<"\n Enter y to perform another operation\n";
			cin>>ch;
	}
	return 0;
}
