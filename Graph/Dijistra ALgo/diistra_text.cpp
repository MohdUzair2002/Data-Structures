#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
 void dijistra(vector<vector<variant<string,int>>> &vec,int vertices,int edges,string source)
 { 
   unordered_map <string,list<pair<string,int>>> adjlist;
   for(int i=0;i<edges;i++)
   {string u=get<string>(vec[i][0]);
    string v=get<string>(vec[i][1]);
    int w=get<int>(vec[i][2]);
    int type=get<int>(vec[i][3]);
    if(type==0)
    { adjlist[u].push_back((make_pair(v,w)));}
    else if (type==1)
    { adjlist[u].push_back((make_pair(v,w)));
      adjlist[v].push_back((make_pair(u,w)));   
    }
   }
   unordered_map <string,int> dist;
   for (auto it=adjlist.begin();it!=adjlist.end();it++)
   { string key=(it->first);
     dist[key]=INT_MAX;
   }
   set <pair<int,string>> st;
   dist[source]=0;
 
   st.insert(make_pair(0,source));
   while(!st.empty())
   {
    auto top=*(st.begin());
    int node_distance=top.first;
    cout<<endl<<node_distance<<endl;
    string top_node=top.second;
    st.erase(st.begin());
    for (auto neighbour:adjlist[top_node])
    {  cout<<endl<<neighbour.first<<endl<<neighbour.second<<endl;
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
  for (auto it=dist.begin();it != dist.end();it++)
  {
    cout<<it->first<<" "<<"="<<" "<<it->second<<endl;
  }
 }
   
};


int main()
{
  graph g;
  int n,m;
  cout<<"Enter the number of nodes";
  cin>>n;
  cout<<"Enter the number of edges";
  cin>>m;
  cout <<"Enter the nodes";
  string source;
  using element=variant<string,int>;
  vector<vector<element>> data;  
  for (int i=0 ;i<m;i++)
  { string u,v;
    int w,type;
    cin>>u>>v>>w>>type;  
    vector <element> v1;
    v1.push_back(u);
    v1.push_back(v);
    v1.push_back(w);  
    v1.push_back(type);
    data.push_back(v1);
    //undirected graph
  }
  cout <<"Enter the source";
  cin>>source;
  g.dijistra(data,n,m,source);
//   g.print_adj_list();
}