#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "better-graph.h"
using namespace std;

void visit(string vertex)
{
     cout<<vertex<<" -> ";
}

bool buildpath(string start, string finish, string intersect, map<string, string> path1, map<string, string> path2)
{
    vector<string> finalpath;
    string front = intersect;
    finalpath.push_back(intersect);
    while (front != start)
    {
        front = path1[front];
        finalpath.push_back(front);
    }
    reverse(finalpath.begin(), finalpath.end());
    string back = intersect;
    while (back != finish)
    {
        back = path2[back];
        finalpath.push_back(back);
    }
    finalpath.pop_back();
    for (auto p : finalpath)
    {
        cout<<p<<" -> ";
    }
    cout<<finish<<" [Goal]\n";
    return true;
}

bool pathsCrossed(string start, string finish, map<string,string> path1, map<string,string> path2)
{
    for (auto check : path1)
    {
        if (path2.find(check.first) != path2.end())
        {
             string intersect = check.first;
             cout<<"Found path intersection at: "<<intersect<<"\n";
             return buildpath(start, finish, intersect, path1, path2);
        }
    }
    return false;
}

bool depthLimitedDepthFirstSearch(Graph& G, string current_vertex, string target, int depth, int max_depth, map<string, string>& camefrom)
{
     int current_depth = depth;
     visit(current_vertex);
     if (current_vertex == target)
     {
       cout<<"Found!\n";
       return true;
     }
     if (current_depth < max_depth)
     {
     for (auto next : G.adjList[current_vertex])
     {
        if (camefrom.find(next.vertex) == camefrom.end())
        {
            camefrom[next.vertex] = current_vertex;
            return depthLimitedDepthFirstSearch(G, next.vertex, target, current_depth + 1, max_depth, camefrom);
        }
     }
     }
  return false;
}

bool dfs(Graph& G, string current, string target, map<string, string> path)
{
    cout<<current<<" ";
    if (current==target)
    {
        cout<<"found!\n";
        return true;
    }
    for (auto next : G.adjList[current])
    {
        if (path.find(next.vertex) == path.end())
        {
            path[next.vertex] = current;
            return dfs(G, next.vertex, target, path);
        }
    }
    return false;
}

void depthFirstSearch(Graph& G, string start, string target)
{
    map<string, string> seen;
    dfs(G, start, target, seen);
}

void iterativeDeepeningBidirectionalDepthFirstSearch(Graph& G, string start, string finish, int max_depth)
{
    for (int depth_limit = 1; depth_limit <= max_depth; depth_limit++)
    {
      map<string, string> path1, path2;
      cout<<"Starting Traversal. Depth Limit: "<<depth_limit<<endl;
      path1[start] = start;
      path2[finish] = finish;
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