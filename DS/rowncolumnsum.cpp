#include<iostream>
using namespace std;
int main()
{
    int A[20][20],i,j,a,b,RS,CS;
    cout<<"enter the number of rows and columns in the matrix"<<endl;
    cin>>a>>b;
    cout<<"enter the elements of the matrix"<<endl;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            cin>>A[i][j];
        }
    }

    for(i=0;i<a;i++)
    {
        RS=0;
        for(j=0;j<b;j++)
        {
            RS+=A[i][j];
        }
        cout<<"The sum of the "<<i<<" row is "<<RS<<endl;
    }

    for(i=0;i<b;i++)
    {
        CS=0;
        for(j=0;j<a;j++)
        {
            CS+=A[j][i];
        }
        cout<<"The sum of the "<<i<<" column is "<<CS<<endl;
    }

    return 0;
}

