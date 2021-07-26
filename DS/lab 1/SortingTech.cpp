#include<iostream>
using namespace std;
int i,j,n,a,A[20],key,m,temp=0;
void Bubblesort(int a)
{
  for(i=0;i<a;i++)
  {
      for(j=0;j<i;j++)
      {
          if(A[i]<A[j])
          {
              temp=A[i];
              A[i]=A[j];
              A[j]=temp;
          }
      }
  }
  for(i=0;i<a;i++)
    cout<<A[i]<<ends;
}
void Selectionsort(int a)
{
    for(i=0;i<a-1;i++)
    {
        m=i;
    for(j=i+1;j<a;j++)
    {
        if(A[j]<A[m])
        m=j;
    }
    temp=A[m];
    A[m]=A[i];
    A[i]=temp;
    }
    for(i=0;i<a;i++)
        cout<<A[i]<<ends;
}
void Insertionsort(int a)
{
for(i=1;i<a;i++)
{
key=A[i];
for(j=i-1;j>=0&&key<A[j];j--)
{
A[j+1]=A[j];
}
A[j+1]=key;
}
for(i=0;i<a;i++)
cout<<A[i]<<ends;
}
int main()
{
    int c;
  cout<<"Enter the number of elements in the array"<<endl;
  cin>>n;
  cout<<"Enter the elements of the array"<<endl;
  for(i=0;i<n;i++)
    cin>>A[i];
  cout<<"Enter 1 for bubble sort,2 for selection sort,3 for insertion sort"<<endl;
  cin>>c;
  switch(c)
  {
  case 1:
    Bubblesort(n);
    break;
  case 2:
    Selectionsort(n);
    break;
  case 3:
    Insertionsort(n);
    break;
  default:
    cout<<"Enter a valid option"<<endl;
    break;
  }
}
