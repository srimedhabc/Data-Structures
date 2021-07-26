#include<iostream>
#include<cstring>
using namespace std;
#define SS 15
class PalinStacks{
private:
    int top;
    int s[50];
public:
    PalinStacks(){
    top=-1;
    }
    bool isFull(){
    if(top==SS)
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
         s[top]=n;
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
            return s[top--];
    }
    void display()
    {
        if(isEmpty())
            cout<<"Stack is empty"<<endl;
        else
            cout<<"Elements in the Stack are"<<endl;
            for(int i=1;i<=top;i++)
            cout<<s[i]<<ends;
    }
};
int main()
{
    int len,choice;
    char str[20];
    PalinStacks s1;
    do
    {
    cout<<"Enter the string "<<endl;
    cin>>str;
    len=strlen(str);
    for(int i=0;i<len;i++)
        s1.push(str[i]);
    for(int j=0;j<len;j++)
    {
        if(s1.pop()!=str[j])
        {
            cout<<"It's not a palindrome"<<endl;
            break;
        }
        if(j==len-1)
            cout<<"It is a palindrome"<<endl;
    }
    cout<<"Enter 1 to continue "<<endl;
    cin>>choice;
    }while(choice==1);
    return 0;
}

