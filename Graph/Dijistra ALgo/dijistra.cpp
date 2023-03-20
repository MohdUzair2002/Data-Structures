#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
 void dijistra(vector<vector<int>> &vec,int vertices,int edges,int source)
 { 
   unordered_map <int,list<pair<int,int>>> adjlist;
   for(int i=0;i<edges;i++)
   {int u=vec[i][0];
   int v=vec[i][1];
   int w=vec[i][2];
   
   adjlist[u].push_back((make_pair(v,w)));
   
   adjlist[v].push_back((make_pair(u,w)));   
   }
   vector<int> dist(vertices);
   for (int i=0;i<vertices;i++)
   {
     dist[i]=INT_MAX;
   }
   set <pair<int,int>> st;
   dist[source]=0;
   st.insert(make_pair(0,source));
   while(!st.empty())
   {
    auto top=*(st.begin());
    int node_distance=top.first;
    int top_node=top.second;
    st.erase(st.begin());
    for (auto neighbour:adjlist[top_node])
    {  
    if(node_distance +neighbour.second <dist[neighbour.first])
    {
         auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
         
            if (record!=(st.end()))
            {
                st.erase(record);
            }
         dist[neighbour.first]=node_distance +neighbour.second;
         st.insert(make_pair(dist[neighbour.first],neighbour.first));
    }
    }
    
   }
  for (int i=0;i < vertices;i++)
  {
    cout<<dist[i]<<" "<<endl;
  }
 }
   
};


int main()
{
  graph g;
  int n,m,source;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the number of edges";
  cin>>m;
  cout <<"Enter the nodes";
  vector <vector<int>> data;
  for (int i=0 ;i<m;i++)
  { int u,v,w;
    cin>>u>>v>>w;  
    vector <int> v1;
    v1.push_back(u);
    v1.push_back(v);
    v1.push_back(w);
    data.push_back(v1);
    //undirected graph
  }
  cout <<"Enter the source";
  cin>>source;
  g.dijistra(data,n,m,source);
//   g.print_adj_list();
}