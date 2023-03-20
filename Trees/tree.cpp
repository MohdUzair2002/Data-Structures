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
        left,right=nullptr;
    }
};
int main()
{
    // for example if we want to store
    //           10
    //          /  \
    //         20   30
    Node *root=new Node(10); 
    root->left=new Node(20);
    root ->right=new Node(30);
    return 0;
}