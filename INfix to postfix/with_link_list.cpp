#include <iostream>
using namespace std;

class stack
{
  public:
   int data;
   stack * link;
  
bool isempty();
bool isfull();
int top_element();
bool push(int x);
int pop();
};
stack * top=NULL;

bool  stack::isempty()
{
    if (top==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}
int stack::top_element()
{  
    return(top->data);
}
bool stack::push(int x)
{  stack * temp=new stack();
   temp->data=x;
   temp->link=top;
   top=temp;
  
   return true;
}
int  stack::pop()
{ 
   if (top==NULL)
{
    cout<<"stack is empty";
    return INT_MIN;
}
else{
  stack  * temp=top;
  top=top->link;
  int data_poped=temp->data;
  free(temp);
  return data_poped ;
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

string convert(string infix)
{   int i=0;
   
    string postfix="";
   while(infix[i]!='\0')
   {;
    if (infix[i]>='a' && infix[i]<='z'||infix[i]>='A' && infix[i]<='Z')
    { 
      postfix+=infix[i];
      i++;
     

    }
    else if(infix[i]=='(')
    {
        top->push(infix[i]);
        i++;
       

    }
     else if (infix[i]==')')
    { 
      while(top->top_element()!='(')
      {
        postfix+=top->pop();
      }
      top ->pop();
      i++;
    
     }
    else
    {  
        while(!top->isempty() && top ->top_element()=='(' &&(top->top_element())<=priority(infix[i]))
        {
            postfix+=top->pop();
        }
        top->push(infix[i]);
        i++;
        
    }
    
   }
   while(!top->isempty())
   {
    postfix+=top->pop();
   }
   cout<<"Postfix:-"<<" "<<postfix;
   return postfix;
   } 
   int main()
  {
    string infix = "((a+(b*c))-d)";
    // top=new stack();
    convert(infix);
    return 0;
  }