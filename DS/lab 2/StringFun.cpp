#include<iostream>
using namespace std;
class StringFun{
char str[40],*s;
public:
    void set(char str1[])
    {
    int i=0;
    s=str1;
    while(*s>='a'&&*s<='z')
    {
        str[i]=*s;
        s++;
        i++;
    }
    }
    int length()
    {
        int i,cnt=0;
        for(i=0;str[i]!='\0';i++)
            cnt++;
        return cnt;
    }
    void concat(char str1[])
	{
		int cnt=0,i;
		for(i=0;str[i]!='\0';i++)
			cnt++;
		for(i=cnt;str1[i-cnt]!='\0';i++)
			str[i] = str1[i-cnt];
		str[i] = '\0';
	}

    int compare(char str1[])
    {
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]-str1[i]==0)
                continue;
            else
                return 0;
        }
        return 1;
    }
    void insert_sub(char str1[],int pos)
    {
        char temp;
        int i,cnt=0;
        for(i=0;str1[i]!='\0';i++)
            cnt++;
            for(i=0;i<cnt;i++)
            {
                temp=str[i+pos];
                str[i+pos]=str1[i];
                str[i+pos+cnt]=temp;
            }
            str[i+pos+cnt+1]='\0';
    }
    void display()
    {
        cout<<str<<endl;
    }
   void delete_sub(int pos)
	{
		char temp;
		int i,cnt=0;
		char str1[20];
		for(i=0;str1[i]!='\0';i++)
			cnt++;
		for(i=0;i<cnt;i++)
			str[i+cnt] = str[i+cnt+pos];
		str[i+cnt+pos+1] = '\0';
	}
};
int main()
{
    StringFun st;
    st.set("abc");
    cout<<st.length()<<endl;
    cout<<st.compare("abc")<<endl;
    st.concat("def");
    st.display();
    st.insert_sub("ghi",3);
    st.display();
    st.delete_sub(3);
    st.display();
    return 0;

}
