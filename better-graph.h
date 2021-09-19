#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
    public:
    typedef struct _edge {
        string vertex;
        int weight;
        _edge(string v, int w) : vertex(v), weight(w) { }
    } edge;
    string graphName;
    list<string> verts;
    map<string, list<edge> > adjList;
    void addEdge(string v, string u, int w);
    void showAdjList();
    bool findVert(string v);
    Graph(string N) : graphName(N) { }
    };

    bool Graph::findVert(string v)
    {
        for (auto vert : verts)
        {
            if (vert == v)
              return true;
        }
        return false;
    }

    void Graph::addEdge(string v, string u, int w)
    {
        if (!findVert(v))
            verts.push_back(v);
        if (!findVert(u))
            verts.push_back(u);
        adjList[v].push_back(edge(u, w));
        adjList[u].push_back(edge(v, w));
    }

    void Graph::showAdjList()
    {
        cout<<graphName<<endl;
        verts.sort();
        for (auto vert : verts)
        {
            cout<<vert<<": ";
            for (auto adj : adjList[vert])
            {
                cout<<adj.vertex<<", ";
            }
            cout<<"\b\b\n";
        }
    }