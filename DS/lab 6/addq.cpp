#include <iostream>
#define MAX 100
using namespace std;
class Stack{
public:
    int top;
    string arr[MAX];
    Stack(){
    top=-1;}
    void push(string item)
    {
        top++;
        arr[top]=item;
    }
    string pop(){
        if(top==-1)
            return "X";
        else
           return arr[top--];
    }
    string TOP(){
    if(top==-1)
        return "X";
        else
            return arr[top];
    }
};
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
string preToPost(string pre_exp) {
  Stack s;
  int length = pre_exp.length();
  for (int i = length - 1; i >= 0; i--) {
    if (isOperator(pre_exp[i])) {
      string op1 = s.TOP();
       s.pop();
      string op2 = s.TOP();
       s.pop();
      string temp = op1 + op2 + pre_exp[i];
      s.push(temp);
    }
    else {
      s.push(string(1, pre_exp[i]));
    }
  }
  return s.TOP();
}
int main() {
    char prefix[20];
    cout<<"Enter prefix expression"<<endl;
    cin>>prefix;
  cout << "Postfix : " << preToPost(prefix);
  return 0;
}
