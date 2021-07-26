#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MAXSIZE 100
class Multiple{
int top[100];
int a[100];
int boundary[100];
public:
    Multiple(int);
    void push(int,int);
    void pop(int);
    void display(int);
};
Multiple::Multiple(int n)
{
    for(int i=0;i<n;i++)
        boundary[i]=top[i]=(MAXSIZE/n)*i-1;
}
void Multiple::push(int i,int x)
{
    if(top[i]==boundary[i+1]||top[i]==MAXSIZE-1)
        cout<<"Stack is full"<<endl;
    else
        a[++top[i]]=x;
}
void Multiple::pop(int i)
{
    if(top[i]==boundary[i])
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Deleted element is\n"<<a[top[i]]<<endl;
      a[top[i]--];
}
void Multiple::display(int i)
{
    if(top[i]==boundary[i])
        cout<<"Stack is empty"<<endl;
    else
        for(int j=top[i];j>boundary[i];j--)
        cout<<a[j]<<endl;
}
int main()
{
    int no;
    cout<<"Enter the number of stacks"<<endl;
    cin>>no;
    Multiple s(no);
    int n,ele,ch,n1,n2;
    do{
        cout<<"Enter 1 to push,2 to pop,3 to display and 4 to exit"<<endl;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter stack number "<<endl;
            cin>>n;
            cout<<"Enter element"<<endl;
            cin>>ele;
            s.push(n-1,ele);
        }
        else if(ch==2)
        {
            cout<<"Enter stack number "<<endl;
            cin>>n2;
            s.pop(n2-1);
        }
        else if(ch==3)
        {
            cout<<"Enter stack number "<<endl;
            cin>>n1;
            s.display(n1-1);
        }
    }while(ch!=4);
    return 0;
}
