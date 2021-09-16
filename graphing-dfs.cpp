#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Graph {
    public:
    int V;
    Graph(int n) : V(n+1) { adjMatrix.resize(V, std::vector<int>(V, 0)); }
    std::vector<std::vector<int>> adjMatrix;
    void addEdge(char v, char u, int w);
    void showAdjMatrix();
};

void Graph::addEdge(char v, char u, int w)
{
    int a = v - 'A' + 1;
    int b = u - 'A' +  1;
    adjMatrix[a][b] = w;
    adjMatrix[b][a] = w;
}

void Graph::showAdjMatrix()
{
    cout<<"\n  ";
    for (int i = 1; i < V; i++)
      cout<<char(i+'A'-1)<<" ";
    cout<<endl;
    for (int i = 1; i < V; i++)
    {
      cout<<char(i+'A'-1)<<" ";
      for (auto u = 1; u < adjMatrix[i].size(); u++)
      {
         cout<<adjMatrix[i][u]<<" ";
      }
      cout<<endl;
    }
}

void depthFirstSearch(Graph& g, char v, char u, std::map<char, bool>& seen)
{
   cout<<"Visiting: "<<v<<"\n";
   seen[v] = true;
   if (v == u)
   {
       cout<<u<<" Found!\n";
       return;
   }
   for (auto c = 1; c < g.V; c++) 
   {
       char child = (char)(c+'A'-1);
       if (seen[child] == false && g.adjMatrix[v-'A'+1][c] > 0)
       {
         depthFirstSearch(g, child, u, seen);
       }
   }   
}

void dfs(Graph& g, char v, char u)
{
   std::map<char, bool> seen;
   depthFirstSearch(g, v, u, seen);
}
int main()
{
    Graph G(6);
    G.addEdge('A', 'B', 6);
    G.addEdge('A', 'C', 7);
    G.addEdge('A', 'E', 2);
    G.addEdge('B', 'C', 5);
    G.addEdge('C', 'E', 5);
    G.addEdge('D', 'E', 4);
    G.addEdge('D', 'F', 1);
    G.addEdge('E', 'F', 2);
    G.addEdge('F', 'A', 3);
    G.showAdjMatrix();
    dfs(G, 'A', 'D');
    return 0;
}