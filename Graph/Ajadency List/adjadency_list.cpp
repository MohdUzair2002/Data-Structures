#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
 unordered_map <int,list<int>> adj;
 void addEdge (int u,int v,bool m) //m is direction 0 for undirected and 1 for directed
 {
   adj[u].push_back(v);
   if (m==0)
   {
    adj[v].push_back(u);
   }
 }
 void print_adj_list()
 {
  for (auto i:adj)
  {
    cout<<i.first<<"->";
    for (auto j:i.second)
    {
      cout<<j<<",";
    }
    cout<<endl;
  }
 }
};
int main()
{
  graph g;
  int n,m;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the umber of edges";
  cin>>m;
  cout <<"Enter the nodes";
  for (int i=0 ;i<m;i++)
  { int u,w;
    cin>>u>>w;  
    g.addEdge(u,w,0);//undirected graph
  }
  g.print_adj_list();
}