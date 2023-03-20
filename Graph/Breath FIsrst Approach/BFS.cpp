#include <bits/stdc++.h>
using namespace std;

void prepare_adj_list(unordered_map<int,list<int>> & adjlist,vector<pair<int,int>> &edges)
{   int u,v;
    for (int i=0 ;i<edges.size();i++)
    {
        u=edges[i].first;
        v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        
    }
}
void printadj (unordered_map<int,list<int>> &adjlist)
{
    for (auto i:adjlist)
     {
        cout<<i.first<<"->";
        for(auto j:i.second)
        {
          cout<<j<<",";
        }
     }
}
void bfs(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans,int node)
{
    queue <int> q;
    q.push(node);
    visited[node]=1; 
    while(!q.empty())
    {  int frontnode=q.front();
       q.pop();
       ans.push_back(frontnode);
       for (auto i:adjlist[frontnode])
       {
         q.push(i);
         visited[i]=1;
       }

    }
}
vector<int> BFS (int vertex,vector<pair<int,int>> edges)
{
    unordered_map<int,list<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepare_adj_list(adjlist,edges);
    printadj(adjlist);
    for (int i=0;i<vertex;i++)
        {
            if(!visited[i])
            {
                bfs(adjlist,visited,ans,i);

            }
        }
    return ans;
}