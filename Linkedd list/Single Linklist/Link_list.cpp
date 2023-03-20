#include <iostream>
using namespace std;

class node {
public:
   int data;
   node * link;
};
node * head=NULL;
void insert_at_head(int val)
{
   node *ptr=new node();
   ptr->data=val;
   ptr->link=head;
   head=ptr;

}
void insert_at_tail(int val)
{ 
  node *ptr=new node();
  ptr->data=val;
  ptr->link=NULL;
  if (head==NULL)
  {
    head=ptr;
    return;
  }
  else
  { 
    node * temp=head;
    while(temp->link!=NULL)
    {   
        temp=temp->link;
    }
    
    temp->link=ptr;
    
  }
}
void delete_from_start()
{
    node *ptr=new node();
    ptr=head;
    head=head->link;
    free(ptr);
}
void delete_from_end()
{
    node *ptr;
    node *temp=head;
    if (head==NULL)
    {
        cout<<"The link list is empty";
    }
    else
    if (head->link==NULL)
    { ptr=head;
      head=NULL;
      free (ptr);
    }
    else{
      temp=head;
    while (temp->link!=NULL)
    {  ptr=temp;
       temp=temp->link;
    }
    free(temp); 

    ptr->link=NULL;
    }
}
void display()
{
    node* temp=head;
    while(temp!=NULL )
    {
        cout <<temp->data<<"->";
        temp=temp->link;
    }
   
    cout<<"NULL"<<endl;
}
int main()
{ 
  insert_at_head(2);
  insert_at_head(3);
  insert_at_tail(5);
  display(); 
  delete_from_start();
  display();

  delete_from_end();
  display();
}