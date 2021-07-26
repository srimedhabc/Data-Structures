#include<iostream>
#include<cstring>
using namespace std;
class Paranthesis{
private:
    int top;
    int arr[30];
public:
    Paranthesis(){
    top=-1;
    }
    bool isFull(){
    if(top==29)
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
     void push(int n)
    {
        if(isFull()){
            cout<<"Stack overflow"<<endl;
        }
     else
     {
         top+=1;
         arr[top]=n;
     }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else
            return arr[top--];
    }
    void display()
    {
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
        else
            cout<<"Elements in the Stack are"<<endl;
            for(int i=1;i<=top;i++)
            cout<<arr[i]<<ends;
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return 0;
        }
        else
            return arr[top];
    }
};
int main()
{
    Paranthesis s;
    char exp[30];
    int flag=0,choice;
    do
    {
    cout<<"Enter the string"<<endl;
    cin>>exp;
    int len=strlen(exp);
    for(int i=0;i<len;i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            {
            s.push(exp[i]);
            flag=1;
            }
            if(!s.isEmpty()){
                if(exp[i]=='}'){
                if(s.peek()=='{')
                    {
                        s.pop();
                        continue;
                    }
                    else
                        break;
            }
            if(exp[i]==']'){
                    if(s.peek()=='['){
                        s.pop();
                        continue;
                    }
                    else
                        break;
           }
           if(exp[i]==')')
           {
               if(s.peek()=='(')
               {
                   s.pop();
                   continue;
               }
               else
                break;
           }
        }
        else
            break;
        }
    if((s.isEmpty())&&(flag==1))
        cout<<"Balanced expression"<<endl;
    else
        cout<<"Unbalanced expression"<<endl;
        cout<<"Enter 1 to repeat the process"<<endl;
        cin>>choice;
   }while(choice==1);
    return 0;
}
