#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int MAX=100;
class STACK
{
int TOP;
int stack[MAX];
public:
STACK()
{
TOP=-1;
}
void push(int);
int pop();
int returntop()
{
return TOP;
}
};
void STACK::push(int opernd)
{
stack[++TOP]=opernd;
}
int STACK::pop()
{
if(TOP==-1)
return -1;
else
return stack[TOP--];
}
void postfix_evaluation()
{
STACK S;
int oper,op1,op2,c,cop,j;
char symbol,postfix[50];
cout<<"ENTER THE POSTFIX EXPRESSION:";
gets(postfix);
for(int i=0;i<strlen(postfix);i++)
{
symbol=postfix[i];
if( symbol >= 48 && symbol<= 57)
{
oper=symbol-'0';
S.push(oper);
}
else if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol == '%')
{
op2=S.pop();
op1=S.pop();
switch(symbol)
{
case '%': c=op1%op2;
S.push(c);
break;
case '/': c=op1/op2;
S.push(c);
break;
case '*': c=op1*op2;
S.push(c);
break;
case '+': c=op1+op2;
S.push(c);
break;
case '-': c=op1-op2;
S.push(c);
break;
}
}
else
{
int val;
cout<<"Enter the value for "<<symbol<<endl;
cin>>val;
S.push(val);
}
}
cout<<"the result is = "<<S.pop();
}
int main()
{
postfix_evaluation();
return 0;
}
