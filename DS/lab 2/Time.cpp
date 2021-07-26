#include<iostream>
using namespace std;
class Time{
public:
    int hour,minute,sec;
    Time()
    {
        hour=0;
        minute=0;
        sec=0;
    }
    void read()
    {
        cout<<"Enter time in hours\n";
        cin>>hour;
        cout<<"Enter time in minutes\n";
        cin>>minute;
        cout<<"Enter time in seconds\n";
        cin>>sec;
    }
    void add(Time t1,Time t2)
    {
        sec=t1.sec+t2.sec;
        if(sec>=60)
        {
            sec=sec%60;
            minute=minute+1;
        }
        minute=t1.minute+t2.minute;
        if(minute>=60)
        {
            minute=minute%60;
            hour=hour+1;
        }
        hour=t1.hour+t2.hour;
        cout<<"\nafter addition :\n";
        display();
    }
    void difference(Time t1,Time t2)
    {
        if(t2.hour>t1.hour)
        {
            cout<<"invalid input as t2 is greater than t1";
        }
        else
        {
        if(t2.sec>t1.sec)
        {
            t1.minute=t1.minute-1;
            t2.sec=t1.sec+60;
        }
        sec=t1.sec-t2.sec;
        if(t2.minute>t1.minute)
        {
            t1.hour=t1.hour-1;
            t2.minute=t1.minute+60;
        }
        minute=t1.minute-t2.minute;
        hour=t1.hour-t2.hour;
        cout<<"\nDifference\n";
        display();
        }
    }
    void display()
    {
        cout<<"Time in hours:\n"<<hour<<endl;
        cout<<"Time in minutes:\n"<<minute<<endl;
        cout<<"Time in seconds:\n"<<sec<<endl;
    }
};
    int main()
    {
        Time t1,t2,t;
        cout<<"Enter the times t1 and t2 "<<endl;
        t1.read();
        t2.read();
        t.add(t1,t2);
        t.difference(t1,t2);
        return 0;
    }
