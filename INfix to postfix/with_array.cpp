#include <iostream>
using namespace std;

class stack
{
     int top;
     int max;
     int * a;
public:
  stack(int size)
  { top=-1;
    max=size;
    a=new int[size];
  }
bool isempty();
bool isfull();
int top_element();
bool push(int x);
int  pop();
};
bool stack::isempty()
{
    return(top<0);
}
bool stack::isfull()
{
    return(top==max-1);
}
int stack::top_element()
{
  return (a[top]);
}
bool stack::push(int x)
{
    if (top>=(max-1))
    {
        cout<<"Stack Overflow";
        return false;
    }
    else
    {
      top++;
      a[top]=x;
      return true;
    }
}
int stack::pop()
{
    if (top<0)
    {
        cout<<"Stack Underflow";
        return INT_MIN;
    }
    else
    {
        int x=(a[top]);
        top --;
         return x;

    }
    
}

int priority (char alpha)
{
    if (alpha=='+' || alpha=='-')
    {
        return 1;
    }
  if (alpha=='*' || alpha=='/')
    {
        return 2;
    }
      if (alpha=='^')
    {
        return 3;
    }
  return 0;
}

string convert (string infix)
{
    int i=0;
    string postfix="";
    stack s(20);
    while (infix[i]!='\0')
    {
        if (infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z')
        {
            postfix+=infix[i];
            i++;
        }
        
       else if(infix[i]=='(')
       {
         s.push(infix[i]);
         i++;
       }
       
       else if(infix[i]==')')
       {
        while(s.top_element()!='(')
        {
          postfix+=s.pop();
        }
        s.pop();
        i++;
       }
     else
    { while(!s.isempty() && priority(infix[i]) <= priority(s.top_element()))
     {
       postfix+=s.pop();
     }
    s.push(infix[i]);
    i++;

    }
   
    }
    while(!s.isempty())
    {
        postfix+=s.pop();
        i++;
    }
    
    
    cout<<"Postfix:-"<<" "<<postfix;
    return postfix;
  
}
int main()
{
    string infix = "((a+(b*c))-d)";
    string postfix; 
    postfix = convert(infix);
    return 0;
}
