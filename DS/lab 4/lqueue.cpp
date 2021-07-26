#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define QSIZE 5
class lqueue{
private:
    int q[QSIZE];
    int front,rear;
public:
    lqueue(){
    front=rear=-1;
    }
    void addq(int item);
    int delq();
    bool isEmpty();
    bool isFull();
    void display();
};
void lqueue::addq(int item){
if(isFull())
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else
        q[++rear]=item;
}
int lqueue::delq(){
if(isEmpty())
    {
        cout<<"Empty queue"<<endl;
        return -1;
    }
    else
        return q[++front];
}
void lqueue::display(){
int i;
if(isEmpty())
        cout<<"Empty queue "<<endl;
   else
        {
            cout<<"contents of the queue are"<<endl;
            for(i=front+1;i<=rear;i++)
            cout<<q[i]<<endl;
        }
}
bool lqueue::isFull(){
if(rear==QSIZE-1)
    return true;
else
    return false;
}
bool lqueue::isEmpty(){
if(front==-1&&rear==-1)
   return true;
else
   return false;
}
int main()
{
    int choice,item;
    lqueue que;
    do{
        cout<<"Enter 0 to add, 1 to delete and 2 to display "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 0:
            cout<<"Enter the item "<<endl;
            cin>>item;
            que.addq(item);
            break;
        case 1:
            cout<<"Removed item from the queue is "<<que.delq()<<endl;
            break;
        case 2:
            que.display();
            break;
        }
    }while(choice<3);
    return 0;
}
