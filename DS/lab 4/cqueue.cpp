 #include<iostream>
 #include<cstring>
 #include<stdio.h>
 using namespace std;
 #define QSIZE 5
 class cqueue{
 private:
     int q[QSIZE];
     int front,rear;
 public:
    cqueue(){
    front=rear=0;
    }
    void addq(int item)
    {
        if(isFull())
        {
            cout<<"Over flow"<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%QSIZE;
            q[rear]=item;
        }
    }
    int delq(){
    if(isEmpty())
        {
            cout<<"Empty queue"<<endl;
            return -1;
        }
        else
        {
            front=(front+1)%QSIZE;
            return q[front];
        }
    }
    void display(){
    int i;
    if(!isEmpty())
        {
            cout<<"The contents of the queue are"<<endl;
            for(i=(front+1)%QSIZE;i!=rear;i=(i+1)%QSIZE){
                cout<<q[i]<<endl;}
            cout<<q[rear]<<endl;
        }
        else
            cout<<"Empty queue"<<endl;
    }
    bool isFull()
    {
        if((rear+1)%QSIZE==front)
            return true;
        else
            return false;
    }
    bool isEmpty(){
    if(front==rear)
        return true;
        else
            return false;
    }
 };
 int main()
 {
     int choice,item;
     cqueue que;
     do{
        cout<<"Enter 1 to add,2 to delete and 3 to display"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the item to be added"<<endl;
            cin>>item;
            que.addq(item);
            break;
        case 2:
            cout<<"The deleted item from the queue is "<<que.delq()<<endl;
            break;
        case 3:
            que.display();
            break;
        }
     }while(choice<4);
     return 0;
 }
