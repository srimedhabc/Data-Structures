#include<iostream>
using namespace std;
#define SS 5
int i;
class SolvedEx{
private:
    int top;
    int s[5];
public:
    int item;
    bool isFull(){
    if(top==(SS))
       return true;
    else
       return false;
    }
    bool isEmpty(){
    if(top==0)
       return true;
    else
       return false;
    }
    void push(int item);
    int pop();
    void display();
    SolvedEx()
    {
    int top=-1;
    }
    };
    void SolvedEx::push(int item)
    {
        if(isFull())
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        else
        {
        top=top+1;
        s[top]=item;
        }
    }
    int SolvedEx::pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else
        {
        cout<<"The popped item is"<<endl;
        return s[top--];
        }
    }
    void SolvedEx::display()
    {
        if(isEmpty())
        {
            cout<<"Empty Stack"<<endl;
            return;
        }
        else
        {
        cout<<"Contents of the stack are"<<endl;
        for(int i=1;i<=top;i++)
            cout<<s[i]<<ends;
        }
    }
    int main()
    {
         int choice,item;
    do{
      SolvedEx s1;
      cout<<"Enter 1 to push,2 to pop,3 to display,4 to exit"<<endl;
      cin>>choice;
      switch(choice)
      {
      case 4:
        break;
      case 1:
        cout<<"Enter the element to be pushed into the stack"<<endl;
        cin>>item;
        s1.push(item);
        break;
      case 2:
        cout<<s1.pop()<<endl;
        break;
      case 3:
        s1.display();
        break;
      default:
        cout<<"Enter a valid option"<<endl;
      }
      }while(choice<=3);
      return 0;
    }
