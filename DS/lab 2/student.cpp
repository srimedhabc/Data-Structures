#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
class Student{
    char name[20],grade;
    int rollno;
public:
    int getroll()
    {
        return rollno;
    }
    void read()
    {
        cout<<"Enter the name "<<endl;
        cin>>name;
        cout<<"Enter the grade "<<endl;
        cin>>grade;
        cout<<"Enter the roll number "<<endl;
        cin>>rollno;
    }
    void display()
    {
        cout<<name<<endl;
        cout<<grade<<endl;
        cout<<rollno<<endl;
    }
    };
    void swap(Student &st1,Student &st2)
    {
     Student st;
     st=st1;
     st1=st2;
     st2=st;
    }
    void Bubble(Student st[],int n)
    {
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n-i-1;j++)
             if(st[j].getroll()>st[j+1].getroll())
                 swap(st[j],st[j+1]);
    }
    int main()
    {
        Student st[20];
        cout<<"Enter the number of students"<<endl;
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
            st[i].read();
        Bubble(st,n);
        for(i=0;i<n;i++)
            st[i].display();
        return 0;
    }
