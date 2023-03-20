#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next=NULL;
   node(int val)
   {
      data=val;
      next=NULL;
   }
};
void push(node * &head,int val)
{   
   node *n=new node(val);
   node *temp=head;
   if (head==NULL)
   {
     head=n;
     return;
   }
   while (temp->next !=NULL)
   {
        temp=temp->next;
   }
   temp->next=n;
   cout << temp->data;
}
void pop(node * head)
{  node * temp=head;
   while(temp !=NULL)
   { 
    cout << temp->data <<"->";
    temp=temp ->next;
   }
   cout<<"NULL"<<endl;
}
int main()
{
    node *head=NULL;
    push(head,2);
    push(head,4);
    push(head,5);
    // pop(head);
}