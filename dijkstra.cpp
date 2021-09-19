#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "better-graph.h"
#include "priority_queue.h"
using namespace std;

void showPath(std::map<string, string> camefrom, std::map<string, int> dist, string v, string u)
{
    list<string> path;
    int pathdist = 0;;
    string crawl = u;
    path.push_back(crawl + "(" + to_string(dist[crawl]) + " hours)");
    while (crawl != v)
    {
        crawl = camefrom[crawl];
        path.push_back(crawl + "(" + to_string(dist[crawl]) + " hours)");
    }
    reverse(path.begin(), path.end());
    cout<<"Travel Time: "<<dist[u]<<" hours."<<endl;
    cout<<"Path: \n";
    for (auto p : path)
        cout<<p<<endl;
    cout<<endl;
}


void dijkstraShortestPath(Graph& G, string v, string u)
{
    bool found = false;
    map<string, int> dist;
    map<string, string> camefrom;
    pq<string> s;
    for (auto l : G.verts)
    {
        dist[l] = INT_MAX;
    }
    string current = v;
    s.push(current, 0);
    dist[current] = 0;
    camefrom[current] = current;
    while (!s.empty())
    {
        current = s.pop();
        cout<<"Current: "<<current<<endl;;
        if (current == u)
        {
            cout<<"Found!\n";
            found = true;
            break;
        }
        for (auto child : G.adjList[current])
        {
            if (dist[child.vertex] > dist[current] + child.weight) 
            {
                dist[child.vertex] = dist[current] + child.weight;
                s.update(child.vertex, dist[child.vertex]);
                camefrom[child.vertex] = current;
            }
        }
    }
    cout<<"Search Over.\n";
    if (found)
    {
        cout<<"A Path Exists...\n";
        showPath(camefrom, dist, v, u);
    }
}

    int main(int argc, char *argv[])
    {
        Graph G("Amtrack Passenger Rail Road");
        G.addEdge("New York", "Philidelphia", 2);
        G.addEdge("New York", "Boston", 2);
        G.addEdge("New York", "Washington D.C.", 4);
        G.addEdge("Philidelphia", "Washington D.C.", 2);
        G.addEdge("Washington D.C.", "Chicago", 18);
        G.addEdge("Washington D.C.", "Atlanta", 8);
        G.addEdge("Chicago", "Atlanta", 15);
        G.addEdge("Chicago", "Denver", 13);
        G.addEdge("Chicago", "New Orleans", 16);
        G.addEdge("New Orleans", "Houston", 11);
        G.addEdge("Denver", "Los Angeles", 20);
        G.addEdge("Houston", "Los Angeles", 22);
        G.addEdge("Los Angeles", "San Francisco", 8);
        G.addEdge("San Francisco", "Denver", 19);
        cout<<"\nDijkstras Algorithm: ";
        dijkstraShortestPath(G, "New York", "New Orleans");
        return 0;
    }