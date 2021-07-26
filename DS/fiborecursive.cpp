#include<iostream>
using namespace std;
 int fibo(int x)
{
   if(x==1||x==0)
    return x;
   else
    return fibo(x-1)+fibo(x-2);
}
int main()
{
int i=0,x,c;
cout<<"enter the number of elements in the series"<<endl;
cin>>x;
while(i<x)
{
cout<<fibo(i)<<ends;
i++;
}
return 0;
}
