#include <iostream>
using namespace std;

class node
{  public:
    int  data;
   node * link;
};
node * top=NULL;
void push(int val)
{   
    node * ptr=new node();
    ptr->data=val;
    ptr->link=top;
    top=ptr;
}
void pop()
{ if (top==NULL)
 {
    cout<<"the stack is empty";
 }
 else
 {
    node * temp=top;
    top=top->link;
    free(temp);
 }
}
void display()
{
    node * ptr=top;

    while(ptr->link!=NULL)
    {
        cout<<"The sequence of stack is "<<ptr->data<<"-";
        ptr=ptr->link;
    }
   
    cout<<ptr->data<<"-"<<"NULL"<<endl;
}
int main()
{   
    push(1);
    push(2);
    display();
    pop();
    display();
}