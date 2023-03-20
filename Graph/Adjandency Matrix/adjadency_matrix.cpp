#include <bits/stdc++.h>
using namespace std;

class graph 
{   int v;
    int ** adj;
    public:
      graph (int v)
      {
        this -> v=v;
        adj=new int * [v];
        for (int r=0;r < v;r++)
         {
            adj[r]=new int[v];
            for (int c=0;c <v ;c++)
             {
                adj[r][c]=0;
             }
         }
       }
       void add_edge(int s,int e)
       {
        adj[s][e]=1;
        adj[e][s]=1;
       }
       void display()
       {
        for (int i=0;i<v;i++)
        {   cout<<i<<"=   ";
            for (int j=0;j<v;j++)
            {
                cout<<adj[i][j]<<"   ";

            }
            cout<<endl;
        }
       }

};
int main()
{
    graph g(4);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,2);
    g.add_edge(0,3);
    g.display();
}