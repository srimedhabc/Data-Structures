#include<iostream>
using namespace std;
class ntrans{
public:
int r,c,v;
ntrans()
{
    r=0;
    v=0;
    c=0;
}
void read(ntrans a[],int m,int n)
{
    int item;
    a[0].r=m;
    a[0].c=n;
    int k=1;
    cout<<"enter items"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>item;
            if(item==0)
                continue;
            a[k].r=i;
            a[k].c=j;
            a[k].v=item;
            k++;
        }
    }
    a[0].v=k-1;
}
void ntranspose(ntrans a[],ntrans b[])
{
    int i,n,j,currentb;
    n=a[0].v;
    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=n;
    if(n>0)
    {
        currentb=1;
        for(i=0;i<a[0].c;i++)
        {
            for(j=1;j<=n;j++)
                if(a[j].c==i)
            {
                b[currentb].r=a[j].c;
                b[currentb].c=a[j].r;
                b[currentb].v=a[j].v;
                currentb++;
            }
        }
    }
    cout<<"Transpose matrix is\n";
    for(i=0;i<a[0].v+1;i++)
        cout<<"\n"<<b[i].r<<" "<<b[i].c<<" "<<b[i].v<<endl;
}
};
int main()
{
    int m,n,i;
    ntrans a[100],ob,b[100];
    cout<<"Enter dimensions"<<endl;
    cin>>m>>n;
    ob.read(a,m,n);
    for(i=0;i<a[0].v+1;i++)
        cout<<"\n"<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
    ob.ntranspose(a,b);
    return 0;
}
