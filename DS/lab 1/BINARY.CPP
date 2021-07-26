#include<iostream>
using namespace std;
int main()
{
int A[20],i,n,m,low,high,mid,flag=0;
cout<<"enter the number of elements in the array"<<endl;
cin>>n;
cout<<"enter the elements of the sorted array"<<endl;
for(i=0;i<n;i++)
cin>>A[i];
cout<<"enter the element to be searched"<<endl;
cin>>m;
low=0;
high=n-1;
mid=(high-low)/2+low;
while(low<=high)
{
if(m<A[mid])
high=mid-1;
else if(m>A[mid])
low=mid+1;
else if(m==A[mid])
{
flag=1;
break;
}
mid=(high-low)/2+low;
}
if(flag==0)
cout<<"not found";
else
cout<<"element found ";
return 0;
}
