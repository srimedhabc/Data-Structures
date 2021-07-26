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
void push(int opernd)
{
stack[++TOP]=opernd;
}
int pop()
{
int a;
if(TOP==-1)
{
return -1;
}
else
{
return stack[TOP--];
}
}
int returntop()
{
return TOP;
}
};
class EVALUATION
{
char prefix[20];
char symbol;
public:
void prefix_evaluation()
{
STACK S;
int oper,a[2],c,cop,j;
int len;
char symbol,prefix[50];
cout<<"ENTER THE PREFIX EXPRESSION:";
gets(prefix);
len=strlen(prefix);
for(int i=len-1;i>=0;i--)
{
symbol=prefix[i];
if( symbol >= 48 && symbol<= 57)
S.push(symbol-'0');
else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='%'||symbol=='/')
{
for(j=0;j<2;j++)
{
a[j]=S.pop();
}
switch(symbol)
{
case '%': c=a[0]%a[1];
S.push(c);
break;
case '/': c=a[0]/a[1];
S.push(c);
break;
case '*': c=a[0]*a[1];
S.push(c);
break;
case '+': c=a[0]+a[1];
S.push(c);
break;
case '-': c=a[0]-a[1];
S.push(c);
break;
}
}
else{
    int val;
    cout<<"Enter the value of "<<symbol<<endl;
    cin>>val;
    S.push(val);
}
}
cout<<"RESULT : "<<S.pop();
}
};
int main()
{
EVALUATION E;
E.prefix_evaluation();
return 0;
}
