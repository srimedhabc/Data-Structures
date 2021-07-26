#include<iostream>
using namespace std;
int main()
{
int A[20][20],B[20][20],C[20][20],i,j,a,b,m,n;
cout<<"enter the number of rows and columns in A and B respectively"<<endl;
cin>>a>>b>>m>>n;
if(a!=m||b!=n)
    cout<<"Comparision not possible"<<endl;
else
{
cout<<"enter the elements of A"<<endl;
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
cin>>A[i][j];
}
}
cout<<"enter the elements of B"<<endl;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cin>>B[i][j];
}
}
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
if(A[i][j]>B[i][j])
C[i][j]=A[i][j];
else
C[i][j]=B[i][j];
}
}
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
