#include<iostream>
using namespace std;
class ftrans{
public:
    int r,c,v;
    ftrans(){
    v=0;
    r=0;
    c=0;
    }
    void read(ftrans a[],int m,int n)
    {
        int item;
        a[0].r=m;
        a[0].c=n;
        int k=1;
        cout<<"Enter item"<<endl;
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
    void ftranspose(ftrans s[],ftrans b[])
    {
        b[0].r=s[0].c;
        b[0].c=s[0].r;
        b[0].v=s[0].v;
        int i,j,k=0;
        int rterms[10],start_pos[10];
        if(s[0].v>0)
        {
            for(i=0;i<s[0].v;i++)
                rterms[i]=0;
            for(i=1;i<s[0].v;i++)
                rterms[s[i].c]++;
            start_pos[0]=1;
            for(i=1;i<s[0].c;i++)
                start_pos[i]=start_pos[i-1]+rterms[i-1];
            for(i=1;i<=s[0].v;i++)
            {
                j=start_pos[s[i].c]++;
                b[j].r=s[i].c;
                b[j].c=s[i].r;
                b[j].v=s[i].v;
            }
        }
        cout<<"f transpose matrix is"<<ends;
        for(i=0;i<s[0].v+1;i++)
            cout<<"\n"<<b[i].r<<" "<<b[i].c<<" "<<b[i].v<<endl;
    }
};
int main()
{
    int m,n,i;
    ftrans a[100],ob,b[100];
    cout<<"Enter number of rows and columns"<<endl;
    cin>>m>>n;
    ob.read(a,m,n);
    for(i=0;i<a[0].v;i++)
        cout<<"\n"<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
    ob.ftranspose(a,b);
    return 0;
}
