#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
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

void breadthFirstSearch(Graph& G, char start, char fin)
{
    bool success = false;
    char current = start;
    char child, next;
    std::map<char, bool> seen;          //which vertexes have been visited
    std::map<char, char> camefrom;      //for rebuilding bath
    std::vector<int> prev(G.V, 0);      //for keeping track of path;
    std::queue<char> searchqueue;       //search queue for BFS = FIFO
    searchqueue.push(current);          //push initial vertex
    seen[current] = true;               //mark as visited.
    while (!searchqueue.empty())
    {
        current = searchqueue.front(); //get the first item on the queue
        searchqueue.pop();
        if (current == fin)             //is this our search target?
        {
            success = true;             //hooray
            break;                      //we can stop looking
        }
        for (auto u : G.adjList[current])   //for every adjacent vertex of current
        {
            child = u.first;
            if (seen[child] == false)       //if we havent yet visited this vertex
            {
                searchqueue.push(child);   //add it to the queue
                seen[child] = true;        //no need to see it twice.
                camefrom[child] = current;
            }
        }
    }
    if (success)
    {
        cout<<"\nA path from "<<start<<" to "<<fin<<" was found.\n";
        next = fin;
        std::vector<char> path;
        while (next != start)
        {
            path.push_back(next);
            next = camefrom[next];
        }
        reverse(path.begin(), path.end());
        cout<<"Path Length: "<<path.size()+1;
        cout<<"\nPath: "<<start;
        for (auto n : path)
        {
            cout<<" -> "<<n;
        }
        cout<<endl;
    } else {
        cout<<"\nNo such path Exists. ("<<start<<" -> "<<fin<<")\n";
    }
}

int main()
{
    Graph G(6);
    G.addEdge('A', 'B', 6);
    G.addEdge('A', 'C', 7);
    G.addEdge('B', 'C', 5);
    G.addEdge('C', 'E', 5);
    G.addEdge('D', 'E', 4);
    G.addEdge('D', 'F', 1);
    G.addEdge('E', 'F', 2);
    G.showAdjList();
    breadthFirstSearch(G, 'A', 'D');
    return 0;
}