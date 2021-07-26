#include<iostream>
#include<cstring>
#define MAXSIZE 100
using namespace std;
class AnyBase{
private:
    int top;
    int arr[30];
public:
    AnyBase(){
    top==-1;
    }
    void push(int n)
    {
        if(top==MAXSIZE-1)
            cout<<"Stack overflow"<<endl;
        else
        {
            top=top+1;
            arr[top]=n;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            //cout<<"Stack underflow"<<endl;
            return -1;
        }
        else
            return arr[top--];
    }
    int topele()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else
            return arr[top];
    }
    void display()
    {
        if(top==-1)
            cout<<"Stack is empty"<<endl;
        else{
            cout<<"Stack contents are "<<endl;
            for(int i=0;i<=top;i++)
                cout<<arr[i]<<ends;
        }
    }
};
int main()
{
    AnyBase ob;
    int a,b,d,n,choice,c=0,i;
    int str[20];
    do{
    cout<<"Enter a decimal number"<<endl;
    cin>>d;
    cout<<"What base do you want to convert the number into"<<endl;
    cin>>n;
    while(d>0){
        a=d%n;
        d=d/n;
        ob.push(a);
        c++;
    }
    cout<<"The converted number is "<<endl;
    for(i=0;i<c;i++)
    {
        b=ob.pop();
        if(b==-1)
            break;
        if(b>9){
            char c=(55+b);
            cout<<c;
        }
        else
            cout<<b;
    }
    cout<<"\nEnter 1 to continue and 0 to exit"<<endl;
    cin>>choice;
    }while(choice!=0);
    return 0;
}


