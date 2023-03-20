#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
bool vis[N];
vector<int> g[N];

class graph
{
    int v;
    list <int> * adj;
    public:
    graph(int v)
    {
        this ->v=v;
        adj=new list <int> [v];
    }
    void add_edge(int s,int e)
    {
        adj[s].push_back(e);
        adj[e].push_back(s);   
    }
    void dfs (int vertex)
    {  
      vis[vertex]=true;
      cout<<vertex<<endl;
      for (int child:adj[vertex])
      {  cout<<"par  " <<vertex<<"  child  "<<child<<endl;
         if (vis[child]) continue;;

         dfs(child);
      }
    }
};
int main()
{
   graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(2, 3); 
  g.dfs(0);
}