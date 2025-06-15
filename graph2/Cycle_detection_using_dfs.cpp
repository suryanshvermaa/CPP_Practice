#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
    vector<list<int>> graph;
    Graph(int n){
        graph.resize(n);
    }
    void add_edge(int src,int dist,bool bidir){
        graph[src].push_back(dist);
        if(bidir) graph[dist].push_back(src);
    }
};
Graph graph(10);
bool isCycle(int curr,int par,unordered_set<int> &vis){
    for(auto neighbour:graph.graph[curr]){
        if(neighbour!=par&&vis.count(neighbour)) return true;
        else{
            vis.count(neighbour);
            bool ans=isCycle(neighbour,curr,vis);
            if(ans) return true;
        }
    }
    return false;
}
int main(){
    graph.add_edge(1,0,true);
    graph.add_edge(0,2,true);
    graph.add_edge(0,3,true);
    graph.add_edge(3,4,true);
    graph.add_edge(4,5,true);
    graph.add_edge(5,6,true);
    graph.add_edge(6,3,true);
    graph.add_edge(6,7,true);
    graph.add_edge(7,8,true);
    graph.add_edge(7,9,true);
    unordered_set<int> vis;
    cout<<isCycle(0,-1,vis);
    return 0;
}