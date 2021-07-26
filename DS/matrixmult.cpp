#include<iostream>
using namespace std;
int main()
{
    int A[20][20],B[20][20],i,j,k,a,b,m,n,C[20][20];
    cout<<"enter the number of rows and columns in A and B"<<endl;
    cin>>a>>b>>m>>n;
    if(b!=m)
        cout<<"matrix multiplication is not possible"<<endl;
        else
        {
        cout<<"Enter the elements of matrix A "<<endl;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
                cin>>A[i][j];
        }
        cout<<"Enter the elements of matrix B "<<endl;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cin>>B[i][j];
        }
        cout<<"The product of the two matrices is"<<endl;
        for(i=0;i<a;i++)
        {
            for(j=0;j<n;j++)
            {
                C[i][j]=0;
                for(k=0;k<b;k++)
            {
                C[i][j]+=(A[i][k]*B[k][j]);
            }
            cout<<C[i][j]<<ends;
            }
            cout<<endl;
        }
        }
        return 0;
}
