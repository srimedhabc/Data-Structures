#include<iostream>
using namespace std;
class Stack{
public:
    int top,arr[100],MAX=100;
    Stack(){
    top=-1;
    }
    void push(int item){
    if(isFull())
    {
        cout<<"Stack overflow"<<endl;
    }
    else{
        top=top+1;
        arr[top]=item;
    }
    }
    int pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else{
        return arr[top--];
    }
    }
    void display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        for(int i=0;i<=top;i++)
            cout<<arr[top-i]<<endl;
    }
    }
    bool isFull(){
    if(top==MAX-1)
        return true;
    else
        return false;
    }
    bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
    }
    };
int main()
{
        int item,n,t;
        Stack s,s1;
        cout<<"Enter number of items in the queue"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
        cout<<"Enter the item of the queue"<<endl;
        cin>>item;
        s.push(item);
        }
        for(int i=0;i<n;i++)
        {
            t=s.pop();
            s1.push(t);
        }
        cout<<"The elements of the queue are"<<endl;
        s1.display();
        return 0;
}
