#include"../include/Graph.h"

Graph::Graph(int n){
    graph.resize(n);
}
void Graph::add_edge(int src,int dist,bool bidir){
    graph[src].push_back(dist);
    if(bidir) graph[dist].push_back(src);
}
