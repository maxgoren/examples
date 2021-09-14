#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Graph {
    public:
    int V;
    Graph(int n) : V(n) { }
    std::map<char, std::list<std::pair<char, int>>> adjList;
    void addEdge(char v, char u, int w);
    void showAdjList();
};

void Graph::addEdge(char v, char u, int w)
{
    adjList[v].push_back(make_pair(u, w));
    adjList[u].push_back(make_pair(v, w));
}

void Graph::showAdjList()
{
    for (auto v : adjList)
    {
        cout<<v.first<<": ";
        for (auto u : adjList[v.first])
        {
            cout<<u.first<<" ";
        }
        cout<<endl;
    }
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
    G.showAdjList();
    return 0;
}