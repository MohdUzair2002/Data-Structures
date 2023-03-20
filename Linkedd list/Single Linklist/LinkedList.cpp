#include <iostream>
using namespace std;

class node
{
  public:
   int data;
   node * next;
   node (int val)
   {
     data=val;
     next=NULL;
   }
};
void Insert_At_Tail(node * & head,int val)
{
   node *n=new node(val);
   node *temp=head;
     if (head==NULL)
 {
   head=n;
   return;
 } 

   while (temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=n;
}
void display_linkedlist(node * head)
{    
   node * temp=head;
   while(temp !=NULL)
   {
    cout<<temp->data<<"->";
    temp=temp->next;
   }
   cout<<"NULL"<<endl;
}
void insert_at_head(node* &head,int val)
{
    node * n=new node(val);
    n ->next=head;
    head=n;
}
int main()
{
  node * head=NULL;
  Insert_At_Tail(head,1);
  Insert_At_Tail(head,2);
  Insert_At_Tail(head,3);
  display_linkedlist(head);

  insert_at_head(head,7);
  display_linkedlist(head);

}