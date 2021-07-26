#include<iostream>
using namespace std;
enum Boolean{FALSE,TRUE};
int icp[]={20,19,12,12,13,13,13};
int isp[]={0,19,12,12,13,13,13};
enum precedence{lparen,rparen,p,m,times,divide,mod,operand};
class Stack
{ int top;
char a[10];
int maxsize;
public: Stack()
{ maxsize=10;top=-1;}
Boolean Isfull()
{

if(top==maxsize-1)
return TRUE;
return FALSE;
}
Boolean Isempty()
{ if(top==-1)
return TRUE;
return FALSE;
}
void push(char x);
char pop();
void display();
char topele();
};
void Stack::push(char x)
{ if(Isfull())

cout<<"Stack is full \n";
else
a[++top]=x;

}
char Stack::topele()
{ return(a[top]);
}
char Stack::pop()
{
if(Isempty())
return(-9999);
else
return(a[top--]);

}
void Stack::display()
{ if(Isempty())

cout<<"Stack is empty";
else
for(int i=top;i>-1;i--)
cout<<a[i];

}
precedence get_token(char c)
{
switch(c)
{
case '(':return lparen;
case ')':return rparen;
case '+':return p;
case '-':return m;
case '*':return times;
case '/':return divide;

case '%':return mod;
default:return operand;
}
}
void postfix(char infix[])
{
precedence temp;
int i=0;
Stack s;
while(infix[i]!='\0')
{
temp=get_token(infix[i]);
if(temp==operand)
{cout<<infix[i];}
else if(temp==rparen)
{
while(get_token(s.topele())!=lparen)
cout<<s.pop();
char c=s.pop();
}
else
{
if(s.Isempty()==TRUE)
s.push(infix[i]);
else
{
while(icp[temp]<=isp[get_token(s.topele())]&&s.Isempty()==FALSE)
cout<<s.pop();
s.push(infix[i]);
}
}
i++;
}
s.display();
}
int main()
{
char infix[10];
cout<<"enter infix expression\n";
cin>>infix;
cout<<"Respective postfix expression is\n";
postfix(infix);
return 0;
}
