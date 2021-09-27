#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "better-graph.h"
using namespace std;


bool buildpath(string start, string finish, string intersect, vector<string> path1, vector<string> path2)
{
    path1.pop_back();
    reverse(path2.begin(), path2.end());
    for (auto p : path2)
      path1.push_back(p);
    path1.pop_back();
    cout<<"Path length: "<<path1.size()+1<<endl;
    cout<<"Path: ";
    for (auto p : path1)
      cout<<p<<" --> ";
    cout<<finish<<endl;
    return true;
}

bool beento(vector<string> path, string check)
{
    for (auto p : path)
    {
        if (p == check)
          return true;
    }
    return false;
}

bool pathsCrossed(string start, string finish, vector<string> path1, vector<string> path2)
{
    for (auto check : path1)
    {
        for (auto against : path2) 
        {
          if (check == against)
          {
             string intersect = check;
             cout<<"Found path intersection at: "<<intersect<<"\n";
             return buildpath(start, finish, intersect, path1, path2);
          }
        }
    }
    return false;
}

bool depthLimitedDepthFirstSearch(Graph& G, string current_vertex, string target, int depth, int max_depth, vector<string>& path)
{
     int current_depth = depth;
     cout<<current_vertex<<" -> ";
     path.push_back(current_vertex);
     if (current_vertex == target)
     {
       cout<<"Found!\n";
       return true;
     }
     if (current_depth < max_depth)
     {
     for (auto next : G.adjList[current_vertex])
     {
        if (!beento(path, next.vertex))
        {
            return depthLimitedDepthFirstSearch(G, next.vertex, target, current_depth + 1, max_depth, path);
        }
     }
     }
  return false;
}

void iterativeDeepeningBidirectionalDepthFirstSearch(Graph& G, string start, string finish, int max_depth)
{
    for (int depth_limit = 1; depth_limit <= max_depth; depth_limit++)
    {
      vector<string> path1, path2;
      cout<<"Starting Traversal. Depth Limit: "<<depth_limit<<endl;
      depthLimitedDepthFirstSearch(G, start, finish, 0, depth_limit, path1);
      cout<<endl;
      depthLimitedDepthFirstSearch(G, finish, start, 0, depth_limit, path2); 
      cout<<endl;
      if (pathsCrossed(start, finish, path1, path2))
      {
        cout<<"Brilliant!\n";
        break;
      }
    }
}
int main()
{
    Graph G("Graph");
    G.addEdge("A", "B",1);
    G.addEdge("A", "D",3);
    G.addEdge("A", "E",3);
    G.addEdge("B", "C",2);
    G.addEdge("B", "D",2);
    G.addEdge("C", "E",5);
    G.addEdge("C", "F",3);
    G.addEdge("F", "G",1);
    G.showAdjList();
    iterativeDeepeningBidirectionalDepthFirstSearch(G, "A", "G", 10);
    //depthFirstSearch(G, "A", "G");
}