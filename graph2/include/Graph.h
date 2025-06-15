#include<vector>
#include<list>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H

class Graph{
public:
    vector<list<int>> graph;
public:
    Graph(int n);
    void add_edge(int src,int dist,bool bidir);
};
#endif