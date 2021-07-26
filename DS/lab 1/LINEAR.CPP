#include<iostream>
using namespace std;
int main()
{

int A[20],i,n,a,found=0;
cout<<"enter the number of elements in the array"<<endl;
cin>>n;
cout<<"enter the elements of the array"<<endl;
for(i=0;i<n;i++)
cin>>A[i];
cout<<"enter the element to be searched"<<endl;
cin>>a;
for(i=0;i<n;i++)
{
if(a==A[i])
cout<<"found at location "<<i<<endl;
found=1;
if(!found)
cout<<"not found";
}

return 0;
}
