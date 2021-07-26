#include<iostream>
using namespace std;
int main()
{
int A[10][10],B[10][10],C[10][10],i,j,a,b,c,d,x,y;
cout<<"Enter the number of rows and columns of the matrices"<<endl;
cin>>a>>b>>c>>d;
if(a!=c||b!=d)
    cout<<"Matrix addition not possible"<<endl;
else
{
cout<<"Enter the elements of matrix A"<<endl;
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
cin>>A[i][j];
}
}
cout<<"Enter the elements of matrix B"<<endl;
for(i=0;i<c;i++)
{
for(j=0;j<d;j++)
{
cin>>B[i][j];
}
}
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
C[i][j]=A[i][j]+B[i][j];
}
}
cout<<"The sum of the matrices A and B is"<<endl;
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
cout<<C[i][j]<<ends;
}
cout<<endl;
}
}
return 0;
}
