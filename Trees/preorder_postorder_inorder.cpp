#include <iostream>
using namespace std;

class Node
{
    public:
     int data;
     Node * left;
     Node *right;
    Node (int  val)
    {
        data=val;
        left=NULL,right=nullptr;
        // right=NULL;
    }
};
void preorder(Node * root)
{ if (root==NULL)
   {  return;}
  cout <<root ->data<<" ";
  preorder(root->left);
  preorder(root ->right);
}
void inorder(Node * root)
{ if (root==NULL)
   {  return;}
  inorder(root->left);
  cout <<root ->data<<" ";
  inorder(root ->right);
}
void postorder(Node * root)
{ if (root==NULL)
   {  return;}
  postorder(root->left);
  postorder(root ->right);
  cout <<root ->data<<" ";

}
int main()
{ //  for example tree is:
//                          10
//                         /   \
//                        20     60
//                       /  \    /  \
//                      40   50  70  80

    Node *root=new Node(10); 
    root->left=new Node(20);
    root ->right=new Node(60);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(70);
    root->right->right=new Node (80);
    cout<<" Preorder=" ;
    preorder(root);
    cout<<endl;
    cout<<" Inorder=" ;
    inorder(root);
    cout<<endl;
    cout<<" Postorder=";
    postorder(root);
    cout<<endl;
    return 0;
}